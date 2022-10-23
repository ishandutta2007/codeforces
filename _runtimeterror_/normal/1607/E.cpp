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
    int n, m;
    cin >> n >> m;
    int mxx = 0, mnx = 0, mxy = 0, mny = 0, x = 0, y = 0;
    string s;
    cin >> s;
    int ansx = 1, ansy = 1;
    for(auto j:s) {
        x += j == 'D';
        x -= j == 'U';
        y += j == 'R';
        y -= j == 'L';
        amax(mxx, x), amin(mnx, x), amax(mxy, y), amin(mny, y);
        if(mxx - mnx + 1 <= n && mxy - mny + 1 <= m) {
            ansx = 1 - mnx, ansy = 1 - mny;
        }
        else {
            break;
        }
    }
    cout << ansx << " " << ansy << "\n";
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