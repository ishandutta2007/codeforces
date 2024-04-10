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
    int n, m;
    cin >> m >> n;
    vector<array<int,3>> a;
    for(int i=0;i<n;++i) {
        int x;
        cin >> x;
        a.push_back({x, 1, i});
        a.push_back({m + x, 1, i});
    }
    for(int i=0;i<n;++i) {
        int x;
        cin >> x;
        a.push_back({x, -1, i});
        a.push_back({m + x, -1, i});
    }
    sort(all(a));
    vector<ll> val(2 * n, 0);
    for(int i=0;i<2*n;++i) {
        val[0] += a[i][0];
    }
    for(int i=1;i<2*n;++i) {
        val[i] = val[i-1] - a[i-1][0] + a[i + 2*n - 1][0];
    }
    auto solve = [&](vector<array<int,3>> &a) {
        vector<vector<array<int,2>>> add(4*n+1), del(4*n+1);
        int psum = 0;
        fenwick<ll> fenw(5*n);
        for(int i=0;i<4*n;++i) {
            psum += a[i][1];
            if(a[i][1] == -1) {
                continue;
            }
            del[i+1].push_back({psum + 2*n + 1, a[i][0]});
            add[max(0, i - 2*n + 1)].push_back({psum + 2*n + 1, a[i][0]});
        }
        psum = 0;
        for(int i=0;i<2*n;++i) {
            for(auto &[k,t]:del[i]) {
                fenw.update(k, -t);
            }
            for(auto &[k,t]:add[i]) {
                fenw.update(k, t);
            }
            val[i] -= 2 * fenw.query(psum + 2*n + 2, 5*n);
            psum += a[i][1];
        }
    };
    solve(a);
    for(int i=0;i<4*n;++i) {
        a[i][1] = -a[i][1];
    }
    solve(a);
    ll ans = *min_element(all(val));
    cout << ans << "\n";
    for(int i=0;i<2*n;++i) {
        if(val[i] == ans) {
            vector<int> match(n);
            vector<int> l, r;
            for(int j=0;j<2*n;++j) {
                if(a[i+j][1] == -1) {
                    l.push_back(a[i+j][2]);
                }
                else {
                    r.push_back(a[i+j][2]);
                }
            }
            for(int j=0;j<n;++j) {
                match[l[j]] = r[j];
            }
            for(int j=0;j<n;++j) {
                cout << match[j] + 1 << " ";
            }
            return 0;
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
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}