/*input
5 6
1 1 2 2
10 -3 -7 -3 -10
10 3 9 3 6
2 1
2 2
1 2 6
2 1
1 2 5
2 1

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
#define a first
#define b second

// start of code

const int MAXN = 400009, BLOCK = 250, BLOCK_NUM = MAXN / BLOCK + 10;

ll A[MAXN], B[MAXN];
int N, Q;
int tour[MAXN], from[MAXN], to[MAXN];
int mapp[MAXN];
pll pnts[MAXN];
int ptr[BLOCK_NUM], sz[BLOCK_NUM];
ll inc[BLOCK_NUM];
vector<int> G[MAXN];

bool bad(pll p0, pll p1, pll p2) { return 1.0L * (p1.a - p0.a) * (p2.b - p0.b) - 1.0L * (p2.a - p0.a) * (p1.b - p0.b) >= 0; }
ll val(int i, ll x) { return pnts[i].a * x + pnts[i].b; }

void build(int k)
{
	int l = k * BLOCK, r = min((k + 1) * BLOCK, N) - 1;
	FOR(i, l, r) A[i] += inc[k]; inc[k] = 0;

	ptr[k] = sz[k] = 0;
	FOR(i, l, r) {
		pll p(B[mapp[i]], A[mapp[i]] * B[mapp[i]]);
		while (sz[k] > 1 && bad(pnts[l + sz[k] - 2], pnts[l + sz[k] - 1], p)) --sz[k];
		pnts[l + (sz[k]++)] = p;
	}
}

ll get(int k)
{
	int l = k * BLOCK;
	ptr[k] = min(ptr[k], sz[k] - 1);
	while (ptr[k] < sz[k] - 1 && val(l + ptr[k], inc[k]) < val(l + ptr[k] + 1, inc[k])) ++ptr[k];
	return val(l + ptr[k], inc[k]);
}

void dfs(int u)
{
	static int timer = 0;
	from[u] = timer++;
	FORA(v, G[u]) dfs(v);
	to[u] = timer;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	scanf("%d %d", &N, &Q);
	FOR(v, 2, N) {
		int u; scanf("%d", &u);
		G[u].push_back(v);
	}
	dfs(1);

	FOR(u, 1, N) {
		int a; scanf("%d", &a);
		A[from[u] << 1] += a, A[to[u] << 1] -= a;
	}

	FOR(u, 1, N) {
		int b; scanf("%d", &b);
		B[from[u] << 1] += b, B[to[u] << 1] -= b;
	}

	for (int i = 2; i < 2 * N; i += 2) A[i] += A[i - 2], B[i] += B[i - 2];
	for (int i = 1; i < 2 * N; i += 2) A[i] = A[i - 1], B[i] = -B[i - 1];
	N *= 2;

	// prep
	FOR(i, 0, N - 1) mapp[i] = i;
	for (int l = 0; l < N; l += BLOCK) {
		sort(mapp + l, mapp + min(N, l + BLOCK), [&](int x, int y) { return B[x] < B[y]; });
		build(l / BLOCK);
	}

	// answer
	FOR(_, 0, Q - 1) {
		int type, v, x; scanf("%d %d", &type, &v);
		int lo = from[v] * 2, hi = to[v] * 2 - 1;
		int lo_k = lo / BLOCK, hi_k = hi / BLOCK;
		int lo_r = lo_k * BLOCK + BLOCK - 1, hi_l = hi_k * BLOCK;

		if (type == 1) {
			scanf("%d", &x);

			if (lo_k == hi_k) {
				FOR(i, lo, hi) A[i] += x;
				build(lo_k);
				continue;
			}

			assert(lo_r < hi_l);
			FOR(i, lo, lo_r) A[i] += x;
			build(lo_k);
			FOR(k, lo_k + 1, hi_k - 1) inc[k] += x;
			FOR(i, hi_l, hi) A[i] += x;
			build(hi_k);
		} else {
			ll ans = 0;
			if (lo_k == hi_k) {
				FOR(i, lo, hi) ans = max(ans, (A[i] + inc[lo_k]) * B[i]);
				printf("%I64d\n", ans);
				continue;
			} 

			assert(lo_r < hi_l);
			FOR(i, lo, lo_r) ans = max(ans, (A[i] + inc[lo_k]) * B[i]);
			FOR(i, hi_l, hi) ans = max(ans, (A[i] + inc[hi_k]) * B[i]);
			FOR(k, lo_k + 1, hi_k - 1) ans = max(ans, get(k));
			printf("%I64d\n", ans);
		}
	}
	return 0;
}