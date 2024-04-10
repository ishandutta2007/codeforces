// Har Har Mahadev
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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif


int _runtimeTerror_()
{
    int n;
    cin >> n;
    int sq = sqrt(2 * n) + 10;
    vector<vector<ll>> dp(n+2,vector<ll>(sq + 2, 0));
    vector<ll> psum(n+1), a(n+1);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        psum[i] = psum[i-1] + a[i];
    }
    // debug(sq);
    ll ans = 1;
    for(int i=n;i>=1;--i) {
        for(int j=1;j<=sq && i + j - 1 <= n;++j) {
            dp[i][j] = dp[i+1][j];
            ll x = psum[i + j - 1] - psum[i - 1];
            if(dp[i + j][j - 1] > x || j == 1) {
                amax(dp[i][j], x);
            }
            if(dp[i][j] > 0) {
                amax(ans, j);
            }
        }
    }
    // debug(dp[5][1]);
    cout << ans << "\n";
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
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}