#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>
#include <limits.h>
#include <fstream>
#include <unordered_map>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int maxn = (int)1e5 + 10;

int dp[maxn][2][2];

vector <int> ed[maxn];

int ans = 0;

void dfs(int v, int p) {
	int cnt = 0;

	vector <pii> a, b;

	dp[v][1][0] = dp[v][1][1] = 1;

	for (int u : ed[v]) {
		if (u == p) {
			continue;
		}

		dfs(u, v);

		cnt++;
		dp[v][0][0] = max(dp[v][0][0], max(dp[u][0][0], dp[u][1][0]));
		dp[v][0][1] = max(dp[v][0][1], max(dp[u][0][1], dp[u][1][1]));
		dp[v][1][0] = max(dp[v][1][0], dp[u][0][0] + 1);
		dp[v][1][1] = max(dp[v][1][1], dp[u][0][1] + 1);

		a.push_back(mp(max(dp[u][0][0], dp[u][1][0]), u));
		b.push_back(mp(max(dp[u][0][1], dp[u][1][1]), u));
	}

	dp[v][0][0] += max(cnt - 1, 0);
	dp[v][0][1] += max(cnt - 1, 0);

	sort(all(a));
	sort(all(b));
	reverse(all(a));
	reverse(all(b));

	for (int i = 0; i < 2; i++) {
		if (i == (int)a.size()) {
			break;
		}

		for (int j = 0; j < 2; j++) {
			if (j == (int)b.size()) {
				break;
			}

			if (a[i].second != b[j].second) {
				ans = max(ans, a[i].first + b[j].first + max(0, cnt - 2) + (p != -1));
			}
		}
	}

	a.clear();
	b.clear();

	for (int u : ed[v]) {
		if (u == p) {
			continue;
		}

		a.push_back(mp(dp[u][0][0], u));
		b.push_back(mp(dp[u][0][1], u));
	}

	sort(all(a));
	sort(all(b));
	reverse(all(a));
	reverse(all(b));

	for (int i = 0; i < 2; i++) {
		if (i == (int)a.size()) {
			break;
		}

		for (int j = 0; j < 2; j++) {
			if (j == (int)b.size()) {
				break;
			}

			if (a[i].second != b[j].second) {
				ans = max(ans, a[i].first + b[j].first + 1);
			}
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		x--;
		y--;
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	dfs(0, -1);

	ans = max(ans, dp[0][0][0]);
	ans = max(ans, dp[0][0][1]);
	ans = max(ans, dp[0][1][0]);
	ans = max(ans, dp[0][1][1]);

	printf("%d\n", ans);
}