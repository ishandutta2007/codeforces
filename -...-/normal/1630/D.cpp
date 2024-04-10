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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif


int _runtimeTerror_()
{
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }
    int g = 0;
    for(int i=1;i<=m;++i) {
        int x;
        cin >> x;
        g = __gcd(g, x);
    }
    vector<vector<ll>> b(g);
    for(int i=0;i<n;++i) {
        b[i % g].push_back(a[i]);
    }
    vector<ll> sum((n + g - 1) / g + 10, 0), dp((n + g - 1)/g + 10, 0);
    int t = (n + g - 1) / g;
    for(int i=0;i<g;++i) {
        sort(all(b[i]));
        int s = sz(b[i]);
        for(int j=0;j<s;++j) {
            sum[j] += b[i][j];
        }
        vector<ll> ndp(t + 10, 0);
        ndp[s-1] = b[i][s-1];
        for(int j=s-2;j>=0;--j) {
            ndp[j] = ndp[j + 2] - (b[i][j] + b[i][j + 1]); 
            amax(ndp[j], b[i][j] + b[i][j + 1] + ndp[j + 2]);
        }
        for(int j=0;j<s;++j) {
            dp[j] += ndp[j];
        }
    }
    for(int j=1;j<n/g;++j) {
        sum[j] += sum[j - 1];
    }
    ll ans = dp[0];
    for(int i=0;i<n/g;++i) {
        amax(ans, -sum[i] + dp[i + 1]);
    }
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
        initncr();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}