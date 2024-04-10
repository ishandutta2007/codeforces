#include<bits/stdc++.h>
using namespace std ;

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

const int N = 200005;

struct node
{
    int val[10];
    int ans ;
    node() {
        for(int i=0;i<10;++i)
            val[i] = 2e9;
        ans = 2e9;
    }
}fake;
node ans ;
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ mem0(a); }
    node tree[4*N];
    inline void combine(node &u,node &a,node &b)
    {
        u = node();
        for(int j=0;j<10;++j)
        {
            u.val[j] = min(a.val[j],b.val[j]);
            if(a.val[j]<2e9 && b.val[j]<2e9)
                amin(u.ans,a.val[j]+b.val[j]);
        }
        amin(u.ans,a.ans);
        amin(u.ans,b.ans);
    }
    inline void make_node(int u,ll val)
    {
        int l = val;
        tree[u] = node();
        for(int j=0;j<10;++j)
        {
            if(l%10)
                tree[u].val[j]=val;
            l/=10;
        }
    }
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            make_node(v,a[st]);
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        combine(tree[v],tree[v<<1],tree[v<<1 | 1]);
    }
    void update(ll v,ll st,ll en,ll in,ll val)
    {
        ll mid=(st+en)>>1;
        if(st==en)
        {
            make_node(v,val);
            a[st]=val;
            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in,val);
        else
            update(v<<1 | 1,mid+1,en,in,val);
        combine(tree[v],tree[v<<1],tree[v<<1 | 1]);
    }
    void query(ll v,ll st,ll en,ll l,ll r)
    {
        if(en<l || st>r)
            return ;
        if(st>=l && en<=r)
        {
            node x;
            combine(x,ans,tree[v]);
            ans = x;
            return ;
        }
        ll mid=(st+en)>>1;
        query(v<<1,st,mid,l,r);
        query(v<<1 | 1,mid+1,en,l,r);
    }
}seg;

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;++i)
        cin>>seg.a[i];
    seg.buildTree(1,0,n-1);
    for(int i=1;i<=m;++i)
    {
        int tt,l,r;
        cin>>tt>>l>>r;
        if(tt==1)
        {
            seg.update(1,0,n-1,l-1,r);
        }
        else
        {
            ans = node();
            seg.query(1,0,n-1,l-1,r-1);
            int answ = ans.ans;
            cout << (answ==2e9?-1:answ) << "\n";
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