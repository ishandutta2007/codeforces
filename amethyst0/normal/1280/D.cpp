//#pragma comment(linker, "/STACK:1000000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = 3010;
pair <int, ll> dp[maxn][maxn];
int len[maxn];
pair <int, ll> buf[maxn];

vector <int> ed[maxn];
ll b[maxn];

void merg(int v, int u) {
	for (int i = 0; i < len[v] + len[u]; i++) {
		buf[i] = mp(-maxn, -maxn);
	}

	for (int i = 0; i < len[v]; i++) {
		for (int j = 0; j < len[u]; j++) {
			pair <int, ll> cur = mp(dp[v][i].first + dp[u][j].first, dp[v][i].second + dp[u][j].second);
			if (buf[i + j] < cur) {
				buf[i + j] = cur;
			}

			cur = mp(dp[v][i].first + dp[u][j].first, dp[v][i].second);
			if (dp[u][j].second > 0) {
				cur.first++;
			}

			if (buf[i + j + 1] < cur) {
				buf[i + j + 1] = cur;
			}
		}
	}

	len[v] = len[v] + len[u];
	for (int i = 0; i < len[v]; i++) {
		dp[v][i] = buf[i];
	}
}

void dfs(int v, int p) {
	len[v] = 1;
	dp[v][0] = mp(0, b[v]);

	for (int u : ed[v]) {
		if (u == p) {
			continue;
		}

		dfs(u, v);
		merg(v, u);
	}
}

int main() {
	int t;

	cin >> t;

	while (t--) {
		int n, m;

		scanf("%d %d", &n, &m);

		for (int i = 1; i <= n; i++) {
			ed[i].clear();
		}

		for (int i = 1; i <= n; i++) {
			scanf("%lld", &b[i]);
		}

		for (int i = 1; i <= n; i++) {
			ll x;

			scanf("%lld", &x);

			b[i] = x - b[i];
		}

		for (int i = 0; i < n - 1; i++) {
			int x, y;

			scanf("%d %d", &x, &y);
			ed[x].push_back(y);
			ed[y].push_back(x);
		}

		dfs(1, -1);
		int ans = dp[1][m - 1].first;
		if (dp[1][m - 1].second > 0) {
			ans++;
		}
		printf("%d\n", ans);
	}

	//system("pause");
}