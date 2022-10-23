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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T , null_type ,less<T> ,rb_tree_tag ,tree_order_statistics_node_update>;

const int N = 300005;

ordered_set<int> pars[N];

vector<pii> v[N];
int p[N];
vector<int> g[N];

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

// lots of proofs and amazing problem

int _runtimeTerror_()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    fenwick<ll> fenw(n+1);
    vector<int> l(n+1, 0), r(n+1, 0);
    vector<int> st1, st2;
    for(int i=1;i<=n;++i) {
        if(s[i-1] == '(') {
            st1.push_back(i);
        }
        else if(!st1.empty()) {
            fenw.update(i, 1);
            while(!st2.empty() && st2.back() > st1.back()) {
                p[st2.back()] = i;
                g[i].push_back(st2.back());
                pars[i].insert(st2.back());
                st2.pop_back();
            }
            l[i] = st1.back();
            r[l[i]] = i;
            st1.pop_back();
            st2.push_back(i);
        }
    }   
    while(!st2.empty()) {
        p[st2.back()] = n+1;
        g[n+1].push_back(st2.back());
        pars[n+1].insert(st2.back());
        st2.pop_back();
    }
    for(int i=1;i<=n+1;++i) {
        if(g[i].empty()) {
            continue;
        }
        sort(all(g[i]));
        v[i].push_back({g[i][0], 1});
        for(int j=1;j<sz(g[i]);++j) {
            if(l[g[i][j]] == g[i][j-1] + 1) {
                ++v[i].back().S;
                v[i].back().F = g[i][j];
            }
            else {
                v[i].push_back({g[i][j], 1});
            }
        }
        for(auto &[x, y]:v[i]) {
            fenw.update(i, y * 1ll * (y - 1)/2);
        }
    }
    auto del = [&](int x, int y) {
        int px = p[y];
        pars[px].erase(y);
        fenw.update(y, -1);
        pii &f = v[px][lower_bound(all(v[px]), make_pair(y, 0)) - v[px].begin()];
        --f.S;
        fenw.update(px, -f.S);
    };  
    for(int i=1;i<=q;++i) {
        int tt, lx, rx;
        cin >> tt >> lx >> rx;
        if(tt == 1) {
            del(lx, rx);
        }
        else {
            int px = p[rx];
            int cnt = pars[px].order_of_key(rx+1) - pars[px].order_of_key(lx);
            cout << fenw.query(lx, rx) + cnt * 1ll * (cnt - 1) / 2 << "\n";
        }
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