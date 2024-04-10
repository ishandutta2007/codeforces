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

template<typename T=long long>
struct fenwick {
    vector<T> bit;
    int n;
    fenwick(int x) {
        n = x;
        bit.resize(x + 1, T(0));
    }
    void update(int j,T val)
    {
        for(;j<=n;j+=j&-j)
            bit[j] += val;
    }
    T get(int r)
    {
        T u = 0;
        for(;r;r-=r&-r)
            u += bit[r]; 
        return u;
    }
    T query(int l,int r)
    {
        return get(r)-get(l-1);
    }
    // kth element
    int getKth(T k) {
        int ans = 0;
        T cnt = 0;
        for(int i=20;i>=0;--i) {
            if(ans + (1 << i) <= n && cnt + bit[ans + (1 << i)] < k) {
                ans += (1 << i);
                cnt += bit[ans];
            }
        }
        if(ans == n) {
            return -1;
        }
        return ans + 1;
    }
    void insert(int x) {
        update(x, 1);
    }
    void erase(int x) {
        update(x, -1);
    }
};


int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<int> c(n+1);
    for(int i=1;i<=n;++i) {
        cin >> c[i];
    }
    vector<vector<int>> g(n+1);
    for(int i=1;i<=n-1;++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y), g[y].push_back(x);
    }
    fenwick<int> fenw(n+1), fenw2(n);
    auto add = [&](int l, int r, int k = 1) {
        fenw.update(l, k);
        fenw.update(r+1, -k);
    };
    vector<int> in(n+1), out(n+1);
    int cur = 1;
    function<void(int, int)> dfs = [&](int s, int p) {
        in[s] = cur++;
        fenw2.update(in[s], c[s]);
        for(auto &j:g[s]) {
            if(j != p) {
                dfs(j, s);
            }
        }
        out[s] = cur - 1;
    };
    dfs(1, 0);
    function<void(int, int)> dfs2 = [&](int s, int p) {
        int cnt = c[s];
        for(auto &j:g[s]) {
            cnt += c[j];
        }
        if(cnt >= 1) {
            add(in[s], in[s]);
        }
        for(auto &j:g[s]) {
            if(j != p) {
                dfs2(j, s);
                int t = fenw2.query(1, n) - fenw2.query(in[j], out[j]);
                if(cnt > 0 && t >= 2) {
                    // debug(s, j);
                    add(in[j], out[j]);
                }
            }
            else {
                if(cnt > 0 && fenw2.query(in[s], out[s]) >= 2) {
                    add(in[s], out[s], -1);
                    // debug(s);
                    add(1, n, 1);
                }
            }
        }
    };      
    dfs2(1, 0);
    for(int i=1;i<=n;++i) {
        cout << (fenw.get(in[i]) > 0) << " ";
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
    //cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}