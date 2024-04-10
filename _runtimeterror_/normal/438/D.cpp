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

vector<int> upd;

const int N=100005;
struct node
{
    ll sum;
    ll mx;
}fake={0};
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ mem0(a); }
    node tree[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.sum=a.sum+b.sum;
        ret.mx=max(a.mx,b.mx);
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        ret.sum=val;
        ret.mx=val;
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
    void descend(int v,int st,int en,int l,int r,int x)
    {
        if(en<l || st>r)
            return ;
        if(st==en)
        {
            upd.pb(st);return ;
        }
        int mid=(st+en)>>1;
        if(tree[v<<1].mx>=x)
            descend(v<<1,st,mid,l,r,x);
        if(tree[v<<1|1].mx>=x)
            descend(v<<1|1,mid+1,en,l,r,x);
    }
}seg;

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>seg.a[i];
    seg.buildTree(1,0,n-1);
    while(m--)
    {
        int tt,l,r,k,x;
        cin>>tt;
        if(tt==1)
        {
            cin>>l>>r;
            cout<<seg.query(1,0,n-1,l-1,r-1).sum<<"\n";
        }
        else if(tt==2)
        {
            upd.clear();
            cin>>l>>r>>x;
            seg.descend(1,0,n-1,l-1,r-1,x);
            for(int j:upd)
                seg.update(1,0,n-1,j,seg.a[j]%x);
        }
        else if(tt==3)
        {
            cin>>k>>x;
            seg.update(1,0,n-1,k-1,x);
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