//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
 
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
 
const long double PI = 4 * atan((long double) 1);
 
typedef long long ll;
typedef long double ld;
typedef double db;
 
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

 
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define f0r(i,a) for(int i=0;i<a;i++)
#define f1r(i,a,b) for(int i=a;i<b;i++)
#define trav(a, x) for (auto& a : x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
 
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define rall(x) rbegin(x), rend(x)
#define resz resize
#define ins insert
 
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.f << ", " << p.s << ")"; }
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
  cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
 
template<class T> bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }
 
namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);
 
	template<class T> void re(T& x) { cin >> x; }
	void re(double& x) { string t; re(t); x = stod(t); }
	void re(ld& x) { string t; re(t); x = stold(t); }
	template<class T, class... Ts> void re(T& t, Ts&... ts) {
		re(t); re(ts...);
	}
 
	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
	template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.f,p.s); }
	template<class T> void re(vector<T>& a) { F0R(i,sz(a)) re(a[i]); }
	template<class T, size_t SZ> void re(array<T,SZ>& a) { F0R(i,SZ) re(a[i]); }
}
 
using namespace input;
 
namespace output {
	void pr(int x) { cout << x; }
	void pr(long x) { cout << x; }
	void pr(ll x) { cout << x; }
	void pr(unsigned x) { cout << x; }
	void pr(unsigned long x) { cout << x; }
	void pr(unsigned long long x) { cout << x; }
	void pr(float x) { cout << x; }
	void pr(double x) { cout << x; }
	void pr(ld x) { cout << x; }
	void pr(char x) { cout << x; }
	void pr(const char* x) { cout << x; }
	void pr(const string& x) { cout << x; }
	void pr(bool x) { pr(x ? "true" : "false"); }
	template<class T> void pr(const complex<T>& x) { cout << x; }
 
	template<class T1, class T2> void pr(const pair<T1,T2>& x);
	template<class T> void pr(const T& x);
 
	template<class T, class... Ts> void pr(const T& t, const Ts&... ts) {
		pr(t); pr(ts...);
	}
	template<class T1, class T2> void pr(const pair<T1,T2>& x) {
		pr("{",x.f,", ",x.s,"}");
	}
	template<class T> void pr(const T& x) {
		pr("{"); // const iterator needed for vector<bool>
		bool fst = 1; for (const auto& a: x) pr(!fst?", ":"",a), fst = 0;
		pr("}");
	}
 
	void ps() { pr("\n"); } // print w/ spaces
	template<class T, class... Ts> void ps(const T& t, const Ts&... ts) {
		pr(t); if (sizeof...(ts)) pr(" "); ps(ts...);
	}
 
	void pc() { pr("]\n"); } // debug w/ commas
	template<class T, class... Ts> void pc(const T& t, const Ts&... ts) {
		pr(t); if (sizeof...(ts)) pr(", "); pc(ts...);
	}
	#define dbg(x...) pr("[",#x,"] = ["), pc(x);
}
 
using namespace output;
 
namespace io {
	void setIn(string s) { freopen(s.c_str(),"r",stdin); }
	void setOut(string s) { freopen(s.c_str(),"w",stdout); }
	void setIO(string s = "") {
		cin.sync_with_stdio(0); cin.tie(0); // fast I/O
		// cin.exceptions(cin.failbit); // ex. throws exception when you try to read letter into int
		if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
	}
}
 
using namespace io;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

const int INF = 1e9 + 7;

template<class T, int SZ> struct MaxSegTree {
    T mx[2*SZ], lazy[2*SZ]; // set SZ to a power of 2
    MaxSegTree() {
        //memset (sum,0,sizeof sum);
        f0r(i, 2*SZ) lazy[i] = 0;
        f0r(i, 2*SZ) mx[i] = 0;
    }
 
    void push(int ind, int L, int R) {
      //  sum[ind] += (R-L+1)*lazy[ind];
        //mn[ind] += lazy[ind];
     //   ckmin(mn[ind], lazy[ind]);
        ckmax(mx[ind], lazy[ind]);
        if (L != R) {
			ckmax(lazy[2*ind+1], lazy[ind]);
			ckmax(lazy[2*ind], lazy[ind]);
		}
        lazy[ind] = 0;
    }
 
    void pull(int ind) {
       // sum[ind] = sum[2*ind]+sum[2*ind+1];
        mx[ind] = max(mx[2*ind], mx[2*ind+1]);
    }
    T qmax(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return 0;
        if (lo <= L && R <= hi) return mx[ind];
 
        int M = (L+R)/2;
        //return qsum(lo,hi,2*ind,L,M) + qsum(lo,hi,2*ind+1,M+1,R);
        return max(qmax(lo, hi, 2*ind, L, M), qmax(lo, hi, 2*ind+1,M+1, R));
    }
 
    void upd(int lo, int hi, long long inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind,L,R);
            return;
        }
 
        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
};
 
