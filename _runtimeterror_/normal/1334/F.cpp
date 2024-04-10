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

const int N = 500005;

template<typename T=long long>
struct fenwick {
    T a[N],bit[N];
    int n;
    fenwick() 
    {
        for(int i=1;i<=N-2;++i)
            a[i] = T(0),bit[i] = T(0);
    }
    void build(int n_)
    {
        n = n_;
        for(int i=1;i<=n;++i)
            for(int j=i;j<=n;j+=j&-j)
                bit[j] += a[i];
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
};
// call fenw.build(n);
fenwick<ll> fenw;

int _runtimeTerror_()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<pii> t;
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        t.push_back({a[i],i});
    }
    sort(t.begin(),t.end());
    fenw.build(n);
    vector<ll> p(n+1),sum(n+1,0), dp(n+1,INF);
    for(int i=1;i<=n;++i) {
        cin >> p[i];
        sum[i] = sum[i-1] + p[i];
        if(p[i] < 0)
            fenw.update(i,p[i]);
    }
    int m;
    cin >> m;
    vector<int> b(m+1);
    vector<int> ids;
    for(int i=1;i<=m;++i)
        cin >> b[i];
    ll ans = INF;
    int cur = n - 1;
    for(int i=m;i>=1;--i)
    {   
        while(cur >= 0 && t[cur].first > b[i]) {
            if(p[t[cur].S] >= 0) {
                fenw.update(t[cur].S,p[t[cur].S]);
            }
            --cur;
        }
        vector<int> tmp;
        int pt = 0;
        while(cur >= 0 && t[cur].first == b[i]) {
            int x = t[cur].S;
            while(pt < sz(ids) && ids[pt] > x) {
                amin(dp[x], dp[ids[pt]] + fenw.query(x+1,ids[pt]-1));
                ++pt;
            }
            if(!tmp.empty()) {
                amin(dp[x], dp[tmp.back()] + fenw.query(x + 1, tmp.back()));
            }
            if(i == m) {
                dp[x] = fenw.query(x + 1, n);
            }
            --cur;
            if(i == 1) {
                amin(ans, dp[x] + sum[x-1]);
            }
            tmp.push_back(x);
        }
        ids = tmp;
        for(auto &i:ids) {
            fenw.update(i, p[i] > 0 ? p[i] : 0);
        } 
    }
    if(ans >= 1e16)
        cout << "NO\n";
    else
        cout << "YES\n" << ans << "\n";
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