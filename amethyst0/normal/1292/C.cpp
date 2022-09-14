#pragma comment(linker, "/STACK:1000000000")
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

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int maxn = 3010;

int sz[maxn];
vector <int> ed[maxn];

void dfs(int v, int p) {
	sz[v] = 1;

	for (int u : ed[v]) {
		if (u != p) {
			dfs(u, v);
			sz[v] += sz[u];
		}
	}
}

ll dp[maxn][maxn];
bool used[maxn];

ll go(int a, int b, int sza) {
	if (dp[a][b] != -1) {
		return dp[a][b];
	}

	ll ans = 0;

	for (int u : ed[b]) {
		if (!used[u]) {
			used[u] = true;
			ans = max(ans, go(a, u, sza) + (ll)sza * sz[u]);
			used[u] = false;
		}
	}

	for (int u : ed[a]) {
		if (!used[u]) {
			used[u] = true;
			ans = max(ans, go(u, b, sz[u]) + (ll)sz[u] * sz[b]);
			used[u] = false;
		}
	}

	return dp[a][b] = ans;
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	ll ans = 0;

	memset(dp, -1, sizeof dp);

	for (int i = 1; i <= n; i++) {
		dfs(i, -1);

		for (int u : ed[i]) {
			used[i] = true;
			used[u] = true;
			ans = max(ans, go(i, u, sz[i] - sz[u]) + (ll)(sz[i] - sz[u]) * sz[u]);
			used[i] = false;
			used[u] = false;
		}
	}

	cout << ans << endl;
}