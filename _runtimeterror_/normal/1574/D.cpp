// Har Har Mahadev
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
#define debug(...) 2351
#endif


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    vector<int> c(n,0);
    for(int i=0;i<n;++i) {
        cin >> c[i];
        a[i].resize(c[i]);
        for(int j=0;j<c[i];++j) {
            cin >> a[i][j];
        }
    }
    map<vector<int>,vector<int>> g;
    int m;
    cin >> m;
    for(int i=0;i<m;++i) {
        vector<int> b;
        for(int j=0;j<n;++j) {
            int x;
            cin >> x;
            --x;
            g[b].push_back(x);
            b.push_back(x);
        }
    }   
    vector<vector<bool>> f(n);
    for(int i=0;i<n;++i) {
        f[i].resize(c[i],0);
    }
    vector<int> ans;
    ll val = 0;
    set<vector<int>> vis;
    function<void(vector<int>)> dfs = [&](vector<int> v) {
        if(sz(v) == n || vis.count(v)) {
            return ;
        }
        vis.insert(v);
        for(auto &j:g[v]) {
            v.push_back(j);
            dfs(v);
            v.pop_back();
        }   
        int cur = sz(v);
        for(auto &j:g[v]) {
            f[cur][j] = 1;
        }
        int big = -1;
        for(int j=c[cur]-1;j>=0;--j) {
            if(f[cur][j] == 0) {
                big = j;
                break;
            }
        }
        if(big != -1) {
            vector<int> cur = v;
            ll x = 0;
            cur.push_back(big);
            for(int j=sz(v)+1;j<n;++j) {
                cur.push_back(c[j]-1);
            }
            assert(sz(cur) == n);
            for(int i=0;i<n;++i) {
                x += a[i][cur[i]];
            }
            // debug(x);
            if(val < x) {
                val = x;
                ans = cur;
            }
        }
        for(auto &j:g[v]) {
            f[cur][j] = 0;
        }
    };

    dfs({});
    for(auto &j:ans) {
        cout << j + 1 << " ";
    }
    // cout << val << "\n";
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