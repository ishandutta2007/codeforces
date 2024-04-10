#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <cassert>
#include <cmath>
#include <vector>
#include <unordered_set>
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
const int maxn = 1e5 + 50;
vector <int> v[maxn];
bool visited[maxn];
int h[maxn], dp[maxn], par[maxn][50];

int mydad (int u, int len){
	for (int i = 30; i >= 0; i--){
		if ((1 << i) <= len){
			u = par[u][i];
			len -= (1 << i);
		}
	}
	return u;
}

int lca (int u, int w){
	if (h[u] < h[w])
		swap (u, w);
	for (int j = 30; j >= 0; j--)
		if (h[u] - (1ll << j) >= h[w])
			u = par[u][j];
	if (u == w)
		return u;
	for (int j = 30; j >= 0; j--){
		if (par[u][j] != par[w][j]){
			u = par[u][j];
			w = par[w][j];
		}
	}
	return par[u][0];
}

void dfs (int u, int dad, int height){
	par[u][0] = dad;
	visited[u] = 1;
	dp[u] = 1;
	h[u] = height;
	for (auto w : v[u]){
		if (!visited[w]){
			dfs (w, u, height + 1);
			dp[u] += dp[w];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++){
		int u, w;
		cin >> u >> w;
		v[u].PB (w);
		v[w].PB (u);
	}
	dfs (1, 0, 0);
	for (int j = 1; j <= 30; j++)
		for (int i = 1; i <= n; i++)
			par[i][j] = par[par[i][j - 1]][j - 1];

	int q;
	cin >> q;
	for (int i = 1; i <= q; i++){
		int u, w;
		cin >> u >> w;
		if (u == w){
			cout << n << '\n';
			continue;
		}
		int anc = lca (u, w);
		if (h[u] == h[w]){
			int len = h[u] - h[anc] - 1;
			int lendad = mydad (u, len), londad = mydad (w, len);
			cout << n - dp[lendad] - dp[londad] << '\n';
			continue;
		}
		if ( (-2 * h[anc] + h[u] + h[w]) % 2 == 1){
			cout << 0 << '\n';
			continue;
		}
		if (h[u] < h[w])
			swap (u, w);
		int len = (-2 * h[anc] + h[u] + h[w]) / 2;
		int lendad = mydad (u, len), londad = mydad (u, len - 1);
		cout << dp[lendad] - dp[londad] << '\n';
	}
}