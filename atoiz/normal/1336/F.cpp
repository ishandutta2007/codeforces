/*input
10 4 2
3 10
9 3
4 9
4 6
8 2
1 7
2 1
4 5
6 7
7 1
8 7
9 2
10 3

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstring>

using namespace std;

const int MAXN = 150006, LOG = __lg(MAXN) + 1;

struct FenwickTree
{
	int A[MAXN];
	FenwickTree() { memset(A, 0, sizeof A); }

	void modify(int i, int x) 
	{
		for (; i < MAXN; i += i & (-i)) A[i] += x; 
	}

	int get(int i)
	{
		int ans = 0;
		for (; i > 0; i -= i & (-i)) ans += A[i];
		return ans;
	}

	int get(int l, int r)
	{
		return (l <= r ? get(r) - get(l - 1) : 0);
	}
} treeSame, treeDiff;

int N, M, K, par[MAXN], anc[LOG][MAXN], dep[MAXN], tin[MAXN], tout[MAXN], T;
int virIn[MAXN], virOut[MAXN], virTour[MAXN * 2];
vector<int> G[MAXN], vir[MAXN], oppList[MAXN];
vector<pair<int, int>> paths[MAXN];
int64_t ansSame = 0, ansDiff = 0;

void init(int u, int p)
{
	tin[u] = ++T;
	anc[0][u] = par[u] = p;
	for (int j = 1; j < LOG; ++j) anc[j][u] = anc[j - 1][anc[j - 1][u]];
	dep[u] = dep[p] + 1;
	for (int v : G[u]) if (v != p) init(v, u);
	tout[u] = T;
}

int getKthAnc(int u, int k)
{
	for (int j = LOG - 1; j >= 0; --j) if (dep[u] - (1 << j) >= k) u = anc[j][u];
	return u;
}

int getLca(int u, int v)
{
	if (dep[u] < dep[v]) swap(u, v);
	for (int j = LOG - 1; j >= 0; --j) if (dep[u] - (1 << j) >= dep[v]) u = anc[j][u];
	if (u == v) return u;
	for (int j = LOG - 1; j >= 0; --j) if (anc[j][u] != anc[j][v]) u = anc[j][u], v = anc[j][v];
	return par[u];
}

void initVir(int u)
{
	virIn[u] = T + 1;
	for (int x : oppList[u]) virTour[++T] = x;
	for (int v : vir[u]) initVir(v);
	virOut[u] = T;
}

void update(int u, int root, int cur)
{
	if (dep[u] - dep[root] >= K) {
		ansSame += 2 * treeSame.get(N);
		if (dep[cur] > dep[root]) {
			int w = getKthAnc(cur, dep[root] + 1);
			ansSame -= treeSame.get(tin[w], tout[w]);
		}
	} else {
		if (dep[cur] >= K + dep[root] * 2 - dep[u]) {
			int w = getKthAnc(cur, K + dep[root] * 2 - dep[u]);
			ansSame += treeSame.get(tin[w], tout[w]);
		}
	}
}

void solveVir(int u, int root, bool clean)
{
	for (int &v : vir[u]) if (virOut[v] - virIn[v] > virOut[vir[u].back()] - virIn[vir[u].back()]) swap(v, vir[u].back());
	for (int v : vir[u]) solveVir(v, root, v != vir[u].back());
	for (int v : vir[u]) if (v != vir[u].back()) {
		for (int i = virIn[v]; i <= virOut[v]; ++i) {
			update(u, root, virTour[i]);
		}

		for (int i = virIn[v]; i <= virOut[v]; ++i) {
			treeSame.modify(tin[virTour[i]], 1);
		}
	}
	for (int cur : oppList[u]) update(u, root, cur), treeSame.modify(tin[cur], 1);

	if (clean) {
		for (int i = virIn[u]; i <= virOut[u]; ++i) {
			treeSame.modify(tin[virTour[i]], -1);
		}
	}
}

void solveSame(vector<pair<int, int>> &curPaths, int root)
{
	if ((int) curPaths.size() < 2) return;
	// cout << "root = " << root << endl;
	// for (auto x : curPaths) cout << x.first << ' ' << x.second << endl;
	// int64_t bef = ansSame;
	vector<int> vec;
	for (auto x : curPaths) vec.push_back(x.first), vec.push_back(x.second);
	for (auto x : curPaths) oppList[x.first].push_back(x.second), oppList[x.second].push_back(x.first);
	sort(vec.begin(), vec.end(), [&](int u, int v) { return tin[u] < tin[v]; });
	int numV = (int) vec.size();
	for (int i = 0; i < numV - 1; ++i) vec.push_back(getLca(vec[i], vec[i + 1]));
	sort(vec.begin(), vec.end(), [&](int u, int v) { return tin[u] < tin[v]; });
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	numV = (int) vec.size();

	for (int i = 1; i < numV; ++i) vir[getLca(vec[i - 1], vec[i])].push_back(vec[i]);
	// for (int i = 1; i < numV; ++i) cout << getLca(vec[i - 1], vec[i]) << " -> " << vec[i] << endl;
	assert(root == vec[0]);
	T = 0;
	initVir(root);
	for (int u : vir[root]) solveVir(u, root, true);
	// cout << " = " << (ansSame - bef) << " / 2" << endl;

	for (int u : vec) vir[u].clear();
	for (auto x : curPaths) oppList[x.first].clear(), oppList[x.second].clear();
}

void solve(int u, int p)
{
	for (int v : G[u]) if (v != p) solve(v, u);
	// cout << u << endl;
	// for (auto x : paths[u]) cout << x.first << ' ' << x.second << endl;
	for (auto x : paths[u]) ansDiff += treeDiff.get(tin[x.first]) + treeDiff.get(tin[x.second]);
	for (auto x : paths[u]) {
		if (dep[x.first] >= dep[u] + K) {
			int w = getKthAnc(x.first, dep[u] + K);
			treeDiff.modify(tin[w], 1);
			treeDiff.modify(tout[w] + 1, -1);
		}

		if (dep[x.second] >= dep[u] + K) {
			int w = getKthAnc(x.second, dep[u] + K);
			treeDiff.modify(tin[w], 1);
			treeDiff.modify(tout[w] + 1, -1);
		}
	}
	solveSame(paths[u], u);
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	init(1, 0);
	while (M--) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (dep[u] + dep[v] - 2 * dep[getLca(u, v)] >= K) {
			paths[getLca(u, v)].emplace_back(u, v);
		}
	}

	solve(1, 0);
	cout << ansDiff + ansSame / 2 << endl;
}