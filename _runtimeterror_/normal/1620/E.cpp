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
    int Q;
    cin >> Q;
    const int N = 5e5;
    vector<vector<int>> a(N + 1);
    vector<int> p(N+1);
    iota(all(p),0);
    int id = 1;

    for(int i=1;i<=Q;++i) {
        int tt, x, y;
        cin >> tt >> x;
        if(tt == 1) {
            a[p[x]].push_back(id);
            ++id;
        }
        else {
            cin >> y;
            if(x == y) {
                continue;
            }
            if(sz(a[p[x]]) > sz(a[p[y]])) {
                swap(p[x], p[y]);
            }
            for(auto &j:a[p[x]]) {
                a[p[y]].push_back(j);
            }
            a[p[x]].clear();
        }
    }
    vector<int> ans(id - 1);
    for(int i=1;i<=N;++i) {
        for(auto &j:a[p[i]]) {
            ans[j-1] = i;
        }
    }
    for(auto i:ans) {
        cout << i << " ";
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
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}