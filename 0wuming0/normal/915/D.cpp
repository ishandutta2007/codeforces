#include"bits/stdc++.h"
using namespace std;
int num[505];
int savenum[505];
int savevis[505];
vector<int>v[505];
int vis[505];
int nn;
int savenn;
void solve(int i)
{
    vis[i]=1;
    nn++;
    for(auto j:v[i])
    {
        num[j]--;
        if(vis[j]==0)if(num[j]==0)solve(j);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        num[b]++;
    }
    for(int i=1;i<=n;i++)if(vis[i]==0)
    {
        if(num[i]==0)solve(i);
    }
    savenn=nn;
    for(int i=1;i<=n;i++)savevis[i]=vis[i],savenum[i]=num[i];
    for(int u=1;u<=n;u++)if(vis[u]==0&&num[u]==1)
    {
        solve(u);
        for(int i=1;i<=n;i++)if(vis[i]==0)
        {
            if(num[i]==0)solve(i);
        }
        if(nn==n)
        {
            cout<<"YES"<<endl;
            return 0;
        }
        nn=savenn;
        for(int i=1;i<=n;i++)vis[i]=savevis[i],num[i]=savenum[i];
    }
    if(savenn==n)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}