#include <iostream>
#include <cstring>

using namespace std;

short n,m;
int k;
char v[505][505];
bool viz[505][505];

short int dx[4]={-1,1,0,0};
short dy[4]={0,0,1,-1};

void dfs(short int x,short int y)
{
    short int l,nx,ny;
    for(l=0;l<4 && k>0;l++)
    {
        nx=x+dx[l];
        ny=y+dy[l];
        if(nx>=0 && ny>=0 && nx<n && ny<m)
            if(!viz[nx][ny] && v[nx][ny]=='.')
            {
                viz[nx][ny]=1;
                dfs(nx,ny);
            }
    }
    if(k>0)
    {
        v[x][y]='X';
        k--;
    }

}

int main()
{
    short int lin,col;
    short int i,j;
    cin>>n>>m>>k;
    for(i=0;i<n;i++)
    {
        cin.get();
        cin.get(v[i],505);
    }

    bool ok=true;
    for(i=0;i<n && ok;i++)
        for(j=0;j<m;j++)
            if(v[i][j]=='.')
            {
                lin=i;
                col=j;
                ok=false;
                break;
            }

    if(!ok && k>0)
    {
        viz[lin][col]=1;
        dfs(lin,col);
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cout<<v[i][j];
        cout<<'\n';
    }

    return 0;
}