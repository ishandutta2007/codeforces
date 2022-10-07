#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

const int maxn = 1 << 18;

int n;
int p[maxn], a[maxn];
vector<int> e[maxn];
ll dp[maxn][2];

void dfs(int v) {
	dp[v][0] = 0;
	dp[v][1] = -1;

	for (int i = 0; i < (int)e[v].size(); i++) {
		int to = e[v][i];
		dfs(to);
		vector<ll> ndp(2, -1);
		ndp[0] = dp[v][0];
		ndp[1] = dp[v][1];
		for (int i1 = 0; i1 < 2; i1++) {
			for (int i2 = 0; i2 < 2; i2++) {
				if (dp[v][i1] != -1 && dp[to][i2] != -1) {
					ndp[(i1 + i2) % 2] = max(ndp[(i1 + i2) % 2], dp[v][i1] + dp[to][i2]);
				}
			}
		}
		dp[v][0] = ndp[0];
		dp[v][1] = ndp[1];
	}
	dp[v][1] = max(dp[v][1], dp[v][0] + a[v]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("task.in", "r", stdin);
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &p[i], &a[i]);
		if (p[i] != -1) {
			e[p[i]].push_back(i);
		}
	}

	ll ans = -1;
	for (int i = 1; i <= n; i++) {
		if (p[i] == -1) {
			dfs(i);
			ans = max(dp[i][0], dp[i][1]);
		}
	}
	cout << ans << endl;

	return 0;
}