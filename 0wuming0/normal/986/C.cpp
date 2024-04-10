#include"bits/stdc++.h"
using namespace std;
bool vis[1<<22];
bool vis2[1<<22];
bool hv[1<<22];
void solve(int i);
void dfs(int i)
{
    vis[i]=1;
    if(vis2[i^((1<<22)-1)]==0)solve(i^((1<<22)-1));
}
void solve(int i)
{
    vis2[i]=1;
    if(hv[i]&&vis[i]==0)dfs(i);
    for(int j=0;j<22;j++)if(i&(1<<j))
    {
        if(vis2[i^(1<<j)]==0)solve(i^(1<<j));
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a;
        scanf("%d",&a);
        hv[a]=1;
    }
    int ans=0;
    for(int i=(1<<22)-1;i>=0;i--)if(hv[i]&&vis[i]==0)
    {//cout<<"ok"<<i<<endl;
        ans++;
        dfs(i);
    }
    cout<<ans<<endl;
    return 0;
}