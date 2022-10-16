#include <iostream>

using namespace std;

int main()
{
    int clasa[8][8]={{1,2,5,6,1,2,5,6},
                     {3,4,7,8,3,4,7,8},
                     {5,6,1,2,5,6,1,2},
                     {7,8,3,4,7,8,3,4},
                     {1,2,5,6,1,2,5,6},
                     {3,4,7,8,3,4,7,8},
                     {5,6,1,2,5,6,1,2},
                     {7,8,3,4,7,8,3,4}};
    int rest[8][8]={{0,0,1,1,0,0,1,1},
                    {0,0,1,1,0,0,1,1},
                    {0,0,1,1,0,0,1,1},
                    {0,0,1,1,0,0,1,1},
                    {0,0,1,1,0,0,1,1},
                    {0,0,1,1,0,0,1,1},
                    {0,0,1,1,0,0,1,1},
                    {0,0,1,1,0,0,1,1}};
    int p,i,j,t;

    char mat[8][8];
    cin>>t;
    int hs1_x,hs1_y,hs2_x,hs2_y;
    bool ales;

    for(p=0;p<t;p++)
    {
        ales=false;
        for(i=0;i<8;i++)
            for(j=0;j<8;j++)
            {
                cin>>mat[i][j];
                if(mat[i][j]=='K')
                {
                    if(!ales)
                        ales=true,hs1_x=i,hs1_y=j;
                    else
                        hs2_x=i,hs2_y=j;
                }
            }
        if(clasa[hs1_x][hs1_y]!=clasa[hs2_x][hs2_y])
        {
            cout<<"NO\n";
            continue;
        }
        else if(rest[hs1_x][hs1_y]!=rest[hs2_x][hs2_y])
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
    }


    return 0;
}