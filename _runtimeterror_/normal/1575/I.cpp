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

const int N = 100005;

struct node
{
    ll sum;
}fake={0};
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    node tree[4*N];
    ll lazy[4*N];
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
        tree[v].sum+=(en-st+1)*lazy[v];
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
    node query(ll v,ll st,ll en,ll l,ll r)
    {
        if(en<l || st>r)
            return fake;
        if(lazy[v]!=0)
        {
            pushdown(v,st,en);
        }
        if(st>=l && en<=r)
            return tree[v];
        ll mid=(st+en)>>1;
        return combine(query(v<<1,st,mid,l,r),query(v<<1 | 1,mid+1,en,l,r));
    }
}seg;

vector<int> v[N];
int sub[N],dep[N],par[N];

void dfs_size(int s=1,int p=-1)
{
    sub[s]=1;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dep[j]=dep[s]+1;
            par[j]=s;
            dfs_size(j,s);
            sub[s]+=sub[j];
        }
    }
}

int head[N],pos[N],in[N],out[N],cur=0;
void hld(int s,int p,int h)
{
    head[s]=h;
    int hv=-1,mx=-1;
    pos[s]=cur++;
    //seg.a[pos[s]]=val[s];
    in[s]=pos[s];
    for(auto j:v[s])
        if(j!=p)
            if(sub[j]>mx)
                mx=sub[j],hv=j;

    if(hv!=-1)
        hld(hv,s,h);
    for(auto j:v[s])
        if(j!=p && j!=hv)
            hld(j,s,j);
    out[s]=cur-1;
}

ll query(int a, int b,int n) {
    ll ans = 0;
    for (; head[a] != head[b]; b = par[head[b]]) {
        if (dep[head[a]] > dep[head[b]])
            swap(a, b);
        ans += seg.query(1,0,n-1,pos[head[b]],pos[b]).sum;
    }
    if (dep[a] > dep[b])
        swap(a, b);
    ans += seg.query(1,0,n-1,pos[a],pos[b]).sum;
    return ans;
}

int _runtimeTerror_()
{
    int n, Q;
    cin >> n >> Q;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }
    for(int i=1;i<=n-1;++i) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y), v[y].push_back(x);
    }
    dfs_size(1,0);
    hld(1,0,1);
    for(int i=1;i<=n;++i) {
        seg.a[pos[i]] = a[i];
    }
    seg.buildTree(1,0,n-1);
    for(int i=1;i<=Q;++i) {
        int tt, u, x;
        cin >> tt >> u >> x;
        if(tt == 1) {
            x = abs(x);
            seg.update(1,0,n-1,pos[u],x);
            a[u] = x;
        }
        else {
            cout << 2 * query(u,x,n) - a[u] - a[x] << "\n";
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