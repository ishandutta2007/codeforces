#define NDEBUG
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str; 
 
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef pair<db,db> pd; 
 
typedef vector<int> vi; 
typedef vector<ll> vl; 
typedef vector<db> vd; 
typedef vector<str> vs; 
typedef vector<pi> vpi;
typedef vector<pl> vpl; 
typedef vector<pd> vpd; 
 
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend() 
#define rsz resize
#define ins insert 
#define ft front() 
#define bk back()
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define lb lower_bound 
#define ub upper_bound 
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
const int MOD = 1e9+7; // 998244353;
const int MX = 2e5+5; 
const ll INF = 1e18; 
const ld PI = acos((ld)-1);
const int xd[4] = {1,0,-1,0}, yd[4] = {0,1,0,-1}; 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
 
template<class T> bool ckmin(T& a, const T& b) { 
	return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { 
	return a < b ? a = b, 1 : 0; } 
constexpr int pct(int x) { return __builtin_popcount(x); } 
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
ll half(ll x) { return fdiv(x,2); }
 
template<class T, class U> T fstTrue(T lo, T hi, U f) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true 
		T mid = half(lo+hi);
		f(mid) ? hi = mid : lo = mid+1; 
	} 
	return lo;
}
template<class T, class U> T lstTrue(T lo, T hi, U f) {
	lo --; assert(lo <= hi); // assuming f is decreasing
	while (lo < hi) { // find first index such that f is true 
		T mid = half(lo+hi+1);
		f(mid) ? lo = mid : hi = mid-1;
	} 
	return lo;
}
template<class T> void remDup(vector<T>& v) { 
	sort(all(v)); v.erase(unique(all(v)),end(v)); }
 
// INPUT
template<class A> void re(complex<A>& c);
template<class A, class B> void re(pair<A,B>& p);
template<class A> void re(vector<A>& v);
template<class A, size_t SZ> void re(array<A,SZ>& a);
 
template<class T> void re(T& x) { cin >> x; }
void re(db& d) { str t; re(t); d = stod(t); }
void re(ld& d) { str t; re(t); d = stold(t); }
template<class H, class... T> void re(H& h, T&... t) { re(h); re(t...); }
 
template<class A> void re(complex<A>& c) { A a,b; re(a,b); c = {a,b}; }
template<class A, class B> void re(pair<A,B>& p) { re(p.f,p.s); }
template<class A> void re(vector<A>& x) { trav(a,x) re(a); }
template<class A, size_t SZ> void re(array<A,SZ>& x) { trav(a,x) re(a); }
 
// TO_STRING
#define ts to_string
str ts(char c) { return str(1,c); }
str ts(const char* s) { return (str)s; }
str ts(str s) { return s; }
str ts(bool b) { 
	#ifdef LOCAL
		return b ? "true" : "false"; 
	#else 
		return ts((int)b);
	#endif
}
template<class A> str ts(complex<A> c) { 
	stringstream ss; ss << c; return ss.str(); }
str ts(vector<bool> v) {
	str res = "{"; F0R(i,sz(v)) res += char('0'+v[i]);
	res += "}"; return res; }
template<size_t SZ> str ts(bitset<SZ> b) {
	str res = ""; F0R(i,SZ) res += char('0'+b[i]);
	return res; }
template<class A, class B> str ts(pair<A,B> p);
template<class T> str ts(T v) { // containers with begin(), end()
	#ifdef LOCAL
		bool fst = 1; str res = "{";
		for (const auto& x: v) {
			if (!fst) res += ", ";
			fst = 0; res += ts(x);
		}
		res += "}"; return res;
	#else
		bool fst = 1; str res = "";
		for (const auto& x: v) {
			if (!fst) res += " ";
			fst = 0; res += ts(x);
		}
		return res;
 
	#endif
}
template<class A, class B> str ts(pair<A,B> p) {
	#ifdef LOCAL
		return "("+ts(p.f)+", "+ts(p.s)+")"; 
	#else
		return ts(p.f)+" "+ts(p.s);
	#endif
}
 
// OUTPUT
template<class A> void pr(A x) { cout << ts(x); }
template<class H, class... T> void pr(const H& h, const T&... t) { 
	pr(h); pr(t...); }
void ps() { pr("\n"); } // print w/ spaces
template<class H, class... T> void ps(const H& h, const T&... t) { 
	pr(h); if (sizeof...(t)) pr(" "); ps(t...); }
 
// DEBUG
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) {
	cerr << ts(h); if (sizeof...(t)) cerr << ", ";
	DBG(t...); }
#ifdef LOCAL // compile with -DLOCAL
	#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
	#define dbg(...) 0
#endif
 
// FILE I/O
void setIn(str s) { freopen(s.c_str(),"r",stdin); }
void setOut(str s) { freopen(s.c_str(),"w",stdout); }
void unsyncIO() { ios_base::sync_with_stdio(0); cin.tie(0); }
void setIO(str s = "") {
	unsyncIO();
	// cin.exceptions(cin.failbit); 
	// throws exception when do smth illegal
	// ex. try to read letter into int
	if (sz(s)) { setIn(s+".in"), setOut(s+".out"); } // for USACO
}
 
