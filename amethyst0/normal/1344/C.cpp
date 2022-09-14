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
#include <array>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
#define uint unsigned int

const int maxn = (int)2e5 + 10;
vector <int> ed[2][maxn];
bool used[2][maxn];

int usd[maxn];
int posit = 0;

int val[2][maxn];

int bfs(int it, int v) {
	if (used[it][v]) {
		return val[it][v];
	}

	usd[v] = posit;
	int ans = maxn + 10;

	for (int u : ed[it][v]) {
		if (usd[u] != posit) {
			ans = min(ans, bfs(it, u));
		}
	}

	return ans;
}

void dfs(int it, int v) {
	if (used[it][v]) {
		return;
	}

	used[it][v] = true;

	for (int u : ed[it][v]) {
		if (!used[it][u]) {
			dfs(it, u);
		}
	}
}

vector <int> e[maxn];
int us[maxn];

void dfs1(int x) {
	us[x] = 1;

	for (int u : e[x]) {
		if (us[u] == 1) {
			cout << -1 << '\n';
			exit(0);
		}

		if (us[u] == 0) {
			dfs1(u);
		}
	}

	us[x] = 2;
}

void getv(int it, int v) {
	if (val[it][v] != -1) {
		return;
	}

	val[it][v] = v;

	for (int u : ed[it][v]) {
		getv(it, u);
		val[it][v] = min(val[it][v], val[it][u]);
	}
}

int main() {
	int n, m;

	cin >> n >> m;

	while (m--) {
		int x, y;

		scanf("%d %d", &x, &y);
		x--;
		y--;
		ed[0][x].push_back(y);
		ed[1][y].push_back(x);
		e[x].push_back(y);
	}

	for (int i = 0; i < n; i++) {
		if (us[i] == 0) {
			dfs1(i);
		}
	}

	memset(val, -1, sizeof val);

	for (int i = 0; i < n; i++) {
		getv(0, i);
		getv(1, i);
	}

	string ans;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (!used[0][i] && !used[1][i]) {
			posit++;
			int res = bfs(0, i);
			posit++;
			res = min(res, bfs(1, i));
			if (res >= i) {
				ans.push_back('A');
				cnt++;
			}
			else {
				ans.push_back('E');
			}
		}
		else {
			ans.push_back('E');
		}

		dfs(0, i);
		dfs(1, i);
	}

	cout << cnt << '\n';
	cout << ans << '\n';
}