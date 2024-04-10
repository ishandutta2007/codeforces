#include <iostream>

using namespace std;

bool mat[10][10];
char v[10][10];

int main()
{
    int i,j;

    for(i=1;i<=8;i++)
        for(j=1;j<=8;j++)
        {
            cin>>v[i][j];
            if(v[i][j]=='W')
                mat[i][j]=1;
            else
                mat[i][j]=0;
        }

    bool ok=true;
    for(i=1;i<=8;i++)
    {
        for(j=2;j<=8;j++)
            if(mat[i][j]^mat[i][j-1])
            {}
            else
            {
                ok=false;
                break;
            }
    }
    if(ok)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}