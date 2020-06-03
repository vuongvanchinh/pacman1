
#include"map.h"

Map::Map( int x, int y, int MapType)
{
    //Get the offsets
    mBox.x = x;
    mBox.y = y;

    //Set the collision box
    mBox.w = Map_WIDTH;
    mBox.h = Map_HEIGHT;

    //Get the Map type
    mType = MapType;
}

void Map::render(SDL_Renderer*& des, Texture &gMapTexture, SDL_Rect gMapClips[])
{
    //If the Map is on screen
    SDL_Rect camera = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };
    if (checkCollision(camera, mBox))
    {
        //Show the Map
        gMapTexture.render(mBox.x , mBox.y , des, &gMapClips[mType]);
    }
}

int Map::getType()
{
    return mType;
}

SDL_Rect Map::getBox()
{
    return mBox;
}