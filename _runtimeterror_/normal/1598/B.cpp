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
    vector<vector<int>> a(n,vector<int>(5,0));
    for(int i=0;i<n;++i) {
        for(int j=0;j<5;++j) {
            cin >> a[i][j];
        }
    }
    for(int i=0;i<5;++i) {
        for(int j=i+1;j<5;++j) {
            int f = 0, g = 0;
            for(int k=0;k<n;++k) {
                if(a[k][i] == 1 && a[k][j] == 0) {
                    ++f;
                }
                if(a[k][j] == 1 && a[k][i] == 0) {
                    ++g;
                }
                if(a[k][i] == 0 && a[k][j] == 0) {
                    f = g = n;
                }
            }
            if(n % 2 == 0 && f <= n / 2 && g <= n / 2) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
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