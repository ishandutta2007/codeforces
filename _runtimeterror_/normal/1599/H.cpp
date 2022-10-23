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
    pii x = {1, 1}, y = {1, 1e9};
    int xd = 1, yd = -1;
    auto get = [&](pii a) {
        cout << "? " << a.F << " " << a.S << "\n";
        cout << flush;
        // int ans = 2e9;
        // for(int i=2;i<=4;++i) {
        //     for(int j=3;j<=5;++j) {
        //         amin(ans, abs(a.F - i) + abs(a.S - j));
        //     }
        // }
        int x;
        cin >> x;
        return x;
    };
    auto tmp = get(x);
    auto tmp2 = get(y);
    if(tmp > tmp2) {
        swap(x, y);
        swap(xd, yd);
        swap(tmp, tmp2);
    }
    int lo = 1, hi = 1e9 - 1;
    pii ans = {-1, -1};
    while(lo <= hi) {
        int mid = (lo + hi)/2;
        x.S += xd * mid;
        auto f = get(x);
        if(f == tmp) {
            ans = x;
            x.S -= xd * mid;
            break;
        }
        else if(f > tmp) {
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
        x.S -= xd * mid;
    }
    int mid = (x.S + ans.S) / 2;
    int l = 1 + get({1, mid});
    int r = 1e9 - get({1e9, mid});
    int u = 1e9 - get({(l + r)/2, 1e9});
    int d = 1 + get({(l + r)/2,1});
    cout << "! " << l << " " << d << " " << r << " " << u << "\n";
    cout << flush;

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
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}