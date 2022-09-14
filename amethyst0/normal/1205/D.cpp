#pragma comment(linker, "/STACK:1000000000")
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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int maxn = 1010;
vector <int> ed[maxn];
int sz[maxn];

void dfs(int v, int p = -1) {
	sz[v] = 1;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p) {
			dfs(u, v);
			sz[v] += sz[u];
		}
	}
}

vector <int> g;

int dp[maxn][maxn];

int n;

bool check(int v) {
	dfs(v);

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (sz[u] * 2 > n) {
			return false;
		}
	}

	return true;
}

int we[maxn];
int pr[maxn];

int cx = 1;
int step = 1;

void dfs1(int v, int p, int e, int tot) {
	we[v] = e;
	pr[v] = p;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p) {
			cx++;
			dfs1(u, v, cx - 1 - tot, cx - 1);
		}
	}
}

void dfs2(int v, int p, int e, int tot) {
	we[v] = e;
	pr[v] = p;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p) {
			cx += step;
			dfs2(u, v, cx - step - tot, cx - step);
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	int v = -1;

	for (int i = 1; i <= n; i++) {
		if (check(i)) {
			v = i;
			break;
		}
	}

	if (v == -1) {
		throw 1;
	}

	dfs(v);

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		g.push_back(sz[u]);
	}

	memset(dp, -1, sizeof dp);

	dp[0][0] = 0;

	for (int i = 0; i < (int)g.size(); i++) {
		for (int j = 0; j <= n; j++) {
			if (dp[i][j] == -1) {
				continue;
			}

			dp[i + 1][j] = 0;
			dp[i + 1][j + g[i]] = 1;
		}
	}

	int best = -1;
	int res = -1;

	for (int i = 0; i < n; i++) {
		if (dp[(int)g.size()][i] == -1) {
			continue;
		}

		int ans = i * (n - i);

		if (ans > res) {
			res = ans;
			best = i;
		}
	}

	if (res < 2 * n * n / 9) {
		throw 1;
	}

	if (best == -1) {
		throw 1;
	}

	int pos = (int)g.size();

	int w = best;

	vector <int> f;

	while (pos > 0) {
		if (dp[pos][w] == 0) {
			pos--;
		}
		else {
			int x = ed[v][pos - 1];
			pos--;
			w -= sz[x];
			f.push_back(x);
		}
	}

	memset(pr, -1, sizeof pr);

	for (int i = 0; i < (int)f.size(); i++) {
		int x = f[i];

		cx++;
		dfs1(x, v, cx - 1, cx - 1);
	}

	cx--;

	step = cx;
	cx = step;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (pr[u] != -1) {
			continue;
		}

		cx += step;
		dfs2(u, v, cx - step, cx - step);
	}

	for (int i = 1; i <= n; i++) {
		if (i == v) {
			continue;
		}

		printf("%d %d %d\n", pr[i], i, we[i]);
	}

	//system("pause");
	return 0;
}