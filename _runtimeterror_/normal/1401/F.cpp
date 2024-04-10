#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
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


const int N = (1<<18)+10;

struct node
{
    ll sum;
}fake={0};
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ mem0(a); mem0(lazy);}
    node tree[4*N];
    ll lazy[4*N];
    int l[4*N],r[4*N];
    int dep[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.sum=a.sum+b.sum;
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        ret.sum=val;
        return ret;
    }
    inline void pushdown(ll v,ll st,ll en)
    {
        if(lazy[v]&(1<<dep[v]))
        {
            swap(l[v],r[v]);
        }
        if(st!=en)
        {
            lazy[l[v]]^=lazy[v];
            lazy[r[v]]^=lazy[v];
        }
        lazy[v]=0;
        return ;
    }
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            tree[v]=make_node(a[st]);
            l[v]=-1,r[v]=-1;
            return ;
        }
        ll mid=(st+en)>>1;
        dep[v<<1]=dep[v]+1;
        dep[v<<1|1]=dep[v]+1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        l[v]=v<<1,r[v]=v<<1|1;
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    void update(ll v,ll st,ll en,ll in,ll val)
    {
        pushdown(v,st,en);
        ll mid=(st+en)>>1;
        if(st==en)
        {
            tree[v]=make_node(val);
            a[st]=val;
            return ;
        }
        pushdown(l[v],st,mid);
        pushdown(r[v],mid+1,en);
        if(in<=mid)
            update(l[v],st,mid,in,val);
        else
            update(r[v],mid+1,en,in,val);
        tree[v]=combine(tree[l[v]],tree[r[v]]);
    }
    void rupdate(ll v,ll st,ll en,ll lx,ll rx,ll val)
    {
        if(lazy[v]!=0)
        {
            pushdown(v,st,en);
        }
        if(en<lx || st>rx)return ;
        if(st>=lx && en<=rx)
        {
            lazy[v]=val;
            pushdown(v,st,en);
            return ;
        }
        ll mid=(st+en)>>1;
        rupdate(l[v],st,mid,lx,rx,val);
        rupdate(r[v],mid+1,en,lx,rx,val);
        tree[v]=combine(tree[l[v]],tree[r[v]]);
    }
    node query(ll v,ll st,ll en,ll lx,ll rx)
    {
        if(lazy[v]!=0)
        {
            pushdown(v,st,en);
        }
        if(en<lx || st>rx)
            return fake;
        if(st>=lx && en<=rx)
            return tree[v];
        ll mid=(st+en)>>1;
        return combine(query(l[v],st,mid,lx,rx),query(r[v],mid+1,en,lx,rx));
    }
}seg;

int _runtimeTerror_()
{
    int n,Q;
    cin>>n>>Q;
    for(int i=0;i<(1<<n);++i)
        cin>>seg.a[i];
    int nx=(1<<n);
    seg.dep[1]=0;
    seg.buildTree(1,0,nx-1);
    while(Q--)
    {
        int tt,x,k,l,r;
        cin>>tt;
        if(tt==1)
        {
            cin>>x>>k;
            seg.update(1,0,nx-1,x-1,k);
        }
        else if(tt==2)
        {
            cin>>k;
            for(int i=n-k;i<=n;++i)
                seg.lazy[1]^=(1<<i);
        }
        else if(tt==3)
        {
            cin>>k;
            seg.lazy[1]^=(1<<(n-k-1));
        }
        else
        {
            cin>>l>>r;
            cout<<seg.query(1,0,nx-1,l-1,r-1).sum<<"\n";
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
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}