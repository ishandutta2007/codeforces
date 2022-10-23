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

const int N = 1000005;

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

vector<int> g[N];
set<int> f[N];
int a[N];
int mp[N];
int ans[N];

vector<array<int,3>> q[N];


int _runtimeTerror_()
{
    int n, Q;
    cin >> n >> Q;
    fenwick<int> fenw(n);
    f[0].clear();
    for(int i=1;i<=n;++i) {
        f[0].insert(a[i]);
    }
    for(int i=1;i<=n;++i) {
        g[i].clear();
        f[i].clear();
        mp[i] = 0;
        cin >> a[i];
    }
    for(int i=1;i<=n;++i) {
        q[i].clear();
        ans[i] = 0;
    }
    for(int i=2;i<=n;++i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    for(int i=1;i<=Q;++i) {
        int v, l, k;
        cin >> v >> l >> k;
        q[v].push_back({l, k, i});
    }
    auto add = [&](int u) {
        f[mp[a[u]]].erase(a[u]);
        if(mp[a[u]] > 0) {
            fenw.update(mp[a[u]], -1);
        }
        ++mp[a[u]];
        f[mp[a[u]]].insert(a[u]);
        fenw.update(mp[a[u]], 1);
    };
    auto del = [&](int u) {
        f[mp[a[u]]].erase(a[u]);
        fenw.update(mp[a[u]], -1);
        --mp[a[u]];
        if(mp[a[u]] > 0) {
            fenw.update(mp[a[u]], 1);   
        }
        f[mp[a[u]]].insert(a[u]);
    };
    function<void(int)> dfs = [&](int s) {
        add(s);
        for(auto &[l, k, id]:q[s]) {
            int fx = fenw.get(l-1);
            auto idx = fenw.getKth(fx + k);
            if(idx != -1) {
                assert(idx > 0);
                assert(!f[idx].empty());
                idx = *f[idx].begin();
            }
            ans[id] = idx;
        }
        for(auto &j:g[s]) {
            dfs(j);
        }
        del(s);
    };
    dfs(1);
    for(int i=1;i<=Q;++i) {
        cout << ans[i] << " ";
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
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}