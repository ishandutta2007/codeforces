#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>


using namespace std;

const long double PI = 4 * atan((long double) 1);

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;
typedef complex<ld> cd;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vd;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

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

const ll MOD = 1e9 + 7;


const int MAX = 100500;
const int ALPH = 26;
vi adj[MAX];
int trie[MAX][ALPH];
bool good[MAX];
int depth[MAX];
int parent[MAX];
int szT = 0;
int newT() {
    return ++szT;
}
int root;
void insert(const string& s) {
    int v = root;
    for (int i = 0; i < s.length(); i++) {
        int c = s[i] - 'a';
        if (trie[v][c] == 0){
            trie[v][c] = newT();
        }
        v = trie[v][c];
    }
    good[v] = true;
}
void dfs_parent(int src, int par){
    parent[src] = par;
    for(int nxt: adj[src]){
        if(nxt == par) continue;
        dfs_parent(nxt, src);
    }
}
void dfs_depth(int src, int par){
    for(int nxt: adj[src]){
        if(nxt == par){
            continue;
        }
        depth[nxt] = depth[src] + 1;
        dfs_depth(nxt, src);
    }
}
inline int isLeaf(int x){
    if(x == 1) return 0;
    if(sz(adj[x]) == 1) return 1;
    return 0;
}



multiset<int>* merge(multiset<int>* a, multiset<int>*b){
    if(a->size()<b->size()) swap(a, b);
    for(auto x: *b) a->insert(x);
    delete b;
    return a;
}

multiset<int>* solve(int src, int par){
    multiset<int>* ret = new multiset<int>;
   // ps(adj[src]);
    for(int nxt: adj[src]){
        if(nxt == par) continue;
        auto use = solve(nxt, src);
       // ps(ret->size(), use->size());
        ret = merge(ret, use);
       // ps(ret->size(), "HUH");
    }
   // ps(src, "STUCK", isLeaf(src));
    if(good[src]){
        ret->insert(depth[src]);
    }
    else if(depth[src] != 0){
        ret->erase(prev(ret->end()));
        ret->insert(depth[src]);
    }
    if(isLeaf(src)) assert(ret->size() == 1);
    return ret;

}
int main() {
    root = newT();
    int n;
    re(n);
    f0r(i, n){
        string line;
        re(line);
        insert(line);
    }

    f0r(i, MAX){
        f0r(j, ALPH){
            if(trie[i][j]){
                adj[i].eb(trie[i][j]);
                adj[trie[i][j]].eb(i);
            }
        }
    }
    dfs_parent(root, -1);
    dfs_depth(root, -1);
    solve(root, -1);
    auto ans = solve(root, -1);
    int res = 0;
    for(auto x: *ans) res += x;
    ps(res);
    return 0;
}