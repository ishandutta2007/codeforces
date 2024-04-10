#include <iostream>
#include <cstring>

using namespace std;

int n,m;

char mat[105][105];
char viz[105][105];

int cnt;
void dfs(int x,int y) {
    if(x<1 || y<1 || x>n || y>m || mat[x][y]=='.' || viz[x][y])
        return;
    viz[x][y]=1;
    cnt++;

    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);
}

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int main()
{
    cin>>n>>m;

    int i,j,tot=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++) {
            cin>>mat[i][j];
            tot+=(mat[i][j]=='#');
        }

    if(tot<=2){
        cout<<"-1\n";
        return 0;
    }

    int k;
    int nx,ny;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(mat[i][j]=='#') {
                memset(viz,0,sizeof(viz));
                cnt=0;

                mat[i][j]='.';
                for(k=0;k<4;k++) {
                    nx=i+dx[k];
                    ny=j+dy[k];

                    if(nx>=1 && ny>=1 && nx<=n && ny<=m && mat[nx][ny]=='#') {
                        dfs(nx,ny);

                        break;
                    }
                }

                mat[i][j]='#';
                cnt++;

                if(cnt!=tot) {
                    cout<<"1\n";
                    return 0;
                }
            }

    cout<<"2\n";
    return 0;
}