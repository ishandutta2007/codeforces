#include"bits/stdc++.h"
using namespace std;
int vis[2005][2005];
char s[2005][2005];
int n,m;
int ans;
void dfs(int x,int y)
{
    if(x==0||y==0||x==n+1||y==m+1)
    {
        vis[x][y]=0;
        return;
    }
    int xx=x,yy=y;
    if(s[x][y]=='U')xx--;
    if(s[x][y]=='D')xx++;
    if(s[x][y]=='L')yy--;
    if(s[x][y]=='R')yy++;
    if(vis[xx][yy]==0)
    {
        vis[xx][yy]=vis[x][y]-1;
        dfs(xx,yy);
        if(ans>0)
        {
            if(ans==vis[x][y])ans=0;
            else vis[x][y]=ans;
        }
        else
        {
            vis[x][y]=vis[xx][yy]+1;
        }
    }
    else if(vis[xx][yy]<0)
    {
        ans=vis[xx][yy]-vis[x][y]+1;
        vis[xx][yy]=vis[x][y]=ans;
    }
    else
    {
        vis[x][y]=vis[xx][yy]+1;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(vis[i][j]==0)
        {
            vis[i][j]=-1;
            ans=0;
            dfs(i,j);
        }
        ans=0;int bx,by;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        {
            if(ans<vis[i][j])
            {
                ans=vis[i][j];
                bx=i;
                by=j;
            }
            vis[i][j]=0;
        }
        cout<<bx<<" "<<by<<" "<<ans<<endl;
    }
    return 0;
}