/**
 * Description: Link-Cut Tree. Given a function $f(1\ldots N)\to 1\ldots N,$ 
 	* evaluates $f^b(a)$ for any $a,b.$ \texttt{sz} is for path queries; 
 	* \texttt{sub}, \texttt{vsub} are for subtree queries. \texttt{x->access()} 
 	* brings \texttt{x} to the top and propagates it; its left subtree will be 
 	* the path from \texttt{x} to the root and its right subtree will be empty. 
 	* Then \texttt{sub} will be the number of nodes in the connected component
 	* of \texttt{x} and \texttt{vsub} will be the number of nodes under \texttt{x}.
 	* Use \texttt{makeRoot} for arbitrary path queries.
 * Time: O(\log N)
 * Usage: FOR(i,1,N+1)LCT[i]=new snode(i); link(LCT[1],LCT[2],1);
 * Source: Dhruv Rohatgi, Eric Zhang
	* https://sites.google.com/site/kc97ble/container/splay-tree/splaytree-cpp-3
	* https://c...content-available-to-author-only...s.com/blog/entry/67637
 * Verification: (see README for links)
	* ekzhang Balanced Tokens
	* Dynamic Tree Test (Easy)
	* https://p...content-available-to-author-only...e.org/viewproblem.php?pid=578 (The Applicant)
 */
 
typedef struct snode* sn;
struct snode { //////// VARIABLES
	sn p, c[2]; // parent, children
	bool flip = 0; // subtree flipped or not
	int val, sz, mn; // value in node, # nodes in current splay tree
	snode(int _val) : val(_val) {
		p = c[0] = c[1] = NULL; calc(); }
	friend int getSz(sn x) { return x?x->sz:0; }
	friend int getMn(sn x) { return x?x->mn:MOD; }
	void prop() { // lazy prop
		if (!flip) return;
		swap(c[0],c[1]); flip = 0;
		F0R(i,2) if (c[i]) c[i]->flip ^= 1;
	}
	void calc() { // recalc vals
		mn = min(val,min(getMn(c[0]),getMn(c[1])));
		sz = 1+getSz(c[0])+getSz(c[1]);
	}
	//////// SPLAY TREE OPERATIONS
	int dir() {
		if (!p) return -2;
		F0R(i,2) if (p->c[i] == this) return i;
		return -1; // p is path-parent pointer
	} // -> not in current splay tree
	// test if root of current splay tree
	bool isRoot() { return dir() < 0; } 
	friend void setLink(sn x, sn y, int d) {
		if (y) y->p = x;
		if (d >= 0) x->c[d] = y; }
	void rot() { // assume p and p->p propagated
		assert(!isRoot()); int x = dir(); sn pa = p;
		setLink(pa->p, this, pa->dir());
		setLink(pa, c[x^1], x); setLink(this, pa, x^1);
		pa->calc(); calc();
	}
	void splay() {
		while (!isRoot() && !p->isRoot()) {
			p->p->prop(), p->prop(), prop();
			dir() == p->dir() ? p->rot() : rot();
			rot();
		}
		if (!isRoot()) p->prop(), prop(), rot();
		prop();
	}
	//////// BASE OPERATIONS
	void access() { // bring this to top of tree, propagate
		for (sn v = this, pre = NULL; v; v = v->p) {
			v->splay(); // now switch virtual children
			v->c[1] = pre; v->calc(); pre = v;
		}
		splay(); assert(!c[1]); // right subtree is empty
	}
	void makeRoot() { 
		access(); flip ^= 1; access(); assert(!c[0] && !c[1]); }
	//////// QUERIES
	friend sn lca(sn x, sn y) {
		if (x == y) return x;
		x->access(), y->access(); if (!x->p) return NULL;
		x->splay(); return x->p?:x; // y was below x in latter case
	} // access at y did not affect x -> not connected
	friend bool connected(sn x, sn y) { return lca(x,y); } 
	// # nodes above
	int distRoot() { access(); return getSz(c[0]); } 
	sn getRoot() { // get root of LCT component
		access(); sn a = this; 
		while (a->c[0]) a = a->c[0], a->prop();
		a->access(); return a;
	}
	sn FBO() {
		prop();
		if (val == mn) return this;
		if (getMn(c[0]) == mn) return c[0]->FBO();
		assert(getMn(c[1]) == mn); return c[1]->FBO();
	}
	sn getMin() {
		access();
		return c[0]->FBO();
	}
	//////// MODIFICATIONS
	void set(int v) { access(); val = v; calc(); } 
	friend void link(sn x, sn y, bool force = 0) { 
		assert(x); assert(y);
		// dbg("LINK");
		assert(!connected(x,y)); 
		// dbg("OK");
		if (force) y->makeRoot(); // make x par of y
		else { y->access(); assert(!y->c[0]); }
		// dbg("OK");
		x->access(); setLink(y,x,0); 
		// dbg("BEFORECALC");
		y->calc();
		// dbg("FIXEDLINK");
	}
	friend void cut(sn y) { // cut y from its parent
		y->access(); assert(y->c[0]);
		y->c[0]->p = NULL; y->c[0] = NULL; y->calc(); }
	friend void cut(sn x, sn y) { // if x, y adj in tree
		x->makeRoot(); y->access(); 
		assert(y->c[0] == x && !x->c[0] && !x->c[1]); cut(y); }
};
sn LCT[600005];
 
