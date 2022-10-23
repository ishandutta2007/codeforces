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

int _runtimeTerror_()
{
    ll n;
    cin>>n;
    vector<int> v(n+1);
    ll dp[n+1][2];
    for(int i=0;i<=n;++i)
        dp[i][0] = INF,dp[i][1] = INF;
    for(int i=1;i<=n;++i)
        cin>>v[i];
    dp[0][0] = dp[0][1] = 0;
    dp[0][0] = INF;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=1;++j)
        {
            amin(dp[i][j],dp[i-1][j^1] + (v[i]==1 && j==0));
            if(i>1)
            {
                ll u = dp[i-2][j^1];
                u += (v[i]==1 && j==0);
                u += (v[i-1]==1 && j==0);
                amin(dp[i][j],u);
            }
        }
    }
    cout<<min(dp[n][0],dp[n][1])<<"\n";
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}