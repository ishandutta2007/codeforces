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

const int N=200005;


struct node
{
    ll sum;
    ll cnt;
}fake{0,0};
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
        ret.cnt=a.cnt+b.cnt;
        return ret;
    }
    inline node make_node(ll val,ll x)
    {
        node ret;
        ret.sum=val;
        ret.cnt=x;
        return ret;
    }
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            tree[v]=make_node(a[st],0);
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    void update(ll v,ll st,ll en,ll in,ll val,ll x)
    {
        ll mid=(st+en)>>1;
        if(st==en)
        {
            tree[v]=make_node(val,x);
            a[st]=val;
            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in,val,x);
        else
            update(v<<1 | 1,mid+1,en,in,val,x);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    ll query(ll v,ll st,ll en,int x)
    {
        if(x==0)
            return 0ll;
        if(tree[v].cnt<=x)
            return tree[v].sum;
        int mid=(st+en)/2;
        if(st==en)
            return tree[v].sum;
        if(tree[v<<1|1].cnt>=x)
            return query(v<<1|1,mid+1,en,x);
        return query(v<<1,st,mid,x-tree[v<<1|1].cnt)+tree[v<<1|1].sum;
    }
}seg;

map<ll,ll> idx;

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<pll> q(n);
    set<ll> s;
    for(int i=0;i<n;++i)
    {
        cin>>q[i].F>>q[i].S;
        s.insert(abs(q[i].S));
    }
    int x=0;
    for(auto j:s)
    {
        //cout<<j<<" ";
        idx[j]=x++;
    }
    //cout<<"\n";
    for(int i=0;i<x;++i)
        seg.a[i]=0;
    seg.buildTree(1,0,x-1);
    ll sum=0;
    set<ll> xx,yy;
    for(int i=0;i<n;++i)
    {
        if(q[i].F==0)
        {
            if(q[i].S>0)
                xx.insert(q[i].S),sum+=q[i].S;
            else 
                xx.erase(-q[i].S),sum+=q[i].S;
            seg.update(1,0,x-1,idx[abs(q[i].S)],q[i].S>0?q[i].S:0,q[i].S>0?1:0);
        }
        else
        {
            ll val=-1;
            if(!yy.empty())
                val=*yy.begin();
            if(q[i].S>0)
            {
                sum+=q[i].S;
                yy.insert(q[i].S);
                ll v2=*yy.begin();
                if(abs(q[i].S)==v2)
                {
                    q[i].S=val;
                    //seg.update(1,0,x-1,idx[abs(q[i].S)],q[i].S>0?q[i].S:0,q[i].S>0?1:-1);
                }
                if(sz(yy)>1)
                    seg.update(1,0,x-1,idx[abs(q[i].S)],q[i].S>0?q[i].S:0,q[i].S>0?1:0);
            }
            else 
            {
                sum+=q[i].S;
                yy.erase(-q[i].S);
                if(val==-q[i].S && !yy.empty())
                {
                    q[i].S=-*yy.begin();
                }
                if(!yy.empty())
                    seg.update(1,0,x-1,idx[abs(q[i].S)],q[i].S>0?q[i].S:0,q[i].S>0?1:0);
            }
            //seg.update(1,0,x-1,idx[abs(q[i].S)],q[i].S>0?q[i].S:0,q[i].S>0?1:0);      
        }
        //cout<<"sz "<<sz(yy)<<"\n";
        ll cx=seg.query(1,0,x-1,sz(yy));
        cout<<cx+sum<<"\n";
        //cout<<sum<<"\n";
        //cout<<ans<<"\n";
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