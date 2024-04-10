#include<bits/stdc++.h>
using namespace std ;
#define ll long long 
#define pb push_back
#define in(x) ll x; cin>>x;
#define ln(x) long long x; cin>>x;
#define memf(a) memset(a,false,sizeof(a))
#define F first
#define S second
#define endl "\n"
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
vector<vector<ll>> v;
vector<bool> check;
vector<ll> team[1002];
ll cc=0;
ll sumw[1002],sumb[1002];
ll w[1002],b[1002];
ll dp[1002][1002];
void dfs(ll x)
{
    check[x]=true;
    team[cc].pb(x);
    sumw[cc]+=w[x];
    sumb[cc]+=b[x];
    // cout<<cc<<" "<<b[x]<<" "<<x<<" "<<w[x]<<endl;
    for(auto i:v[x])
        if(!check[i])
            dfs(i);
}
int main()
{
    fast
    ll n,m,W;
    cin>>n>>m>>W;
    for(ll i=1;i<=n;i++)
        cin>>w[i];
    for(ll i=1;i<=n;i++)
        cin>>b[i];
    // cout<<n<<endl;

    check.resize(n+1);
    v.resize(n+1);
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    for(ll i=1;i<=n;i++)
    {
        if(!check[i])
        {
            dfs(i);
            cc++;
        }
    }
    // for(int i=0;i<cc;i++)
    // {
    //  for(auto j:team[i])
    //      cout<<j<<" ";
    //  cout<<endl;
    //  cout<<sumb[i]<<endl;
    // }
    ll mx=0;
    for(ll i=0;i<cc;i++)
    {
        for(ll j=0;j<=1000;j++)
        {
            dp[i+1][j]=dp[i][j];
            if(j>=sumw[i])
                dp[i+1][j]=max(dp[i+1][j],dp[i][j-sumw[i]]+sumb[i]);
            for(ll k:team[i])
            {
                if(j>=w[k])
                dp[i+1][j]=max(dp[i+1][j],dp[i][j-w[k]]+b[k]);
            }
            if(j<=W)
                mx=max(mx,dp[i+1][j]);
        }
        // cout<<mx<<endl;
    }
    cout<<mx;
    return 0;
}