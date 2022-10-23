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
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    int cnt = 0, t2 = 0;
    bool good = false;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            char ch;
            cin >> ch;
            t2 += ch == 'B';
            if(i == r || j == c) {
                cnt += ch == 'B';
            }
            if(i == r && j == c && ch == 'B') {
                good = true;
            }
        }
    }
    if(good) {
        cout << "0\n";
    }
    else if(cnt) {
        cout << "1\n";
    }
    else if(t2){
        cout << "2\n";
    }
    else {
        cout << "-1\n";
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
        initialize();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}