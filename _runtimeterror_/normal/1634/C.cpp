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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif


int _runtimeTerror_()
{
    int n, k;
    cin >> n >> k;
    if(n % 2 == 1 && k > 1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    if(n & 1) {
        for(int i=1;i<=n;++i) {
            cout << i << "\n";
        }
        return 0;
    }
    int cur = 1;
    for(int i=1;i<=n/2;++i) {
        for(int j=0;j<k;++j) {
            cout << cur + (2 * j) << " ";
        }
        cout << "\n";
        for(int j=1;j<=k;++j) {
            cout << cur + (2 * j - 1) << " ";
        }
        cout << "\n";
        cur += 2 * k;
    }
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