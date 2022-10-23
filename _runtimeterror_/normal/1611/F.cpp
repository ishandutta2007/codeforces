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
#define debug(...) 2401
#endif

const int N = 200005;
struct node
{
	ll sum;
}fake={INF};
	// base value is assigned to fake node
struct SEGTREE
{
	ll a[N];
	SEGTREE(){ }
	node tree[4*N];
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
	int query(ll v,ll st,ll en,ll l,ll val)
	{
		if(en < l) {
			return -1;
		}
		if(st == en) {
			return st;
		}
		ll mid=(st+en)>>1;
		int u = -1;
		if(tree[v << 1].sum < val) {
			u = query(v << 1, st, mid, l, val);
		}
		if(u != -1) {
			return u;
		}
		return query(v << 1 | 1, mid + 1, en, l, val);
	}
}seg;

int _runtimeTerror_()
{
    int n;
    ll s;
    cin >> n >> s;
    vector<ll> a(n+2,0);
    for(int i=1;i<=n;++i) {
    	cin >> a[i];
    	a[i] += a[i-1];
    }
    a[n+1] = -INF;
    for(int i=1;i<=n+1;++i) {
    	seg.a[i] = a[i];
    }
    seg.buildTree(1, 1, n+1);
    int len = -1, first = -1, last = -1;
    
    for(int i=0;i<=n;++i) {
    	int id = seg.query(1,1,n+1,i+1,a[i] - s);
    	if(id != i + 1) {
    		if(len < id - i - 1) {
    			len = id - i - 1;
    			first = i + 1;
    			last = id - 1;
    		}
    	}
    }
    if(len == -1) {
    	cout << "-1\n";
    }
    else {
    	cout << first << " " << last << "\n";
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
    cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}