template<class T, int SZ> struct MinSegTree {
    T mn[2*SZ], lazy[2*SZ]; // set SZ to a power of 2
    MinSegTree() {
        //memset (sum,0,sizeof sum);
        f0r(i, 2*SZ) lazy[i] = INF;
        f0r(i, 2*SZ) mn[i] = INF;
    }
 
    void push(int ind, int L, int R) {
      //  sum[ind] += (R-L+1)*lazy[ind];
        //mn[ind] += lazy[ind];
        ckmin(mn[ind], lazy[ind]);
        if (L != R) {
			ckmin(lazy[2*ind+1], lazy[ind]);
			ckmin(lazy[2*ind], lazy[ind]);
		}
        lazy[ind] = INF;
    }
 
    void pull(int ind) {
       // sum[ind] = sum[2*ind]+sum[2*ind+1];
        mn[ind] = min(mn[2*ind], mn[2*ind+1]);
    }
    T qmin(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (lo > R || L > hi) return INF;
        if (lo <= L && R <= hi) return mn[ind];
 
        int M = (L+R)/2;
        //return qsum(lo,hi,2*ind,L,M) + qsum(lo,hi,2*ind+1,M+1,R);
        return min(qmin(lo, hi, 2*ind, L, M), qmin(lo, hi, 2*ind+1,M+1, R));
    }
 
    void upd(int lo, int hi, long long inc, int ind = 1, int L = 0, int R = SZ-1) {
        push(ind,L,R);
        if (hi < L || R < lo) return;
        if (lo <= L && R <= hi) {
            lazy[ind] = inc;
            push(ind,L,R);
            return;
        }
 
        int M = (L+R)/2;
        upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
        pull(ind);
    }
};
 
const bool VALUES_IN_VERTICES =  false;
template <class T, int V>
class HeavyLightMin {
  int parent[V], heavy[V], depth1[V];
  int root[V], treePos[V];
  MinSegTree<T, V> tree;
 
  template <class G>
  int dfs(const G& graph, int v) {
    int size = 1, maxSubtree = 0;
    for (int u : graph[v]) if (u != parent[v]) {
      parent[u] = v;
      depth1[u] = depth1[v] + 1;
      int subtree = dfs(graph, u);
      if (subtree > maxSubtree) heavy[v] = u, maxSubtree = subtree;
      size += subtree;
    }
    return size;
  }
 
  template <class BinaryOperation>
  void processPath(int u, int v, BinaryOperation op) {
    for (; root[u] != root[v]; v = parent[root[v]]) {
      if (depth1[root[u]] > depth1[root[v]]) swap(u, v);
      op(treePos[root[v]], treePos[v]);
    }
    if (depth1[u] > depth1[v]) swap(u, v);
    //op(treePos[u], treePos[v] + 1);
    op(treePos[u] + (VALUES_IN_VERTICES ? 0 : 1), treePos[v]);
  }
 
public:
  template <class G>
  void init(const G& graph) {
    int n = graph.size();
    fill_n(heavy, n, -1);
    parent[0] = -1;
    depth1[0] = 0;
    dfs(graph, 0);
    for (int i = 0, currentPos = 0; i < n; ++i)
      if (parent[i] == -1 || heavy[parent[i]] != i)
        for (int j = i; j != -1; j = heavy[j]) {
          root[j] = i;
          treePos[j] = currentPos++;
        }
//    tree.build();
  }
 
  void modifyPath(int u, int v, const T& value) {
    processPath(u, v, [this, &value](int l, int r) { tree.upd(l, r, value); });
  }
 
  ll queryPath(int u, int v) {
    ll res = INF;
    processPath(u, v, [this, &res](int l, int r) { ckmin(res, (tree.qmin(l, r))); });
    return res;
  }
};\
template <class T, int V>
class HeavyLightMax {
  int parent[V], heavy[V], depth1[V];
  int root[V], treePos[V];
  MaxSegTree<T, V> tree;
 
  template <class G>
  int dfs(const G& graph, int v) {
    int size = 1, maxSubtree = 0;
    for (int u : graph[v]) if (u != parent[v]) {
      parent[u] = v;
      depth1[u] = depth1[v] + 1;
      int subtree = dfs(graph, u);
      if (subtree > maxSubtree) heavy[v] = u, maxSubtree = subtree;
      size += subtree;
    }
    return size;
  }
 
