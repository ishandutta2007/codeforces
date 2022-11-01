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

class SCC {
	vector<char> used;
	vector<vector<int>> e, re;

	void dfs(int v, vector<int>& vs) {
		used[v] = true;
		for (auto to : e[v]) if (!used[to]) dfs(to, vs);
		vs.push_back(v);
	}
	void rdfs(int v, vector<int> & group) {
		used[v] = true;
		for (auto to : re[v]) if (!used[to]) rdfs(to, group);
		group.push_back(v);
	}

public:
	SCC(const vector<vector<int>>& G) : used(sz(G)), e(sz(G)), re(sz(G)) {
		FOR(i, sz(G)) for (auto to : G[i]) {
			e[i].push_back(to);
			re[to].push_back(i);
		}
	}

	vector<vector<int>> run() {
		vector<int> vs;
		fill(used.begin(), used.end(), 0);
		FOR(v, sz(e)) if (!used[v]) dfs(v, vs);
		fill(used.begin(), used.end(), 0);
		vector<vector<int>> ret;
		for (int i = sz(vs) - 1; i >= 0; i--) {
			if (!used[vs[i]]) {
				ret.emplace_back();
				rdfs(vs[i], ret.back());
			}
		}
		return ret;
	}
};



int main() {
	int n, m; reader(m, n);
	vector<vector<int>> e(n);

	bool ok = true;
	vector<int> last;
	FOR(i, m) {
		int x; reader(x);
		vector<int> cur(x);
		FOR(i, x) reader(cur[i]);

		int ml = min(sz(last), sz(cur));
		Pii edge(-1, -1);
		FOR(j, ml) {
			if (last[j] == cur[j]) {
				continue;
			} else {
				edge = Pii(last[j], cur[j]);
				break;
			}
		}
		if (edge.first == -1) {
			if (sz(last) > sz(cur)) {
				ok = false;
			}
		} else {
			e[edge.second - 1].push_back(edge.first - 1);
		}
		last = cur;
	}


	{
		SCC scc(e);
		auto cc = scc.run();
		if (sz(cc) != n) ok = false;
	}

	queue<int> q;
	vector<int> rem(n);
	vector<int> dep(n);
	FOR(i, n)for (auto c : e[i]) rem[c]++;
	FOR(i, n) {
		if (rem[i] == 0) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int v; v = q.front(); q.pop();
		for (auto c : e[v]) {
			rem[c]--;
			int ndep = dep[v];
			if (v < c) ndep++;
			chmax(dep[c], ndep);

			if (rem[c] == 0) {
				q.push(c);
			}
		}
	}
	FOR(i, n) if (dep[i] > 1) ok = false;
	set<int> bigger;
	FOR(i, n) if (dep[i] == 1) bigger.insert(i);


	if (!ok) {
		puts("No");
		return 0;
	}

	vector<int> ans(bigger.begin(), bigger.end());
	for (auto& c : ans) c++;
	puts("Yes");
	writerLn(sz(ans));
	writerArr(ans);

	return 0;
}