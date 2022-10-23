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

const int N = 300005;
ll dp[N][21];
ll d[N],c[N];
ll logn[N];

struct node
{
    ll maximum,minimum;
}fake{-INF,INF};
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ mem0(a); }
    node tree[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.maximum=max(a.maximum,b.maximum);
        ret.minimum=min(a.minimum,b.minimum);
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        ret.maximum=ret.minimum=val;
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

ll ans = 0;

int query(int l,int r)
{
    int x = (1<<logn[r-l+1]);
    int xx = dp[l][logn[r-l+1]],yy = dp[r-x+1][logn[r-l+1]];
    return d[xx]>d[yy]?xx:yy;
}
int n;

void go_(int l,int r)
{
    if(l>r || l==r)
        return ;
    int x = query(l,r-1);
    node f = seg.query(1,0,n,x+1,r);
    node b = seg.query(1,0,n,l-1,x);
    amax(ans,f.maximum-b.minimum-d[x]);
    go_(l,x);
    go_(x+1,r);
}

int _runtimeTerror_()
{
    ll a;
    cin>>n>>a;
    for(int i=1;i<=n;++i)
    {
        cin>>d[i]>>seg.a[i];
        seg.a[i] = a-seg.a[i];
        amax(ans,seg.a[i]);
    }
    for(int i=1;i<=n;++i)
        d[i] = (d[i+1]-d[i])*(d[i+1]-d[i]);
    for(int i=1;i<=n;++i)
        seg.a[i] += seg.a[i-1];
    seg.buildTree(1,0,n);
    for(int len=0;len<=20;++len)
    {
        for(int i=1;i<n;++i)
        {
            logn[i] = log2(i);
            if(i+(1<<len)>n+1)
                continue;
            if(len == 0)
                dp[i][0] = i;
            else
            {
                ll x = dp[i][len-1],y = dp[i+(1<<(len-1))][len-1];
                dp[i][len] = d[x]>d[y]?x:y;
            }
        }
    }
    go_(1,n);
    cout << ans << "\n";
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