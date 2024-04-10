#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <limits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <iterator>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pii;
typedef pair<ll, ll> Pll;

#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)(c).size())
#define ten(x) ((int)1e##x)
#define tenll(x) ((ll)1e##x)

// #pragma comment(linker,"/STACK:36777216")

template<class T> void chmax(T& l, const T r) { l = max(l, r); }
template<class T> void chmin(T& l, const T r) { l = min(l, r); }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }

#ifdef _WIN32
#   define mygc(c) (c)=getchar()
#   define mypc(c) putchar(c)
#else
#   define mygc(c) (c)=getchar_unlocked()
#   define mypc(c) putchar_unlocked(c)
#endif

void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }

void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }

typedef ll cost_type;
typedef pair<cost_type, int> P;
const ll INF = numeric_limits<ll>::max() / 10;

struct edge {
	int to;
	cost_type cost;
	edge(){}
	edge(int to, cost_type cost) : to(to), cost(cost) {}
};

void dijkstra(int s, vector<P::first_type>& cost_table, vector<vector<edge> >& edges, vector<int>* _prev = NULL){

	//init
	cost_table.resize((int)edges.size());
	fill(cost_table.begin(), cost_table.end(), P::first_type(INF));
	if (_prev) _prev->resize((int)edges.size());
	if (_prev) fill(_prev->begin(), _prev->end(), -1);

	priority_queue<P, vector<P>, greater<P> > q;
	q.push(P(0, s));
	cost_table[s] = 0;

	while (!q.empty()) {
		P p = q.top(); q.pop();
		int v = p.second;
		if (cost_table[v] < p.first) continue;
		for (int i = 0; i < (int)edges[v].size(); i++) {
			edge& e = edges[v][i];
			if (cost_table[e.to] > cost_table[v] + e.cost) {
				cost_table[e.to] = cost_table[v] + e.cost;
				if (_prev) (*_prev)[e.to] = v;
				q.push(P(cost_table[e.to], e.to));
			}
		}
	}
}

vector<vector<edge>> e;

typedef tuple<ll, int, int> P2;

map<Pii, int> e2id;

class UnionFind {
private:
	int n;
	vector<int> a;
public:
	UnionFind(int n) : n(n), a(n, -1) {}
	int find(int x) { return a[x] < 0 ? x : (a[x] = find(a[x])); }
	bool same(int x, int y) { return find(x) == find(y); }
	bool same(Pii& p) { return same(p.first, p.second); }
	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		if (a[x] > a[y]) swap(x, y);
		a[x] += a[y];
		a[y] = x;
		n--;
		return true;
	}
	bool unite(Pii& p) { return unite(p.first, p.second); }
	int size() const { return n; }
	int size(int x) { return -a[find(x)]; }
};

int main(){
	int n, m; reader(n, m);
	e.resize(n);
	vector<P2> es;
	FOR(i, m){
		int a, b, c; reader(a, b, c);
		a--; b--;
		e[a].emplace_back(b, c);
		e[b].emplace_back(a, c);
		es.emplace_back(c, a, b);

		e2id[Pii(a, b)] = i + 1;
		e2id[Pii(b, a)] = i + 1;
	}
	sort(es.begin(), es.end());

	int s; reader(s); s--;

	vector<P::first_type> cost_table;
	dijkstra(s, cost_table, e);

	static bool connect_low[ten(5) * 3];
	UnionFind uf(n);
	ll ans = 0;
	vector<int> anses;
	for (auto& p : es) {
		ll cst; int from, to;
		tie(cst, from, to) = p;
		if (uf.same(from, to)) continue;
		if (cost_table[from] > cost_table[to]) swap(from, to);
		if (connect_low[to]) continue;
		if (cost_table[to] - cost_table[from] == cst) {
			connect_low[to] = true;
			uf.unite(from, to);
			ans += cst;
			anses.push_back(e2id[Pii(from, to)]);
		}
	}

	writerLn(ans);
	if(sz(anses)) writerArr(&anses[0], sz(anses));
}