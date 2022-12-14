#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <set>
#define MP make_pair
#define F first
#define PB push_back
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int mod = (int)1e9 + 7;
const int maxn = 1e5 + 100;
const int inf = (int)1e9;

struct yal {
	int fi, se, weight, ind;
};

yal ed[maxn];

vector <pii> v[maxn];

int n, m;

vector <int> g;

int vaz[maxn], h[maxn], up[maxn];
bool visited[maxn], mark[maxn];

void dfs (int u, int idx = 0) {
	visited[u] = 1;
	up[u] = h[u];
	for (auto w : v[u]) {
		if (!visited[w.F]) {
			h[w.F] = h[u] + 1;
			dfs (w.F, w.S);
			up[u] = min (up[u], up[w.F]);
		}
		else {
			if (w.S != idx)
				up[u] = min (up[u], h[w.F]);
		}
	}
	if (up[u] == h[u])
		vaz[idx] = 2;
}

int par[maxn];

int root (int u) {
	if (par[u] < 0)
		return u;
	return par[u] = root (par[u]);
}

void merge (int u, int w) {
	u = root (u), w = root (w);
	if (u == w)
		return;
	par[u] = w;
}

void check (int l, int r) {
	for (auto w : g) {
		if (!visited[w]) {
			dfs (w);
		}
	}
	memset (visited, 0, sizeof visited);
	memset (mark, 0, sizeof mark);
	for (auto w : g) {
		v[w].clear();
	}
	g.clear();
	for (int i = l; i < r; i++)
		merge (ed[i].fi, ed[i].se);
}

bool cmp (yal Fi, yal Se) {
	return Fi.weight < Se.weight;
}

int main(){ 
	ios::sync_with_stdio(false);
	memset (par, -1, sizeof par);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> ed[i].fi >> ed[i].se >> ed[i].weight;
		ed[i].ind = i;
	}
	sort (ed + 1, ed + m + 1, cmp);
	int last = 1;
	for (int i = 1; i <= m + 1; i++) {
		if (i > 1 and ed[i].weight != ed[i - 1].weight) {
			check (last, i);
			last = i;
		}

		if (root (ed[i].fi) == root (ed[i].se))
			continue;
		
		vaz[ed[i].ind] = 1;
		v[root (ed[i].fi)].PB ({root (ed[i].se), ed[i].ind});
		v[root (ed[i].se)].PB ({root (ed[i].fi), ed[i].ind});
		if (!mark[root (ed[i].fi)]) {
			mark[root (ed[i].fi)] = 1;
			g.PB (root (ed[i].fi));
		}
		if (!mark[root (ed[i].se)]) {
			mark[root (ed[i].se)] = 1;
			g.PB (root (ed[i].se));
		}
	}
	for (int i = 1; i <= m; i++) {
		if (vaz[i] == 0) {
			cout << "none \n";
		}
		else if (vaz[i] == 1) {
			cout << "at least one \n";
		}
		else {
			cout << "any \n";
		}
	}
}