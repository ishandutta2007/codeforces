#include <iostream>

#define M 1010
#define mp make_pair
#define f first
#define s second

using namespace std;

char a[M][M];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int r,c,s=0,f=0,d[M][M];
bool u[M][M];
pair<int,int> p[M*M];

void read(void){
    cin>>r>>c;
    for (int i=1; i<=r; ++i)
    for (int j=1; j<=c; ++j)
    cin>>a[i][j];
}

void bfs(void){
    for (int i=1; i<=r; ++i)
    for (int j=1; j<=c; ++j)
    if (a[i][j]=='E'){
        u[i][j]=1;
        p[f++]=mp(i,j);
    }
    
    while (s<f){
        int x=p[s].f,y=p[s].s;
        s++;
        for (int i=0; i<4; ++i){
            int x1=x+dx[i];
            int y1=y+dy[i];
            if (a[x1][y1]!='T' && a[x1][y1]!=0 && !u[x1][y1]){
                u[x1][y1]=1;
                d[x1][y1]=d[x][y]+1;
                p[f++]=mp(x1,y1);
            }
        }
    }
}

void finish_him(void){
    long long b,ans=0;
    for (int i=1; i<=r; ++i)
    for (int j=1; j<=c; ++j)
    if (a[i][j]=='S')
    b=d[i][j];
    
    for (int i=1; i<=r; ++i)
    for (int j=1; j<=c; ++j)
    if ('0'<=a[i][j] && a[i][j]<='9')
    if (u[i][j] && d[i][j]<=b)
    ans=ans+a[i][j]-'0';
    
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    read();
    bfs();
    finish_him();
    return 0;
}