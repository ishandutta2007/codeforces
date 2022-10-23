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

const int N = 100005;

struct node
{
    ll sum;
    ll a;
    ll d;
    ll maxd, lazyd = 0;
    node() {
        sum = a = d = maxd = lazyd = 0;
    }
}fake;

struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    node tree[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.sum = a.sum + b.sum;
        ret.maxd = max(a.maxd, b.maxd);
        return ret;
    }
    inline node make_node(ll a, ll d)
    {
        node ret;
        ret.sum = a;
        ret.maxd = d;
        return ret;
    }
    inline void pushdown(ll v,ll st,ll en)
    {
        tree[v].maxd += tree[v].lazyd;
        int len = en - st + 1;
        tree[v].sum += len * (2 * tree[v].a + (len - 1) * tree[v].d)/2;
        int mid = (st + en)/2;
        if(st!=en)
        {
            tree[v << 1].lazyd += tree[v].lazyd;
            tree[v << 1 | 1].lazyd += tree[v].lazyd;

            tree[v << 1].d += tree[v].d;
            tree[v << 1 | 1].d += tree[v].d;

            tree[v << 1].a += tree[v].a;
            tree[v << 1 | 1].a += tree[v].a + (mid + 1 - st) * tree[v].d;
        }
        tree[v].lazyd = tree[v].a = tree[v].d = 0;
        return ;
    }
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            tree[v] = make_node(a[st], st == 0 ? 0: a[st] - a[st - 1]);
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    void rupdate(ll v,ll st,ll en,ll l,ll a_ap, ll d_ap)
    {
        if(tree[v].lazyd != 0 || tree[v].a != 0 || tree[v].d != 0)
        {
            pushdown(v,st,en);
        }
        if(en < l)return ;
        if(st>=l)
        {
            tree[v].lazyd = d_ap;
            // debug(d_ap);
            tree[v].d += d_ap;
            tree[v].a += a_ap + d_ap * (st - l);
            pushdown(v,st,en);
            return ;
        }
        ll mid=(st+en)>>1;
        rupdate(v<<1,st,mid,l,a_ap, d_ap);
        rupdate(v<<1 | 1,mid+1,en,l,a_ap,d_ap);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    pll query(ll v,ll st,ll en,ll x)
    {
        if(tree[v].maxd <= x) {
            return {tree[v].sum, en};
        }
        if(st == en) {
            return {0, 0};
        }
        pushdown(v, st, en);
        int mid = (st + en)/2;
        pushdown(v << 1, st, mid);
        pushdown(v << 1 | 1, mid + 1, en);
        if(tree[v << 1].maxd > x) {
            return query(v << 1, st, mid, x);
        }
        pll ans = query(v << 1 | 1, mid + 1, en, x);
        if(ans.S == 0) {
            return {tree[v << 1].sum, mid};
        }
        ans.F += tree[v << 1].sum;
        return ans;
    }
    ll sum_q(ll v, ll st, ll en, ll l, ll r) {
        pushdown(v, st, en);
        if(st > r || en < l) {
            return 0;
        }
        if(st >= l && en <= r) {
            return tree[v].sum;
        }
        int mid = (st + en)/2;
        return sum_q(v << 1, st, mid, l, r) + sum_q(v << 1 | 1, mid + 1, en, l, r);
    }
}seg;

int _runtimeTerror_()
{
    int n, m, Q;
    cin >> n >> m >> Q;
    vector<ll> a(n), b(m);
    for(int i=0;i<n;++i) {
        cin >> a[i];
    }   
    for(int i=0;i<m;++i) {
        cin >> b[i];
        seg.a[i] = b[i];
    }
    seg.buildTree(1, 0, m-1);
    for(int i=1;i<=Q;++i) {
        int type, k, d;
        cin >> type >> k >> d;
        if(type == 1) {
            ll cur = d;
            for(int j=n-k;j<=n-1;++j) {
                a[j] += cur;
                cur += d;
            }
        }
        else {
            seg.rupdate(1, 0, m-1, m - k, d, d);
        }
        ll prev = seg.sum_q(1, 0, m-1, 0, 0);
        ll ans = a[0] + prev;
        ll cur = 0;
        for(int j=0;j<n-1;++j) {
            ll d = a[j + 1] - a[j];
            auto q = seg.query(1, 0, m-1, d);
            if(q.S <= cur) {
                ans += a[j + 1] + seg.sum_q(1, 0, m - 1, cur, cur);
            }
            else {
                int len = q.S - cur;
                ans += a[j] * len + a[j + 1] + q.F - prev;
                ans += seg.sum_q(1, 0, m - 1, q.S, q.S);
                cur = q.S;
                prev = q.F;
            }
        }   
        if(cur < m - 1) {
            ans += a[n - 1] * (m - 1 - cur) + seg.sum_q(1, 0, m - 1, cur + 1, m - 1);
        }
        cout << ans << "\n";
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