pi ed[400005];
int N,M,Q, rig[400005];
bool in[400005];
 
void del(int ind) {
	assert(in[ind]);
	cut(LCT[ed[ind].f],LCT[ind]);
	cut(LCT[ed[ind].s],LCT[ind]);
	in[ind] = 0;
}
 
bool link(int ind) {
	in[ind] = 1;
	int u = ed[ind].f, v = ed[ind].s;
	assert(!connected(LCT[u],LCT[v]));
	link(LCT[u],LCT[ind],1);
	link(LCT[v],LCT[ind],1);
	return 1;
}
 
bool ad(int ind) {
	int u = ed[ind].f, v = ed[ind].s;
	if (!connected(LCT[u],LCT[v])) return link(ind);
	LCT[u]->makeRoot();
	if (LCT[v]->distRoot()%4 == 0) return 0;
	sn s = LCT[v]->getMin(); assert(s->val != MOD);
	del(s->val); return link(ind);
}
 
// oops did I really need this to pass

/**
 * Description: Fast input and output.
 * Time: input is $\sim$300ms faster for $10^6$ long longs on CF
 * Source: 
 	* https://c...content-available-to-author-only...s.com/gym/102394/submission/64154785
 	* https://c...content-available-to-author-only...s.com/contest/1254/submission/65420506 (neal)
 	* https://c...content-available-to-author-only...s.com/blog/entry/45835 (AI.Cash)
 * Verification: https://c...content-available-to-author-only...s.com/gym/102394/problem/G 
 */
 
namespace FastIO {
	const int BSZ = 1<<15; ////// INPUT
	char ibuf[BSZ]; int ipos, ilen;
	char nc() { // next char
		if (ipos == ilen) {
			ipos = 0; ilen = fread(ibuf,1,BSZ,stdin);
			if (!ilen) return EOF;
		}
		return ibuf[ipos++];
	}
	void rs(str& x) { // read str
		char ch; while (isspace(ch = nc()));
		do { x += ch; } while (!isspace(ch = nc()) && ch != EOF);
	}
	template<class T> void ri(T& x) { // read int or ll
		char ch; int sgn = 1;
		while (!isdigit(ch = nc())) if (ch == '-') sgn *= -1;
		x = ch-'0'; while (isdigit(ch = nc())) x = x*10+(ch-'0');
		x *= sgn;
	}
	template<class T, class... Ts> void ri(T& t, Ts&... ts) { 
		ri(t); ri(ts...); } // read ints
	////// OUTPUT (call initO() at start)
	char obuf[BSZ], numBuf[100]; int opos;
	void flushOut() { fwrite(obuf,1,opos,stdout); opos = 0; }
	void wc(char c) { // write char
		if (opos == BSZ) flushOut();
		obuf[opos++] = c; }
	void ws(str s) { trav(c,s) wc(c); } // write str
	template<class T> void wi(T x, char after = '\0') { /// write int
		if (x < 0) wc('-'), x *= -1;
		int len = 0; for (;x>=10;x/=10) numBuf[len++] = '0'+(x%10);
		wc('0'+x); R0F(i,len) wc(numBuf[i]);
		if (after) wc(after);
	}
	void initO() { assert(atexit(flushOut) == 0); } /// auto-flush output
}
using namespace FastIO;
/// initO(); int a,b; ri(a,b); wi(b,'\n'); wi(a,'\n'); 
 
int main() {
	initO();
	ri(N,M,Q);
	dbg(Q);
	FOR(i,1,N+1) {
		LCT[2*M+i] = new snode(MOD);
		//dbg("OK",M+i);
	}
	F0R(i,M) {
		ri(ed[i].f,ed[i].s); 
		ed[i].f += 2*M, ed[i].s += 2*M;
		LCT[i] = new snode(i);
		dbg(ed[i]);
	}
	FOR(i,M,2*M) {
		ed[i] = ed[i-M];
		LCT[i] = new snode(i);
	}
	int r = -1;
	F0R(i,2*M) {
		while (r < 2*M-1 && ad(r+1)) r ++;
		rig[i] = r;
		if (in[i]) del(i);
		dbg(i,rig[i]);
	}
	F0R(i,Q) {
		int l,r; ri(l,r); l--,r--;
		if (rig[r+1] >= M+l-1) ws("NO\n");
		else ws("YES\n");
	}
	flushOut();
	// you should actually read the stuff at the bottom
}
 
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/