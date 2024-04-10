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
    bool got = false;
    auto get = [&](int a,int b,int c) {
        cout << "? " << a << " " << b << " " << c << "\n" << flush;
        int x;
        cin >> x;
        return 1 - x;
    };
    int q = get(1, 2, 3);
    for(int i=2;i<=n-2;++i) {
        int f = get(i, i+1, i+2);
        if(f != q) {
            int l = i, r = i + 1;
            got = true;
            vector<int> x, y;
            for(int i=1;i<=n;++i) {
                if(i == l || i == r) {
                    continue;
                }
                int tmp = get(l, r, i);
                if(tmp == 1) {
                    x.push_back(i);
                }
                else {
                    y.push_back(i);
                }
            }
            int tmp = get(x[0], y[0], l);
            if(tmp == 1) {
                x.push_back(l);
            }
            else {
                x.push_back(r);
            }
            sort(all(x));
            cout << "! ";
            cout << sz(x) << " ";
            for(auto &j:x) {
                cout << j << " ";
            }
            cout << "\n" << flush;
            return 0;
        }
        else {
            q = f;
        }
    }
    assert(got);
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