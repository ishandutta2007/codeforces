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

int n;
string s;
const int N=1000005;
int a[N],one[N],zero[N];


struct node
{
    ll sum;
}fake;
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ mem0(a); }
    node tree[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.sum=max(a.sum,b.sum);
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        ret.sum=val;
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
    ll query(ll v,ll st,ll en,ll l,ll x)
    {
        if(tree[v].sum<x)
            return n+1;
        if(st==en)
            return st;
        ll mid=(st+en)/2;
        ll val = n+1;
        if(l<=mid && tree[v<<1].sum>=x)
            val = query(v<<1,st,mid,l,x);
        if(val!=n+1)
            return val;
        return query(v<<1|1,mid+1,en,l,x);
    }
}seg;

int _runtimeTerror_()
{
    cin>>n>>s;
    for(int i=1;i<=n;++i)
    {
        one[i]=one[i-1]+(s[i-1]=='1');
        zero[i]=zero[i-1]+(s[i-1]=='0');
    }
    for(int i=1;i<=n;++i)
    {
        ll lo=1,hi=n-i+1;
        ll ans=1;
        while(lo<=hi)
        {
            ll mid=(lo+hi)/2;
            if(one[i+mid-1]-one[i-1]==0 || zero[i+mid-1]-zero[i-1]==0)
                lo=mid+1,ans=mid;
            else
                hi=mid-1;
        }
        seg.a[i]=ans;
    }
    seg.buildTree(1,1,n);
    for(int i=1;i<=n;++i)
    {
        ll cur=1;
        ll ans=0;
        while(cur<=n)
        {
            ll x=seg.query(1,1,n,cur,i);
            if(x==n+1)
                break;
            ++ans;
            cur=x+i;

        }
        cout<<ans<<" ";
    }
    return 0;
}

int main()
{
    //freopen("outer","r",stdin);
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