#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const int V=510;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
char s[V][V];
int vis[V][V];
int q[2*V*V];
int n,m,K;
int main()
{
    while(~scanf("%d%d%d",&n,&m,&K))
    {
        int em=0;
        int sx=-1,sy=-1;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            for(int j=0;j<m;j++)
            if(s[i][j]=='.')
            {
                sx=i;sy=j;
                em++;
            }
        }
        int cnt=em-K;
        memset(vis,0,sizeof(vis));
        int top=0,tail=0;
        tail++;q[tail]=sx;
        tail++;q[tail]=sy;
        vis[sx][sy]=1;
        while(top!=tail)
        {
            top++;
            int nx=q[top];
            top++;
            int ny=q[top];\
            for(int i=0;i<4;i++)
            {
                int tx=nx+dx[i];
                int ty=ny+dy[i];
                if(tx<0||tx>=n)continue;
                if(ty<0||ty>=m)continue;
                if(s[tx][ty]=='#')continue;
                if(!vis[tx][ty])
                {
                    if(tail/2<cnt)
                    {
                        vis[tx][ty]=1;
                        tail++;q[tail]=tx;
                        tail++;q[tail]=ty;
                    }
                }
            }
        }
        for(int i=0;i<n;i++,puts(""))
        for(int j=0;j<m;j++)
        if(s[i][j]=='.')
        {
            if(vis[i][j])printf(".");
            else printf("X");
        }
        else printf("#");
    }
}