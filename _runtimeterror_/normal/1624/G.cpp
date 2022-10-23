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

struct DSU {
    int n, cmps;
    vector<int> p, sub;
    DSU(int n_) {
        n = n_;
        cmps = n;
        p.resize(n+1);
        sub.resize(n+1, 1);
        iota(p.begin(), p.end(), 0);
    }
    int parent(int i) {
        assert(i <= n);
        return p[i] = (p[i] == i ? i : parent(p[i]));
    }
    bool merge(int x, int y) {
        assert(x <= n && y <= n);
        x = parent(x), y = parent(y);
        if(x == y) {
            return false;
        }
        --cmps;
        if(sub[x] > sub[y]) {
            swap(x, y);
        }
        sub[y] += sub[x];
        p[x] = y;
        return true;
    }
    void clear() {
        cmps = n;
        iota(p.begin(), p.end(), 0);
        sub.assign(n+1, 1);
    }
    int operator[](int i) {
        return parent(i);
    }
};


int _runtimeTerror_()
{
    int n, m;
    cin >> n >> m;
    vector<array<int,3>> edges;
    for(int i=0;i<m;++i) {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }
    DSU dsu(n);
    int ans = 0;
    auto good = [&](vector<array<int,3>> &edges) {
        dsu.clear();
        int cnt = n;
        for(auto &[u, v, w]:edges) {
            cnt -= dsu[u] != dsu[v];
            dsu.merge(u, v);
        }
        return cnt == 1;
    };
    for(int i=30;i>=0;--i) {
        vector<array<int, 3>> es;
        for(auto &[u, v, w]:edges) {
            if((w & (1 << i)) == 0) {
                es.push_back({u, v, w});
            }
        }
        if(good(es)) {
            edges = es;
        }
        else {
            ans |= (1 << i);
        }
    }
    cout << ans << "\n";
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