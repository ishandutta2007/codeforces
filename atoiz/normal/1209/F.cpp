/*input
12 19
1 2
2 3
2 4
2 5
2 6
2 7
2 8
2 9
2 10
3 11
11 12
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10

*/

#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

const long long MOD = 1000000007;
struct intmod
{
	long long val;

	intmod(long long _val = 1) { val = _val % MOD; if (val < 0) val += MOD; }

	bool operator!=(intmod rhs) const { return val != rhs.val; }
	bool operator==(intmod rhs) const { return val == rhs.val; }

	intmod operator+=(intmod rhs) { val += rhs.val; if (val >= MOD) val -= MOD; return *this; }
	intmod operator-=(intmod rhs) { val -= rhs.val; if (val < 0) val += MOD; return *this; }
	intmod operator*=(intmod rhs) { val = val * rhs.val % MOD; return *this; }

	friend intmod operator+(intmod lhs, intmod rhs) { return lhs += rhs; }
	friend intmod operator-(intmod lhs, intmod rhs) { return lhs -= rhs; }
	friend intmod operator*(intmod lhs, intmod rhs) { return lhs *= rhs; }

	friend intmod sqr(intmod a) { return a * a; }
	friend intmod bpow(intmod a, int p) { intmod ans(1); while (p) { if (p & 1) ans *= a; a = sqr(a); p >>= 1; } return ans; }
	friend intmod inv(intmod a) { return bpow(a, MOD - 2); }

	intmod operator/=(intmod rhs) { return (*this) *= inv(rhs); }
	friend intmod operator/(intmod lhs, intmod rhs) { return lhs /= rhs; }

	friend istream& operator>>(istream &is, intmod &im) { return is >> im.val; }
	friend ostream& operator<<(ostream &os, intmod im) { return os << im.val; }
};


// start of code

const int MAXN = 100007, MAX_NODE = MAXN * 10, LOG = 20;
int N, M;
vector<pii> G[MAXN];
int par[MAXN], trieNode[MAXN];
int trie[MAX_NODE][10], last = 1;
int dep[MAX_NODE], anc[LOG][MAX_NODE];
intmod val[MAX_NODE];

int getAnc(int u, int h) { FORB(i, LOG - 1, 0) if (dep[u] - (1 << i) >= h) u = anc[i][u]; return u; }
int getLca(int u, int v)
{
	if (dep[u] < dep[v]) swap(u, v);
	FORB(i, LOG - 1, 0) if (dep[u] - (1 << i) >= dep[v]) u = anc[i][u];
	// cout << "lca " << u << ' ' << v << endl;
	if (u == v) return u;
	FORB(i, LOG - 1, 0) if (anc[i][u] != anc[i][v]) u = anc[i][u], v = anc[i][v];
	return anc[0][u];
}

int getChild(int u, int d)
{
	if (trie[u][d]) return trie[u][d];
	int v = trie[u][d] = ++last;
	// cerr << u << " " << v << endl;
	val[v] = val[u] * 10 + d;
	dep[v] = dep[u] + 1;
	anc[0][v] = u;
	FOR(i, 1, LOG - 1) anc[i][v] = anc[i - 1][anc[i - 1][v]];
	return v;
}

struct Vertex
{
	int g_u, u;
	bool operator< (const Vertex ver) const
	{
		int v = ver.u;
		if (u == v) return 0;
		if (dep[u] != dep[v]) return dep[u] > dep[v];
		int lca = getLca(u, v);
		// cout << "comp " << u << ' ' << v << ": " << lca << endl;
		int parU = getAnc(u, dep[lca] + 1);
		int parV = getAnc(v, dep[lca] + 1);
		FOR(d, 0, 9) {
			if (trie[lca][d] == parU) return 0;
			if (trie[lca][d] == parV) return 1;
		}
		assert(0);
		return 1;
	}
};

vi split(int x)
{
	vi vec;
	while (x) vec.push_back(x % 10), x /= 10;
	reverse(ALL(vec));
	return vec;
}

priority_queue<Vertex> pq;

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	FOR(i, 1, M) {
		int u, v; cin >> u >> v;
		G[u].emplace_back(i, v);
		G[v].emplace_back(i, u);
	}

	val[1] = 0;
	pq.push({1, 1});
	while (!pq.empty()) {
		int g_u = pq.top().g_u, u = pq.top().u; pq.pop();
		if (trieNode[g_u]) continue;
		trieNode[g_u] = u;

		for (auto e : G[g_u]) if (e.se != par[g_u]) {
			// cerr << g_u << " -> " << e.se << ": " << e.fi << endl;
			par[e.se] = g_u;
			int v = u;
			vi digits = split(e.fi);
			FORA(d, digits) v = getChild(v, d);
			pq.push({e.se, v});
		}
	}

	FOR(i, 2, N) cout << val[trieNode[i]] << '\n';

	return 0;
}