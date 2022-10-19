#include"bits/stdc++.h"
using namespace std;
vector<int>v[5005];
int p[5005],c[5005],k[5005],flg[5005],anss[5005];
int vis[5005],save[5005];
bool dfs(int i)
{
    for(auto j:v[i])if(vis[j]==0)
    {
        vis[j]=1;
        if(save[j]==0||dfs(save[j]))
        {
            save[j]=i;
            return true;
        }
    }
    return false;
}
int main()
{
    int n,m,d;
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",p+i);
    for(int i=1;i<=n;i++)scanf("%d",c+i);
    cin>>d;
    int ans=0;
    for(int i=1;i<=d;i++)
    {
        scanf("%d",k+i);
        flg[k[i]]=1;
    }
    for(int i=1;i<=n;i++)if(flg[i]==0)v[p[i]+1].push_back(c[i]);
    for(int i=d;i>=1;i--)
    {
        while(1)
        {
            for(int j=1;j<=m;j++)vis[j]=0;
            if(dfs(ans+1))ans++;
            else break;
        }
        anss[i]=ans;
        v[p[k[i]]+1].push_back(c[k[i]]);
    }
    for(int i=1;i<=d;i++)printf("%d\n",anss[i]);
    return 0;
}