#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

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
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 500005;
int c[N],n;
int answ[N];

vector<pair<int,int>> v[N];

vector<vector<int>> dp;

void dfs(int l,int r)
{
    if(l>r)
        return ;
    int mid = (l+r)/2;
    for(int i=l;i<=r;++i)
        for(int j=0;j<=20;++j)
            dp[i][j] = 0;
    auto add = [&](vector<int> &dp,int u)
    {
        for(int j=20;j>=0;--j)
        {
            if((u&(1<<j))==0)
                continue;
            if(dp[j]==0)
                dp[j] = u;
            u ^= dp[j];
        }
    };
    for(int i=mid-1;i>=l;--i)
    {
        for(int j=0;j<=20;++j)
            dp[i][j] = dp[i+1][j];
        add(dp[i],c[i]);
    }
    for(int i=mid;i<=r;++i)
    {
        if(i==mid)
        {
            add(dp[i],c[i]);
            // continue;
        }
        else
        {   
            for(int j=0;j<=20;++j)
                dp[i][j] = dp[i-1][j];
            add(dp[i],c[i]);
        }
        for(auto j:v[i])
        {
            if(j.F>mid  || j.F<l)
                continue;
            vector<int> ans(20,0);
            ans = dp[i];
            for(int k=0;k<=20;++k)
                add(ans,dp[j.F][k]);
            answ[j.S] = 0;
            for(int k=20;k>=0;--k)
            {
                if((answ[j.S]&(1<<k)))
                    continue;
                answ[j.S] ^= ans[k];
            }
        }
    }
    dfs(l,mid-1);
    dfs(mid+1,r);
}

int _runtimeTerror_()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>c[i];
    int Q;
    cin>>Q;
    dp.resize(N);
    for(int i=0;i<=n;++i)
    {
        dp[i].resize(21);
    }
    for(int i=1;i<=Q;++i)
    {
        int l,r;
        cin>>l>>r;
        v[r].pb({l,i});
    }
    dfs(1,n);
    for(int i=1;i<=Q;++i)
        cout<<answ[i]<<"\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}