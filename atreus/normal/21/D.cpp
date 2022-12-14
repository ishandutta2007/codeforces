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
const int maxn = 1e5 + 100;
const int mod = 1e9 + 7;
const int inf = (1 << 30);
ll n, m, cnt, num[maxn], d[20], e[20][20], dp[20][20];
bool visited[20];

bool check (int idx, int mask) {
	int x = mask & (1 << idx);
	return x != 0;
}

int solve (int mask) {
	if (num[mask] != -1)
		return num[mask];
	if (mask == 0)
		return num[mask] = 0;
	ll ret = inf;
	for (int i = 1; i <= n; i++) {
		if (!check (i, mask))
			continue;
		for (int j = 1; j <= n; j++) {
			if (!check (j, mask) or j == i)
				continue;
			ret = min (ret, dp[i][j] + solve (mask - (1 << i) - (1 << j)));
		}
	}
	return num[mask] = ret;
}

void dfs (int u) {
	visited[u] = 1;
	cnt += d[u];
	for (int i = 1; i <= n; i++)
		if (e[u][i] and !visited[i])
			dfs (i);
}

int main() {
	ios_base::sync_with_stdio(false);
	ll ans = 0;
	cin >> n >> m;
	memset (dp, 63, sizeof dp);
	for (int i = 1; i <= m; i++) {
		ll v, u, w;
		cin >> v >> u >> w;
		e[v][u] = e[u][v] = 1;
		dp[v][u] = dp[u][v] = min (dp[u][v], w);
		d[u] ++;
		d[v] ++;
		ans += w;
	}
	for (int k = 1; k <= n; k++) {
		dp[k][k] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dp[i][j] = min (dp[i][j], dp[i][k] + dp[k][j]);
	}
	dfs (1);
	if (cnt != 2 * m)
		return cout << -1 << endl, 0;
	
	int mask = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] & 1)
			mask += (1 << i);
	}
	memset (num, -1, sizeof num);
	cout << ans + solve (mask) << endl;
	
}