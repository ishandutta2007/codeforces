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
    ll x, n;
    cin >> x >> n;
    ll p = (x % 2 + 2) % 2;
    if(n % 4 == 1) {
        if(p % 2 == 0) {
            x -= n;
        }
        else {
            x += n;
        }
    }
    else if(n % 4 == 2) {
        if(p % 2 == 0) {
            ++x;
        }
        else {
            --x;
        }
    }
    else if(n % 4 == 3) {
        if(p % 2 == 0) {
            x += n + 1;
        }
        else {
            x -= n + 1;
        }
    }
    cout << x << "\n";
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