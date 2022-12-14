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
const int maxn = 1e6 + 100;
const int inf = (int)1e9;
const int block = 400;

vector <int> v[maxn], red;

int dp[maxn];

void bfs () {
	memset (dp, -1, sizeof dp);
	queue <int> q;
	for (auto w : red) {
		dp[w] = 0;
		q.push (w);
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto w : v[u]) {
			if (dp[w] == -1) {
				dp[w] = dp[u] + 1;
				q.push (w);
			}
		}
	}
}

int par[maxn][22], h[maxn];

int lca (int fi, int se) {
	if (fi == se)
		return fi;
	if (h[fi] < h[se])
		return lca (se, fi);
	for (int i = 20; i >= 0; i--)
		if (h[fi] - (1 << i) >= h[se])
			fi = par[fi][i];
	if (fi == se)
		return fi;
	for (int i = 20; i >= 0; i--) {
		if (par[fi][i] != par[se][i]) {
			fi = par[fi][i];
			se = par[se][i];
		}
	}
	return par[fi][0];
}

int dis (int fi, int se) {
	int L = lca (fi, se);
	return h[fi] + h[se] - 2 * h[L];
}

void dfs (int u, int p = -1) {
	par[u][0] = p;
	for (int i = 1; i <= 20 and par[u][i - 1] != -1; i++)
		par[u][i] = par[par[u][i - 1]][i - 1];
	for (auto w : v[u]) {
		if (w != p) {
			h[w] = h[u] + 1;
			dfs (w, u);
		}
	}
}

pii Q[maxn];

int main(){ 
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n - 1; i++) {
		int u, w;
		cin >> u >> w;
		v[u].PB (w);
		v[w].PB (u);
	}
	dfs (1);
	red.PB (1);
	for (int i = 0; i < q; i++) {
		if (i % block == 0) {
			bfs ();
		}
		cin >> Q[i].F >> Q[i].S;
		if (Q[i].F == 1) {
			red.PB (Q[i].S);
		}
		else {
			for (int j = i - 1; j / block == i / block; j--) {
				if (Q[j].F == 1) {
					dp[Q[i].S] = min (dp[Q[i].S], dis (Q[i].S, Q[j].S));
				}
			}
			cout << dp[Q[i].S] << '\n';
		}
	}
}