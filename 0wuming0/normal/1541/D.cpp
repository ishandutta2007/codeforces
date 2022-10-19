#include"bits/stdc++.h"
using namespace std;
#define ll long long
ll mod=1e9+7;
vector<int>v[205];
int vis[205];
int now;
vector<int>rd[205][205];
void crt(int i,int j)
{
    vis[j]=now;
    for(auto k:v[j])if(vis[k]!=now)
    {
        rd[i][k]=rd[i][j];
        rd[i][k].push_back(k);
        crt(i,k);
    }
}
ll invn;
ll ans;
ll dp[205][205];
int dfs(int i)
{
    int ans=1;
    vis[i]=now;
    for(auto j:v[i])if(vis[j]!=now)
    {
        ans+=dfs(j);
    }
    return ans;
}
void solve(int a,int b)
{
    for(auto i:rd[a][b])vis[i]=now;
    int len=rd[a][b].size()-1;
    int k=0;
    for(auto i:rd[a][b])
    {
        ans+=dfs(i)*dp[k][len-k]%mod;
        ans%=mod;
        k++;
    }
}
ll getinv(int n)
{
    if(n==1)return 1;
    return (mod-mod/n)*getinv(mod%n)%mod;
}
int main()
{
    int n;
    cin>>n;
    invn=getinv(n);
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        ++now;
        rd[i][i].push_back(i);
        crt(i,i);
    }
    for(int i=1;i<=200;i++)dp[i][0]=1;
    ll _2=getinv(2);
    for(int i=1;i<=200;i++)for(int j=1;j<=200;j++)
    {
        dp[i][j]=(dp[i-1][j]+dp[i][j-1])*_2%mod;
    }
    for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)
    {
        ++now;
        solve(i,j);
    }
    cout<<ans*invn%mod<<endl;
    return 0;
}