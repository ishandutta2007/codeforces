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

const int N = (1<<19);
string s;

map<pair<int,int>,char> mp;
struct node
{
    ll sum = 0;
}fake;
struct SEGTREE
{
    SEGTREE(){ }
    node tree[4*N];
    inline node combine(node a,node b,char c)
    {
        node ret;
        if(c == '?')
            ret.sum = a.sum + b.sum;
        else if(c == '0')
            ret.sum = a.sum;
        else
            ret.sum = b.sum;
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
            tree[v]=make_node(1);
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        char c = mp[{st,en}];
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1],c);
        // debug(st,en,tree[v].sum);
    }
    void update(ll v,ll st,ll en,int l,int r)
    {
        if(st == l && en == r)
        {
            tree[v] = combine(tree[v<<1],tree[v<<1 | 1],mp[{l,r}]);
            // debug(l,r,tree[v].sum);
            return ;
        }
        ll mid=(st+en)>>1;
        if(r<=mid)
            update(v<<1,st,mid,l,r);
        else
            update(v<<1 | 1,mid+1,en,l,r);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1],mp[{st,en}]);
    }
}seg;


int _runtimeTerror_()
{
    int k;
    cin>>k;
    string s;
    cin>>s;
    int n = (1<<k);
    vector<pii> range(n+1);
    vector<pii> cur;
    for(int i=1;i<=n;i+=2)
        cur.push_back({i,i+1});
    int pt = 0;
    while(true)
    {
        for(int i=0;i<sz(cur);++i)
        {
            range[pt+i] = cur[i];
        }
        pt += sz(cur);
        if(sz(cur) == 1)
            break;
        vector<pii> tmp;
        for(int i=0;i<sz(cur);i+=2)
        {
            tmp.push_back({cur[i].F,cur[i+1].S});
        }
        cur = tmp;
    }
    for(int i=0;i<sz(s);++i)
    {
        mp[{range[i]}] = s[i];
    }
    // debug(range);
    int Q;
    cin>>Q;
    seg.buildTree(1,1,n);
    while(Q--)
    {
        int p;
        char c;
        cin>>p>>c;
        --p;
        mp[{range[p]}] = c;
        // debug(range[p]);
        seg.update(1,1,n,range[p].F,range[p].S);
        cout<<seg.tree[1].sum<<"\n";
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