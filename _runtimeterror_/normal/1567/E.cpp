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


const int N = 200005;
struct node
{
    ll sum;
    ll pref, suf;
    ll len;
    node() {
        sum = pref = suf = 0;
        len = 0;
    }
}fake;
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    node tree[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.sum = a.sum + b.sum;
        ret.len = a.len + b.len;
        if(a.suf > 0) {
            ret.sum -= a.suf * (a.suf + 1)/2;
        }
        if(b.pref > 0) {
            ret.sum -= b.pref * (b.pref + 1)/2;
        }
        ret.sum += (a.suf + b.pref) * (a.suf + b.pref + 1)/2;
        ret.suf = b.suf;
        ret.pref = a.pref;
        if(b.suf == b.len) {
            ret.suf = b.len + a.suf;
        }
        if(a.pref == a.len) {
            ret.pref = a.len + b.pref;
        }
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        ret.len = 1;
        if(val == 0) {
            return ret;
        }
        ret.sum = ret.pref = ret.suf = 1;
        return ret;
    }
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            tree[v]=make_node(a[st]);
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    void update(ll v,ll st,ll en,ll in,ll val)
    {
        ll mid=(st+en)>>1;
        if(st==en)
        {
            tree[v]=make_node(val);
            a[st]=val;
            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in,val);
        else
            update(v<<1 | 1,mid+1,en,in,val);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    node query(ll v,ll st,ll en,ll l,ll r)
    {
        if(en<l || st>r)
            return fake;
        if(st>=l && en<=r)
            return tree[v];
        ll mid=(st+en)>>1;
        return combine(query(v<<1,st,mid,l,r),query(v<<1 | 1,mid+1,en,l,r));
    }
}seg;

int _runtimeTerror_()
{
    int n,Q;
    cin >> n >> Q;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        seg.a[i] = a[i] >= a[i-1];
    }
    seg.buildTree(1,1,n);
    for(int i=1;i<=Q;++i)
    {
        int tt, l, r;
        cin >> tt >> l >> r;
        if(tt == 1) {
            a[l] = r;
            seg.update(1,1,n,l,a[l] >= a[l-1]);
            if(l + 1 <= n) {
                seg.update(1,1,n,l+1,a[l+1] >= a[l]);
            }
        }
        else {
            cout << seg.query(1,1,n,l+1,r).sum + r - l + 1 << "\n";
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