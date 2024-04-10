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

const int N = 100005;

int n;
int a[N];
int last[N];


struct node
{
    ll sum,mi;
}fake{0,INF};
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
        ret.mi = min(a.mi,b.mi);
        return ret;
    }
    inline node make_node(ll val,ll val2)
    {
        node ret;
        ret.sum = val;
        ret.mi = val2;
        return ret;
    }
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            tree[v]=make_node(a[st],-1);
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    void update(ll v,ll st,ll en,ll in,ll val,ll val2)
    {
        ll mid=(st+en)>>1;
        if(st==en)
        {
            tree[v]=make_node(val,val2);
            a[st]=val;
            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in,val,val2);
        else
            update(v<<1 | 1,mid+1,en,in,val,val2);
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

vector<pair<int,int>> Q[N];
vector<int> occ[N];
int ans[N];
int diff[N],idx[N];

int _runtimeTerror_()
{
    cin>>n;
    for(int i=1;i<N;++i)
        last[i] = -1;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        diff[i] = 2e9,idx[i] = -1;
        seg.a[i]=0;
    }
    int q;
    cin>>q;
    for(int i=0;i<q;++i)
    {
        int l,r;
        cin>>l>>r;
        --l,--r;
        Q[r].pb({l,i});
    }
    for(int i=0;i<n;++i)
    {
        if(last[a[i]] == -1)
        {
            diff[i] = 2e9,idx[i] = -1;
            seg.update(1,0,n-1,i,1,-1);
            last[a[i]] = i;
        }
        else
        {
            seg.update(1,0,n-1,last[a[i]],0,2e9);
            int u = diff[last[a[i]]];
            int d = i-last[a[i]];
            if(u==2e9 || u==d)
                diff[i] = d,idx[i] = idx[last[a[i]]];
            else
            {
                int l = occ[a[i]].back();
                occ[a[i]].pop_back();
                int x = occ[a[i]].back();
                occ[a[i]].pb(l);
                diff[i] = d,idx[i] = x; 
            }
            seg.update(1,0,n-1,i,1,idx[i]);
            last[a[i]] = i;
        }
        for(auto &j : Q[i])
        {   
            node di = seg.query(1,0,n-1,j.F,i);
            int answ = di.sum;
            if(di.mi>=j.F)
                ++answ;
            ans[j.S] = answ;
        }
        occ[a[i]].pb(i);
    }
    for(int i=0;i<q;++i)
        cout<<ans[i]<<"\n";
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