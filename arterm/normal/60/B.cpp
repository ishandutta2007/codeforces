#include <iostream>

#define M 13

using namespace std;

long n,m,k,ans=0,
dx[]={0,0,0,0,1,-1},
dy[]={0,0,1,-1,0,0},
dz[]={1,-1,0,0,0,0};

bool f[M][M][M];

void read(void){
    char ch;
    cin>>k>>n>>m;
    for (long i=0; i<k; ++i)
    for (long j=0; j<n; ++j)
    for (long t=0; t<m; ++t)
    cin>>ch,f[i][j][t]=(ch=='#');
}

bool good(long x, long y, long z){
    return 0<=x && x<k && 0<=y && y<n && 0<=z && z<m;
}

void dfs(long x, long y, long z){
    f[x][y][z]=1;
    ans++;
    for (long k=0; k<6; ++k)
    if (good(x+dx[k],y+dy[k],z+dz[k]))
    if (!f[x+dx[k]][y+dy[k]][z+dz[k]])
    dfs(x+dx[k],y+dy[k],z+dz[k]);
}

int main()
{
    read();
    long x, y;
    cin>>x>>y;
    --x,--y;
    if (!f[0][x][y])
    dfs(0,x,y);

    cout<<ans<<"\n";
    return 0;
}