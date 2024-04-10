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
#include <array>

using namespace std;
#define int int64_t

namespace kactl {
	/**
 * Author: Chen Xing
 * Date: 2009-10-13
 * License: CC0
 * Source: N/A
 * Description: Fast bipartite matching algorithm. Graph $g$ should be a list
 * of neighbors of the left partition, and $btoa$ should be a vector full of
 * -1's of the same size as the right partition. Returns the size of
 * the matching. $btoa[i]$ will be the match for vertex $i$ on the right side,
 * or $-1$ if it's not matched.
 * Usage: vi btoa(m, -1); hopcroftKarp(g, btoa);
 * Time: O(\sqrt{V}E)
 * Status: stress-tested by MinimumVertexCover, and tested on oldkattis.adkbipmatch and SPOJ:MATCHING
 */

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	for (int b : g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		for (int a : btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			for (int a : cur) for (int b : g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			for (int a : next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,0,sz(g))
			res += dfs(a, 0, g, btoa, A, B);
	}
}
}

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)
#define SORT(a) sort(begin(a), end(a))

#define SORTUNIQUE(a) sort(begin(a), end(a)), a.erase(unique(begin(a), end(a)), end(a))
#define LB(a,x) ((int) (lower_bound(ALL(a), x) - begin(a)))
#define UB(a,x) ((int) (upper_bound(ALL(a), x) - begin(a)))
#define FORL(i, a, b) for (int64_t i = a; i <= b; ++i)
#define FORBL(i, a, b) for (int64_t i = a; i >= b; --i)
#define FORANOPTR(i, a) for (auto i : a)
#define FORIT(i, a, b) for (auto i = a; i != b; ++i)

#define MP make_pair
#define PB push_back
#define EB emplace_back
#define SP ' '
#define NL '\n'

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<VVI> VVVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<VVL> VVVL;
#define fi first
#define se second

template <typename T>
ostream& operator<< (ostream &os, vector<T> &vec) 
{
	if (vec.empty()) return os;
	for (int i = 0; i < (int) vec.size() - 1; ++i) os << vec[i] << ' ';
	return os << vec.back();
}

void DB() {}
template <typename T, typename... Args>
void DB(T t, Args... a)
{
	#ifdef LOCAL
	cout << flush;
	cerr << t;
	DB(a...);
	cerr << flush;
	#endif
}

mt19937 rng((int) chrono::system_clock().now().time_since_epoch().count());

// start of code

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	VI a(n); FOR(i,0,n-1) cin >> a[i];
	VVI g(n);
	FOR(i, 0, n-1) if (a[i] * 3ll > m) {
		FOR(j, 0, n - 1) if (a[j] * 3ll <= m) {
			if (a[i] % a[j] == 0 && 2 * a[i] + a[j] <= m) {
				g[j].push_back(i);
			}
		}
	}
	VI btoa(n, -1);
	kactl::hopcroftKarp(g, btoa);
	FOR(i, 0, n-1) if (a[i] * 3ll > m && btoa[i] == -1) {
		cout << -1 << endl;
		return 0;
	}
	vector<pii> ans;
	VI used(n, 0);
	FOR(i, 0, n-1) if (a[i] * 3ll > m) {
		int j = btoa[i];
		used[i] = 1, used[j] = 1;
		ans.EB(a[i] * 2 + a[j], a[i] + a[j]);
	}
	FOR(i, 0, n-1) if (!used[i]) {
		used[i] = 0;
		ans.EB(a[i] * 3, a[i] * 2);
	}
	cout << SZ(ans) << endl;
	for (auto [x, y] : ans) cout << x << ' ' << y << '\n';
}