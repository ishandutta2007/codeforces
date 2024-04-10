/*input
7 8
1 2
1 3
2 4
3 5
4 6
5 6
4 7
5 7

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

// start of code

const int MAXN = 14, MAXM = 100;
int n, m;
bool G[MAXN][MAXN];

int pathSize[MAXN][MAXN][1 << MAXN], pathPrev[MAXN][MAXN][1 << MAXN];

int minCost[1 << MAXN];
struct { int from, to, mask; } costPrev[1 << MAXN];

bool flag[MAXN];
void backtrack(int mask0, int from, int to, int idx, int mask)
{
	if (idx == n) {
		if (minCost[mask0 | mask] <= minCost[mask0] + pathSize[from][to][mask]) return;
		minCost[mask0 | mask] = minCost[mask0] + pathSize[from][to][mask];
		costPrev[mask0 | mask] = {from, to, mask};
		return;
	}

	backtrack(mask0, from, to, idx + 1, mask);
	if (flag[idx]) return;
	flag[idx] = 1;
	backtrack(mask0, from, to, idx + 1, mask ^ (1 << idx));
	flag[idx] = 0;
}

signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	FOR(_, 0, m-1) {
		int u, v; cin >> u >> v; --u, --v;
		G[u][v] = G[v][u] = 1;
	}

	FOR(i, 0, n-1) FOR(j, 0, n-1) FOR(mask, 0, (1 << n) - 1) pathSize[i][j][mask] = MAXM;
	FOR(i, 0, n-1) pathSize[i][i][1 << i] = 0;

	FOR(cnt, 1, n) FOR(mask, 0, (1 << n) - 1) if (__builtin_popcount(mask) == cnt)
	FOR(u, 0, n-1) if ((mask >> u) & 1) FOR(v, 0, n-1) if ((mask >> v) & 1) if (pathSize[u][v][mask] < MAXM)
	FOR(w, 0, n-1) if ((w == u ? pathSize[u][v][mask] > 1 : !((mask >> w) & 1)) && G[v][w])
	if (pathSize[u][v][mask] + 1 < pathSize[u][w][mask | (1 << w)]) {
		pathSize[u][w][mask | (1 << w)] = pathSize[u][v][mask] + 1;
		pathPrev[u][w][mask | (1 << w)] = v;
	}

	FOR(mask, 0, (1 << n) - 1) minCost[mask] = MAXM;
	minCost[1] = 0;

	FOR(cost, 0, m) FOR(mask, 0, (1 << n) - 1) if (minCost[mask] == cost) {
		FOR(u, 0, n-1) flag[u] = (mask >> u) & 1;
		FOR(u, 0, n-1) if (flag[u]) FOR(v, 0, n-1) if (flag[v]) {
			backtrack(mask, u, v, 0, (1 << u) | (1 << v));
		}
	}

	int mask = (1 << n) - 1;
	cout << minCost[mask] << '\n';
	while (mask != 1) {
		int from = costPrev[mask].from, to = costPrev[mask].to, prevMask = costPrev[mask].mask;
		mask = (mask ^ prevMask) | (1 << from) | (1 << to);

		// cout << "P" << from << ' ' << to << ' ' << prevMask << endl;

		while (__builtin_popcount(prevMask) > 1) {
			// cout << "S" << from << ' ' << to << ' ' << prevMask << endl;
			int mid = pathPrev[from][to][prevMask];
			cout << mid + 1 << ' ' << to + 1 << '\n';
			if (from != to) prevMask ^= (1 << to);
			to = mid;
		}
	}

	return 0;
}