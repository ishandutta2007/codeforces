/*input
5 5 1
1 2 2
2 3 3
3 5 2
1 4 4
4 5 4
2 10
*/

// spoiled

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
#include <queue>

using namespace std;

#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define FORA(i, a) for (auto &i : a)
#define FORB(i, a, b) for (int i = a; i >= b; --i)
#define SZ(a) ((int) a.size())
#define ALL(a) begin(a), end(a)

typedef int64_t ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define fi first
#define se second

// start of code

struct Path
{
	int to; int64_t d;
	Path (int _to = 0, int64_t _d = 0): to(_to), d(_d) {}
	bool operator< (const Path p) const { return d > p.d; }
};

const int MAXN = 200010;
const int64_t INF = 1e16;

// SegmentTree

int64_t tree[MAXN << 2];
#define MID ((lo + hi) >> 1)
#define ROOT1 (root << 1)
#define ROOT2 (root << 1 | 1)

void upd(int root, int lo, int hi, int l, int r, int64_t x)
{
	if (l <= lo && hi <= r) { tree[root] = min(tree[root], x); return; }
	if (hi < l || r < lo) return; 

	upd(ROOT1, lo, MID, l, r, x);
	upd(ROOT2, MID + 1, hi, l, r, x);
}

void exp(int root, int lo, int hi, int64_t A[])
{
	if (lo == hi) { A[lo] = tree[root]; return; }
	tree[ROOT1] = min(tree[ROOT1], tree[root]);
	tree[ROOT2] = min(tree[ROOT2], tree[root]);
	exp(ROOT1, lo, MID, A);
	exp(ROOT2, MID + 1, hi, A);
}

// end 

int N, M, Q; 
int64_t W[MAXN];
int U[MAXN], V[MAXN];
vector<int> G[MAXN];

int64_t dist1[MAXN], distN[MAXN];
int par1[MAXN], parN[MAXN];
int ids1[MAXN], idsN[MAXN];

int order[MAXN];
vector<int> path;

int P[MAXN];
int64_t tmp[MAXN];

void findSP(int source, int64_t dist[], int par[])
{
	for (int u = 1; u <= N; ++u) dist[u] = INF;
	priority_queue<Path> pq;
	pq.emplace(source, dist[source] = 0);
	while (!pq.empty()) {
		int u = pq.top().to; int64_t d = pq.top().d; pq.pop();
		if (dist[u] == d) for (int id : G[u]) {
			int v = (U[id] == u ? V[id] : U[id]);
			int64_t w = W[id];
			if (dist[v] > d + w) {
				pq.emplace(v, dist[v] = d + w);
				par[v] = id;
			}
		}
	}
}

void findId(int source, int64_t dist[], int ids[], int null)
{
	for (int u = 0; u < N; ++u) P[u] = u + 1;
	sort(P, P + N, [&] (int u, int v) { return dist[u] < dist[v]; });
	
	for (int i = 0; i < N; ++i) {
		int u = P[i];
		ids[u] = null;
		for (int id : G[u]) {
			int v = (U[id] == u ? V[id] : U[id]);
			if (dist[v] + W[id] == dist[u]) {
				if (order[id] >= 0) ids[u] = order[id];
				else ids[u] = ids[v];
			}
		}
	}
}



signed main()
{

	for (int i = 0; i < MAXN << 2; ++i) tree[i] = INF;
	for (int i = 0; i < MAXN; ++i) order[i] = -1;

	scanf("%d %d %d", &N, &M, &Q);
	for (int i = 1; i <= M; ++i) {
		int u, v; 
		scanf("%d %d %I64d", &u, &v, &W[i]);
		U[i] = u, V[i] = v;
		G[u].emplace_back(i);
		G[v].emplace_back(i);
	}

	findSP(1, dist1, par1);
	findSP(N, distN, parN);

	int u = 1;
	while (u != N) {
		order[parN[u]] = path.size();
		path.emplace_back(parN[u]);
		u = (U[parN[u]] == u ? V[parN[u]] : U[parN[u]]);
	}

	findId(1, dist1, ids1, -1);
	findId(N, distN, idsN, path.size());

	for (int u = 1; u <= N; ++u) for (int id : G[u]) {
		int v = (U[id] == u ? V[id] : U[id]);
		if (order[id] < 0)
			upd(1, 0, path.size() - 1, ids1[u] + 1, idsN[v] - 1, dist1[u] + W[id] + distN[v]);
	}
	exp(1, 0, path.size() - 1, tmp);

	for (int _ = 0; _ < Q; ++_) {
		int id; int64_t x;
		scanf("%d %I64d", &id, &x);
		int u = U[id], v = V[id];

		int64_t ans = INF;
		ans = min(ans, dist1[u] + x + distN[v]);
		ans = min(ans, dist1[v] + x + distN[u]);

		if (order[id] >= 0) {
			ans = min(ans, tmp[order[id]]);
		} else ans = min(ans, dist1[N]);

		printf("%I64d\n", ans);
	}

	return 0;
}