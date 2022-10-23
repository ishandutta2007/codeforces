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
    vector<ll> a(n);
    ll S = 0;
    for(int i=0;i<n;++i) {
        cin >> a[i];
        S += a[i];
    }
    ll x = n * 1ll * (n + 1)/2;
    if(S % x) {
        cout << "NO\n";
        return 0;
    }
    S /= x;
    vector<ll> ans(n);
    for(int i=0;i<n;++i) {
        ll f = S - a[i] + a[(i - 1 + n) % n];
        if(f <= 0 || f % n > 0) {
            cout << "NO\n";
            return 0;
        }
        ans[i] = f/n;
    }
    cout << "YES\n";
    for(int i=0;i<n;++i) {
        cout << ans[i] << " ";
    } 
    cout << "\n";
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