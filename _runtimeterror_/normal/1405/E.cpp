#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std ;
template<typename T>
using ordered_set = tree<T , null_type ,less<T> ,rb_tree_tag ,tree_order_statistics_node_update>;

#define ll int 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
const long double PI = acos(-1);

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 300005;

struct fenwick {
    vector<vector<ll>> bit;
    int n;
    void resize(int n_)
    {
        n = n_;
        bit.resize(n+1);
    }
    void update(int j,ll val)
    {
        for(;j<=n;j+=j&-j)
            bit[j].pb(val);
    }
    ll get(ll r,ll x)
    {
        ll u = 0;
        for(;r;r-=r&-r)
            u += sz(bit[r])-(lower_bound(all(bit[r]),x)-bit[r].begin()); 
        return u;
    }
    ll query(int l,int r,ll x)
    {
        return get(r,x)-get(l-1,x);
    }
};

fenwick seg;

struct node2
{
    ll sum,idx;
}fake;
    // base value is assigned to fake node2
struct SEGTREE2
{
    ll a[N];
    SEGTREE2(){ mem0(a); }
    node2 tree[4*N];
    ll lazy[4*N];
    inline node2 combine(node2 a,node2 b)
    {
        node2 ret;
        ret.sum=max(a.sum,b.sum);
        if(ret.sum==b.sum)
            ret.idx=b.idx;
        else
            ret.idx=a.idx;
        return ret;
    }
    inline node2 make_node2(ll val,ll i)
    {
        node2 ret;
        ret.sum=val;
        ret.idx = i;
        return ret;
    }
    inline void pushdown(ll v,ll st,ll en)
    {
        tree[v].sum+=lazy[v];
        if(st!=en)
        {
            lazy[v<<1]+=lazy[v];
            lazy[v<<1 | 1]+=lazy[v];
        }
        lazy[v]=0;
        return ;
    }
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            tree[v]=make_node2(a[st],st);
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    void rupdate(ll v,ll st,ll en,ll l,ll r,ll val)
    {
        if(lazy[v]!=0)
        {
            pushdown(v,st,en);
        }
        if(en<l || st>r)return ;
        if(st>=l && en<=r)
        {
            lazy[v]=val;
            pushdown(v,st,en);
            return ;
        }
        ll mid=(st+en)>>1;
        rupdate(v<<1,st,mid,l,r,val);
        rupdate(v<<1 | 1,mid+1,en,l,r,val);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    int query(int v,int l,int r)
    {
        return tree[1].sum==0?tree[1].idx:-1;
    }
}seg2;
ll n,q;
int a[N];

void set_()
{
    int pr = 1e9;
    int in = -1;
    while(true)
    {
        int u = seg2.query(1,0,n-1);
        if(u==-1)
            break;
        if(u>pr)
        {
            a[u+1] = pr+1;
            seg2.rupdate(1,0,n-1,u,u,-2e9);
        }
        else
        {
            pr = u;
            a[u+1] = u+1;
            seg2.rupdate(1,0,n-1,u,u,-2e9);
        }
        seg2.rupdate(1,0,n-1,u+1,n-1,1);
    }
}   

int _runtimeTerror_()
{
    cin>>n>>q;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=0;i<n;++i)
    {
        a[i] = a[i]-i-1;
        if(a[i]>0)
            a[i]=-2e9;
        seg2.a[i] = a[i];
    }
    for(int i=0;i<n;++i)
        a[i]=-1;
    seg2.buildTree(1,0,n-1);
    set_();
    seg.resize(n);
    for(int i=1;i<=n;++i)
        seg.update(i,a[i]);
    for(int i=1;i<=n;++i)
        sort(all(seg.bit[i]));
    for(int i=0;i<q;++i)
    {
        int x,y;
        cin>>x>>y;
        int u = seg.query(x+1,n-y,x+1);
        cout<<u<<"\n";
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
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}