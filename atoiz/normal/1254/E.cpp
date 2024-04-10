// https://codeforces.com/contest/1254/problem/E

/*input
3
1 2
1 3
1 0 0

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
#include <utility>
#include <tuple>
#include <climits>
#include <fstream>
#include <bitset>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#include <random>
#include <chrono>
#include <ios>
#include <iomanip>
#include <functional>

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

const int MOD = 1000000007;
struct intmod
{
	long long val;

	intmod(long long _val = 0) { val = _val % MOD; val += (val < 0 ? MOD : 0); }

	bool operator!=(intmod rhs) const { return val != rhs.val; }
	bool operator==(intmod rhs) const { return val == rhs.val; }

	intmod operator+=(intmod rhs) { val += rhs.val; val -= (val >= MOD ? MOD : 0); return *this; }
	intmod operator-=(intmod rhs) { val -= rhs.val; val += (val < 0 ? MOD : 0); return *this; }
	intmod operator*=(intmod rhs) { val = (long long) val * rhs.val % MOD; return *this; }

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

const int MAXN = 500007, LOG = 20;
int U[MAXN], V[MAXN], dep[MAXN], anc[LOG][MAXN], N, U_id[MAXN], V_id[MAXN], up[MAXN];
int root[MAXN];
vector<int> G[MAXN], prv[MAXN], nxt[MAXN];
intmod fact[MAXN];

void kill()
{
	puts("0");
	exit(0);
}

void dfs_build(int u)
{
	FORA(id, G[u]) {
		if (id == up[u]) continue;
		int v = U[id] ^ V[id] ^ u;

		up[v] = id;
		anc[0][v] = u;
		FOR(j, 1, LOG - 1) anc[j][v] = anc[j - 1][anc[j - 1][v]];
		dep[v] = dep[u] + 1;

		dfs_build(v);
	}
}

int get_lca(int u, int v)
{
	if (dep[u] < dep[v]) swap(u, v);
	FORB(j, LOG - 1, 0) if (dep[u] - (1 << j) >= dep[v]) u = anc[j][u];
	if (u == v) return u;
	FORB(j, LOG - 1, 0) if (anc[j][u] != anc[j][v]) u = anc[j][u], v = anc[j][v];
	return anc[0][u];
}

void connect(int prv_id, int nxt_id, int u)
{
// 	cout << u << ": " << prv_id << ' ' << nxt_id << endl;
	prv_id = (u == U[prv_id]) ? U_id[prv_id] : V_id[prv_id];
	nxt_id = (u == U[nxt_id]) ? U_id[nxt_id] : V_id[nxt_id];
// 	cout << u << ": " << prv_id << ' ' << nxt_id << endl;

	if (prv[u][nxt_id] >= 0 && prv[u][nxt_id] != prv_id) kill();
	if (nxt[u][prv_id] >= 0 && nxt[u][prv_id] != nxt_id) kill();

	prv[u][nxt_id] = prv_id;
	nxt[u][prv_id] = nxt_id;
}

signed main()
{
	scanf("%d", &N);
	FOR(i, 2, N) {
		scanf("%d %d", &U[i], &V[i]);
		G[U[i]].push_back(i);
		G[V[i]].push_back(i);
		U_id[i] = SZ(G[U[i]]) + 1;
		V_id[i] = SZ(G[V[i]]) + 1;	
	}
	FOR(i, 1, N) {
		prv[i].assign(SZ(G[i]) + 2, -1);
		nxt[i].assign(SZ(G[i]) + 2, -1);
	}

	U_id[1] = V_id[1] = 1;

	dfs_build(1);

	FOR(_v, 1, N) {
	    int v = _v;
		int u;
		scanf("%d", &u);
// 		cout << "Q " << u << ' ' << v << endl;
		if (!u) continue;
		int a = get_lca(u, v);

		if (u == v) kill();

		int cur_id = 0;
		while (u != a) {
			int nxt_id = up[u];
			connect(cur_id, nxt_id, u);
			cur_id = nxt_id;
			u = anc[0][u];
		}
		int up_id = cur_id;

		cur_id = 1;
		while (v != a) {
			int nxt_id = up[v];
			connect(nxt_id, cur_id, v);
			cur_id = nxt_id;
			v = anc[0][v];
		}
		int down_id = cur_id;

		connect(up_id, down_id, a);
	}
// 	cout << "So far, so good" << endl;

	fact[0] = 1;
	FOR(i, 1, N) fact[i] = fact[i - 1] * i;

	intmod ans = 1;
	FOR(u, 1, N) {
		int cnt = -1;

		FOR(id, 0, SZ(prv[u]) - 1) root[id] = -1;
		FOR(id, 0, SZ(prv[u]) - 1) {
			if (prv[u][id] < 0) {
				if (root[id] >= 0) kill();
				root[id] = id;
				if (id != 0) ++cnt;

				for (int i = nxt[u][id]; i >= 0; i = nxt[u][i]) {
					if (root[i] >= 0) kill();
					root[i] = id;
				}
			}
		}
		if (root[1] == 0) {
		    ++cnt;
		    if (cnt != 0) kill();
		}
// 		cout << u << ": " << cnt << endl;
		FOR(id, 0, SZ(prv[u]) - 1) {
			if (root[id] < 0) kill();
		}

		ans *= fact[cnt];
	}

	cout << ans << endl;

	return 0;
}