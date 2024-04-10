#include"bits/stdc++.h"
using namespace std;
vector<int>v[200005];
int ok[200005];
int fa[200005][21];
int vis[200005];
int deep[200005];
int ans;
void dfs(int i)
{
    vis[i]=1;
    int num=0;
    for(auto j:v[i])if(vis[j]==0)
    {
        num++;
        fa[j][0]=i;
        deep[j]=deep[i]+1;
        dfs(j);
    }
    if(num==0)ok[i]=1;
}
void dfs2(int i)
{
    vis[i]=3;
    for(auto j:v[i])if(vis[j]==1)
    {
        dfs2(j);
    }
    else if(vis[j]==2)ans++;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        vector<int>pos;
        for(int i=0;i<m;i++)
        {
            int a;
            scanf("%d",&a);
            pos.push_back(a);
        }
        for(int i=0;i<=n;i++)
        {
            vis[i]=0;
            ok[i]=0;
            v[i].clear();
        }
        for(int i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(1);
        for(int i=1;i<21;i++)for(int j=1;j<=n;j++)fa[j][i]=fa[fa[j][i-1]][i-1];
        for(auto i:pos)
        {
            int now=deep[i]/2;
            for(int j=20;j>=0;j--)if((1<<j)<=now)
            {
                now-=(1<<j);
                i=fa[i][j];
            }
            vis[i]=2;
        }
        ans=0;
        dfs2(1);
        bool flag=0;
        for(int i=1;i<=n;i++)if(ok[i]==1&&vis[i]==3)
        {
            flag=1;
        }
        if(flag)printf("-1\n");
        else printf("%d\n",ans);
    }
    return 0;
}