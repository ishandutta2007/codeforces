#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iomanip>
#define F first
#define S second
#define PB push_back
#define PF push_front
#define MP make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
const int block = 316;

vector <int> minn[maxn][30], v[maxn];
int par[maxn][30], h[maxn];

vector <int> merge (vector <int> fi, vector <int> se) {
	int idx1 = 0, idx2 = 0, cnt = 0;
	vector <int> ret;
	while (cnt < 10 and (idx1 < fi.size() or idx2 < se.size())) {
		if (idx1 < fi.size()) {
			if (idx2 == se.size() or fi[idx1] < se[idx2])
				ret.PB (fi[idx1 ++]);
			else
				ret.PB (se[idx2 ++]);
		}
		else
			ret.PB (se[idx2 ++]);
		cnt ++;
	}
	return ret;
}

bool visited[maxn];

void dfs (int u, int parent = -1) {
	visited[u] = 1;
	if (parent != -1)
		h[u] = h[parent] + 1;
	par[u][0] = parent;
	for (int i = 1; i <= 20 and par[u][i - 1] != -1; i++) {
		par[u][i] = par[par[u][i - 1]][i - 1];
		minn[u][i] =  merge (minn[u][i - 1], minn[par[u][i - 1]][i - 1]);
	}
	
	for (auto w : v[u])
		if (!visited[w])
			dfs (w, u);
}

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

void solve (int fi, int se, int LCA, int a) {
	vector <int> ans;
	for (int i = 20; i >= 0; i--) {
		if (h[fi] - (1 << i) >= h[LCA]) {
			for (auto w : minn[fi][i])
				ans.PB (w);
			fi = par[fi][i];
		}
		if (h[se] - (1 << i) >= h[LCA]) {
			for (auto w : minn[se][i])
				ans.PB (w);
			se = par[se][i];
		}
	}
	for (auto w : minn[LCA][0])
		ans.PB (w);
	sort (ans.begin(), ans.end());
	cout << min (a, (int)ans.size()) << " ";
	for (int i = 0; i < min (a, (int)ans.size()); i++)
		cout << ans[i] << " ";
	cout << endl;
}

int main () {
	int n, m, q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n - 1; i++) {
		int u, w;
		cin >> u >> w;
		v[u].PB (w);
		v[w].PB (u);
	}
	
	for (int i = 1; i <= m; i++) {
		int c;
		cin >> c;
		if (minn[c][0].size() < 10)
			minn[c][0].PB (i);
	}

	dfs (1);

	for (int i = 1; i <= q; i++) {
		int u, w, a;
		cin >> u >> w >> a;
		int LCA = lca (u, w);
		solve (u, w, LCA, a);
	}
}