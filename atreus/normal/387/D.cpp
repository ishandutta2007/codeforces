#include <cstring>
#include <algorithm>
#include <map>
#include <stack>
#include <iomanip>
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
const int maxn = 500 + 500;
const int mod = 998244353;
const ll inf = (1ll << 62);
bool visited[maxn];
vector <int> v[maxn];
int match[maxn], mat[maxn][maxn], ans[maxn];

bool dfs (int u, int ref) {
	if (visited[u] or u == ref)
		return 0;
	visited[u] = 1;
	for (auto child : v[u]) 
		if (child != ref and (match[child] == -1 or dfs (match[child], ref)))
			return match[child] = u, 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, w;
		cin >> u >> w;
		v[u].PB (w);
		mat[u][w] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] == 1)
				ans[i] ++;
			if (mat[j][i] == 1)
				ans[i] ++;
		}
		if (mat[i][i] == 1)
			ans[i] --;
	}
	ll tot = inf;
	for (int i = 1; i <= n; i++) {
		memset (match, -1, sizeof match);
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			memset (visited, 0, sizeof visited);
			cnt += dfs (j, i);
		}
		ll sum = m - (cnt + ans[i]);
		ll bm = 3*n-2;
		tot = min (tot, sum + bm - (cnt + ans[i]));
	}
	cout << tot << endl;
}