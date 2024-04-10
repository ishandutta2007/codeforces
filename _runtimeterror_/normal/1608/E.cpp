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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

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
    vector<int> x(n), y(n), c(n);
    for(int i=0;i<n;++i) {
        cin >> x[i] >> y[i] >> c[i];
    }
    auto compress = [&](vector<int> &x) {
        auto u = x;
        sort(all(u));
        map<int,int> id;
        id[u[0]] = 1;
        for(int i=1;i<n;++i) {
            if(u[i] != u[i-1]) {
                id[u[i]] = id[u[i-1]] + 1;
            }
        }
        for(auto &j:x) {
            j = id[j];
        }
    };
    compress(x),compress(y);
    int ans = 0;
    auto solve = [&](vector<int> x, vector<int> y, vector<int> c, int ldown, int lup, int right) {
        vector<int> f(n);
        iota(all(f), 0);
        sort(all(f), [&](int a, int b) {
            return x[a] < x[b];
        });
        vector<int> cnt(n+1, 0);
        for(int i=n-1;i>=0;--i) {
            cnt[i] = cnt[i+1] + (c[f[i]] == right);
        }
        const int N = 1e5+1;
        fenwick<int> up(N), down(N), lx(N), rx(N);
        auto add = [&](int a) {
            if(c[a] == ldown) {
                down.insert(y[a]);
                lx.insert(x[a]);
            }
            else if(c[a] == lup) {
                up.insert(y[a]);
                rx.insert(x[a]);
            }
        };

        auto check = [&](int x) {
            if(x == 0) {
                return true;
            }
            if(x > down.get(N) || x > up.get(N)) {
                return false;
            }
            int aaa = down.getKth(x);
            int bbb = up.getKth(up.get(N) - x + 1);
            int ccc = lx.getKth(x);
            int ddd = rx.getKth(up.get(N) - x + 1);
            return bbb > aaa || ddd > ccc;
        };
        int prev = 0;
        for(int i=0;i<n;++i) {
            int j = i;
            while(j < n && x[f[j]] == x[f[i]]) {
                add(f[j]);
                ++j;
            }
            while(prev < n && check(prev)) {
                ++prev;
            }
            int val = prev - 1;
            i = j - 1;
            amax(ans, min(val, cnt[i+1]));
        }
    };

    vector<int> cols = {1, 2, 3};
    do{
        solve(x, y, c, cols[0], cols[1], cols[2]);
    }while(next_permutation(all(cols)));

    for(int i=0;i<n;++i) {
        x[i] = 1e5 + 1 - x[i];
    }
    cols = {1, 2, 3};
    do{
        solve(x, y, c, cols[0], cols[1], cols[2]);
    }while(next_permutation(all(cols)));

    for(int i=0;i<n;++i) {
        x[i] = 1e5 + 1 - x[i];
    }
    swap(x, y);
    cols = {1, 2, 3};
    do{
        solve(x, y, c, cols[0], cols[1], cols[2]);
    }while(next_permutation(all(cols)));

    for(int i=0;i<n;++i) {
        x[i] = 1e5 + 1 - x[i];
    }
    cols = {1, 2, 3};
    do{
        solve(x, y, c, cols[0], cols[1], cols[2]);
    }while(next_permutation(all(cols)));

    cout << ans * 3 << "\n";
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