  template <class BinaryOperation>
  void processPath(int u, int v, BinaryOperation op) {
    for (; root[u] != root[v]; v = parent[root[v]]) {
      if (depth1[root[u]] > depth1[root[v]]) swap(u, v);
      op(treePos[root[v]], treePos[v]);
    }
    if (depth1[u] > depth1[v]) swap(u, v);
    //op(treePos[u], treePos[v] + 1);
    op(treePos[u] + (VALUES_IN_VERTICES ? 0 : 1), treePos[v]);
  }
 
public:
  template <class G>
  void init(const G& graph) {
    int n = graph.size();
    fill_n(heavy, n, -1);
    parent[0] = -1;
    depth1[0] = 0;
    dfs(graph, 0);
    for (int i = 0, currentPos = 0; i < n; ++i)
      if (parent[i] == -1 || heavy[parent[i]] != i)
        for (int j = i; j != -1; j = heavy[j]) {
          root[j] = i;
          treePos[j] = currentPos++;
        }
//    tree.build();
  }
 
  void modifyPath(int u, int v, const T& value) {
    processPath(u, v, [this, &value](int l, int r) { tree.upd(l, r, value); });
  }
 
  ll queryPath(int u, int v) {
    ll res = 0;
    processPath(u, v, [this, &res](int l, int r) { ckmax(res, (tree.qmax(l, r))); });
    return res;
  }
};
HeavyLightMin<ll, (1<<18)> h1;
HeavyLightMax<ll, (1<<18)> h2;
const int MAX = 2e5 + 5;
const int LOG = 20;
vector<array<int, 3>> bad;
map<pi, int> num;
map<pair<int, int>, int> map1;
vector<vi> hgraph;
vector<array<int, 3>> edges;
vector<array<int, 3>> t;

int n,m;

template<int SZ> struct DSU{
    int par[SZ], sz[SZ];
    DSU(){
        for(int i = 0; i<SZ; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }
    int get(int x){
        if(par[x] != x){
            par[x] = get(par[x]);
        }
        return par[x];
    }
    bool unite(int x, int y){
        x = get(x);
        y = get(y);
        if(x == y){
            return false;
        }
        if(sz[x] < sz[y]){
            swap(x, y);
        }
        sz[x] += sz[y];
        par[y] = x;
        return true;
    }
};
//weight, start, end

long long kruskal(vector<array<int,3>> edge) {
    DSU<MAX> D;
    sort(edge.begin(), edge.end());
    long long ans = 0;
    for (auto a: edge){
        if (D.unite(a[1],a[2])){
            ans += a[0]; //edge in MST
            array<int, 3> arr = {a[1], a[2], a[0]};
            t.eb(arr);
        }
    }
    return ans;
}

pi conv(int a, int b){
	if(a>b) return mp(b, a);
	return mp(a, b);
}
int ans [MAX];
int main(){
	re(n, m);
	hgraph.resz(n);
	f0r(i, m){
		int u, v, c;
		re(u,v, c);
		u--;
		v--;
		array<int, 3> arr = {c, u, v};
		num[conv(u, v)] = i;
		edges.eb(arr);
		
	}
	kruskal(edges);
	//return 0;
	for(auto x: t) map1[conv(x[0], x[1])]++;
	for(auto x: t){
		hgraph[x[0]].eb(x[1]);
		hgraph[x[1]].eb(x[0]);
	}
	for(auto x: edges){
		if(map1.find(conv(x[1], x[2])) == map1.end()){
			array<int, 3> arr = {x[1], x[2], x[0]};
			bad.eb(arr);
		}
	}
	h1.init(hgraph);
	h2.init(hgraph);
	for(auto e: bad){
		h1.modifyPath(e[0], e[1], e[2]);
	}
	for(auto e: t){
		h2.modifyPath(e[0], e[1], e[2]);
	}
	for(auto e: bad){
		int val = h2.queryPath(e[0], e[1]);
		ans[num[conv(e[0], e[1])]] = val - 1;
	}
	for(auto e: t){
		int val = h1.queryPath(e[0], e[1]);
		if(val == INF){
			ans[num[conv(e[0], e[1])]] = -1;
		}
		else{
			ans[num[conv(e[0], e[1])]] = val-1;
		}
	}
	f0r(i, m) pr(ans[i],  " " );
	ps();
	

	return 0;
}