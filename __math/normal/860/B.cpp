#include <bits/stdc++.h>

using namespace std;
#define FOR(i,n) for(int i = 0; i < (n); i++)
#define sz(c) ((int)c.size())
#define ten(n) ((int)1e##n)
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

template<typename ...> static inline int getchar_unlocked(void) { return getchar(); }
template<typename ...> static inline void putchar_unlocked(int c) { putchar(c); }
#define mygc(c) (c)=getchar_unlocked()
#define mypc(c) putchar_unlocked(c)
void reader(int& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
void reader(ll& x) { int k, m = 0; x = 0; for (;;) { mygc(k); if (k == '-') { m = 1; break; }if ('0' <= k&&k <= '9') { x = k - '0'; break; } }for (;;) { mygc(k); if (k<'0' || k>'9')break; x = x * 10 + k - '0'; }if (m) x = -x; }
int reader(char c[]) { int i, s = 0; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c[s++] = i; for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c[s++] = i; }c[s] = '\0'; return s; }
int reader(string& c) { int i; for (;;) { mygc(i); if (i != ' '&&i != '\n'&&i != '\r'&&i != '\t'&&i != EOF) break; }c.push_back(i); for (;;) { mygc(i); if (i == ' ' || i == '\n' || i == '\r' || i == '\t' || i == EOF) break; c.push_back(i); }; return sz(c); }
template <class T, class S> void reader(T& x, S& y) { reader(x); reader(y); }
template <class T, class S, class U> void reader(T& x, S& y, U& z) { reader(x); reader(y); reader(z); }
template <class T, class S, class U, class V> void reader(T& x, S& y, U& z, V & w) { reader(x); reader(y); reader(z); reader(w); }
void writer(int x, char c) { int s = 0, m = 0; char f[10]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(ll x, char c) { int s = 0, m = 0; char f[20]; if (x<0)m = 1, x = -x; while (x)f[s++] = x % 10, x /= 10; if (!s)f[s++] = 0; if (m)mypc('-'); while (s--)mypc(f[s] + '0'); mypc(c); }
void writer(const char c[]) { int i; for (i = 0; c[i] != '\0'; i++)mypc(c[i]); }
void writer(const string& x, char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
void writer(const char x[], char c) { int i; for (i = 0; x[i] != '\0'; i++)mypc(x[i]); mypc(c); }
template<class T> void writerLn(T x) { writer(x, '\n'); }
template<class T, class S> void writerLn(T x, S y) { writer(x, ' '); writer(y, '\n'); }
template<class T, class S, class U> void writerLn(T x, S y, U z) { writer(x, ' '); writer(y, ' '); writer(z, '\n'); }
template<class T> void writerArr(T x[], int n) { if (!n) { mypc('\n'); return; }FOR(i, n - 1)writer(x[i], ' '); writer(x[n - 1], '\n'); }
template<class T> void writerArr(vector<T>& x) { writerArr(x.data(), (int)x.size()); }

template<class T> void chmin(T& a, const T& b) { if (a > b) a = b; }
template<class T> void chmax(T& a, const T& b) { if (a < b) a = b; }

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
ll mod_pow(ll a, ll n, ll mod) {
	ll ret = 1;
	ll p = a % mod;
	while (n) {
		if (n & 1) ret = ret * p % mod;
		p = p * p % mod;
		n >>= 1;
	}
	return ret;
}
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }

struct Node {
	int id;
	int childs[10];
	Node() {
		id = -1;
		memset(childs, -1, sizeof(int) * 10);
	}
};

class trie_tree {

	vector<Node> nodes;

	int add_node() {
		nodes.push_back(Node());
		return sz(nodes) - 1;
	}

public:
	trie_tree() {
		clear();
	}

	void clear() {
		nodes.clear();
		add_node();
	}

	int add(const char* s, int id) {
		int cur = 0;
		for (int i = 0; s[i]; i++) {
			int nxt = nodes[cur].childs[s[i] - '0'];
			if (nxt == -1) {
				nxt = add_node();
				nodes[cur].childs[s[i] - '0'] = nxt;
			}
			cur = nxt;
		}
		if (nodes[cur].id == -1 || nodes[cur].id == id) {
			nodes[cur].id = id;
		} else {
			nodes[cur].id = -2;
		}
		return cur;
	}

	int dfs(int cur) {
		int detect = nodes[cur].id;
		for (int i = 0; i < 10; i++) {
			int ncur = nodes[cur].childs[i];
			if (ncur == -1) continue;
			int ret = dfs(ncur);
			if (ret == -2) detect = -2;
			if (detect == -2) {
				continue;
			}
			if (detect == -1) {
				detect = ret;
			} else {
				if (detect != ret) {
					detect = -2;
				}
			}
		}

		return nodes[cur].id = detect;
	}

	void build() {
		dfs(0);
		nodes[0].id = -2;
	}

	void check_ans(vector<string>& ans, string& cs, int cur) {
		if (nodes[cur].id > -1) {
			int id = nodes[cur].id;
			if (sz(ans[id]) > sz(cs)) {
				ans[id] = cs;
			}
		}

		for (int i = 0; i < 10; i++) {
			int ncur = nodes[cur].childs[i];
			if (ncur == -1) continue;
			cs.push_back('0' + i);
			check_ans(ans, cs, ncur);
			cs.pop_back();
		}
	}
};


int main() {
	int n; reader(n);
	vector<string> vs(n);
	FOR(i, n) reader(vs[i]);

	trie_tree tt;

	FOR(i, n) {
		FOR(j, 9) {
			tt.add(vs[i].c_str() + j, i);
		}
	}
	tt.build();

	vector<string> ans(n, "0000000000");
	string buf;
	tt.check_ans(ans, buf, 0);
	for (auto& s : ans) {
		writerLn(s);
	}

	return 0;
}