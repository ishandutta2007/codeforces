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
#include <fstream>
#include <bitset>
#include <cstring>
#include <limits.h>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

const int maxn = (int)2e5 + 10;
vector <int> ed[maxn];
int dst[2][maxn];
int g[maxn];

int n;

void bfs(int v, int tp) {
	for (int i = 1; i <= n; i++) {
		dst[tp][i] = -1;
	}

	dst[tp][v] = 0;
	queue <int> q;
	q.push(v);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		for (int u : ed[v]) {
			if (dst[tp][u] == -1) {
				dst[tp][u] = dst[tp][v] + 1;
				q.push(u);
			}
		}
	}
}

int main() {
	int m, k;

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		scanf("%d", &g[i]);
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	bfs(1, 0);
	bfs(n, 1);

	sort(g, g + k, [&](int a, int b) {
		return dst[0][a] < dst[0][b];
	});

	int ans = 0;

	int val = -(int)1e9;

	for (int i = k - 1; i >= 0; i--) {
		int x = g[i];

		ans = max(ans, dst[0][x] + val + 1);
		val = max(val, dst[1][x]);
	}

	ans = min(ans, dst[0][n]);

	cout << ans << '\n';
}