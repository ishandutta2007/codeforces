#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 5005;

ll dp[N][N];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=0;i<=n;++i)
        for(int j=0;j<=n;++j)
            dp[i][j] = INF;
    dp[0][0] = 0;
    for(int i=1;i<=n;++i)
        dp[i][0] = 0;
    ll ans = INF;
    for(int j=1;j<=n;++j)
    {
        if(a[j] == 1)
            break;
        dp[0][j] = 0;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(a[i] == 0 && a[j] == 1)
            {
                amin(dp[i][j],dp[i-1][j-1] + abs(i-j));
                amin(dp[i][j],dp[i-1][j]);
            }
            else
            {
                amin(dp[i][j],dp[i-1][j]);
                if(a[j] == 0)
                    amin(dp[i][j],dp[i-1][j-1]),amin(dp[i][j],dp[i][j-1]);
            }
        }
        amin(ans,dp[i][n]);
    }
    // cout<<dp[1][1]<<"\n";
    // cout<<dp[2][1]<<"\n";
    cout<<ans<<"\n";
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