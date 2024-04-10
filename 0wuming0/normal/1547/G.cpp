#include"bits/stdc++.h"
using namespace std;
vector<int>v[400005];
int vis[400005];
int save[400005];
void dfs(int i)
{
    save[i]=1;
    vis[i]=1;
    for(auto j:v[i])
    {
        if(vis[j]==0)dfs(j);
        else if(save[j])vis[j]=-1;
        else if(vis[j]!=-1)vis[j]=2;
    }
    save[i]=0;
}
void dfs1(int i)
{
    vis[i]=-1;
    for(auto j:v[i])if(vis[j]!=-1)
    {
        dfs1(j);
    }
}
void dfs2(int i)
{
    vis[i]=2;
    for(auto j:v[i])if(vis[j]!=2&&vis[j]!=-1)
    {
        dfs2(j);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)vis[i]=0;
        for(int i=0;i<m;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
        }
        dfs(1);
        for(int i=1;i<=n;i++)if(vis[i]==2)dfs2(i);
        for(int i=1;i<=n;i++)if(vis[i]==-1)dfs1(i);
        for(int i=1;i<=n;i++)printf("%d%c",vis[i]," \n"[i==n]);
        for(int i=1;i<=n;i++)v[i].clear();
    }
    return 0;
}