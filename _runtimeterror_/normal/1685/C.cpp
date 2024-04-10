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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y < x) x = y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x < y) x = y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 3000
#endif

const int N = 3e5 + 5;
struct node
{
    ll sum;
}fake{INF};
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
        ret.sum=min(a.sum,b.sum);
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
        lazy[v] = 0;
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

int _runtimeTerror_()
{
    int n;
    cin >> n;
    n *= 2;
    string s;
    cin >> s;
    {
        int cur = 0;
        int good = 1;
        for(int i=0;i<n;++i) {
            cur += s[i] == '(' ? 1 : -1;
            if(cur < 0) {
                good = 0;
            }
        }
        if(good) {
            cout << "0\n";
            return 0;
        }
    }
    {
        int farthest = -1;
        int cur = 0, mx = 0;
        for(int i=0;i<n;++i) {
            cur += s[i] == '(' ? 1 : -1;
            if(cur < 0) {
                break;
            }
            if(cur >= mx) {
                farthest = i;
                mx = cur;
            }
        }
        vector<int> suf(n + 1, 0);
        for(int i=0;i<=n;++i) {
            seg.a[i] = 0;
        }
        seg.buildTree(1, 0, n);
        for(int i=n-1;i>=0;--i) {
            seg.rupdate(1, 0, n, i, n, s[i] == '(' ? 1: -1);
            suf[i] = seg.query(1, 0, n, 0, n).sum;
        }
        for(int i=0;i<=n;++i) {
            seg.a[i] = 0;
        }
        seg.buildTree(1, 0, n);
        vector<int> pref(n + 1, 0);
        cur = 0;
        debug(farthest);
        for(int i=0;i<n;++i) {
            cur += s[i] == '(' ? 1: -1;
            seg.rupdate(1, 0, n, 0, i, s[i] == '(' ? 1: -1);
            pref[i] = seg.query(1, 0, n, 0, n).sum;
            if(i > farthest) {
                auto u = seg.query(1, 0, n, farthest + 1, i).sum;
                if(u + mx >= 0 and cur + suf[i + 1] >= 0) {
                    cout << "1\n";
                    cout << farthest + 2 << " " << i + 1 << "\n";
                    return 0;
                }
            }
        }
    }
    {
        for(int i=0;i<n;++i) {
            if(s[i] == '(') {
                continue;
            }
            int j = i, cur = 0;
            while(j < n) {
                cur += s[j] == ')' ? 1 : -1;
                if(cur == 0) {
                    break;
                }
                ++j;
            }
            if(cur != 0) {
                cout << "2\n";
                cout << 1 << " " << i << "\n";
                cout << i + 1 << " " << n << "\n";
                return 0;
            }
            i = j;
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
        initncr();
    #endif
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--) {
        _runtimeTerror_();
    }
    return 0;
}