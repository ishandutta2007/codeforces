// 
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
    int n, m, Q;
    cin >> n >> m >> Q;
    vector<int> p(n+m+1);
    vector<int> cnt(n+m+1,0), right(n+m+1,0), sub(n+m+1,1);
    iota(all(p),0);

    vector<pll> v;
    for(int i=1;i<=n;++i) {
        int x;
        cin >> x;
        v.push_back({x, 1});
    }
    for(int i=1;i<=m;++i) {
        int x;
        cin >> x;
        v.push_back({x, 0});
    }

    fenwick<ll> fenw(n+m);
    ll ans = 0;

    sort(all(v));
    vector<int> cost(n+m+1);
    vector<array<int,3>> edges;
    for(int i=1;i<=n+m;++i) {
        cost[i] = v[i-1].F;
        cnt[i] = v[i-1].S;
        right[i] = i;

        fenw.update(i, cost[i]);
        if(cnt[i] == 1) {
            ans += cost[i];
        }
        if(i > 1) {
            edges.push_back({cost[i] - cost[i-1], i-1, i});
        }
    }

    sort(all(edges));

    vector<ll> fans(Q, ans);
    vector<array<int,2>> q(Q);
    for(int i=0;i<Q;++i) {
        cin >> q[i][0];
        q[i][1] = i;
    }
    sort(all(q));

    function<int(int)> parent = [&](int x) {
        return p[x] = (p[x] == x) ? x : parent(p[x]);
    };

    function<ll(int)> get = [&](int cmp) {
        return fenw.query(right[cmp] - cnt[cmp] + 1, right[cmp]);
    };

    function<void(int,int)> merge = [&](int x,int y) {
        x = parent(x), y = parent(y);
        ans -= get(x), ans -= get(y);
        if(sub[x] > sub[y]) {
            swap(x, y);
        }
        p[x] = y;
        cnt[y] += cnt[x];
        sub[y] += sub[x];
        amax(right[y], right[x]);
        ans += get(y);
    };

    int cur = 0;
    for(int i=0;i<Q;++i) {
        while(cur < sz(edges) && edges[cur][0] <= q[i][0]) {
            merge(edges[cur][1], edges[cur][2]);
            ++cur;
        }
        fans[q[i][1]] = ans;
    }

    for(int i=0;i<Q;++i) {
        cout << fans[i] << "\n";
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
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}