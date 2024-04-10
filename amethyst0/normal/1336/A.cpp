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

const int maxn = (int)2e5 + 10;
vector <int> ed[maxn];
int cf[maxn];
int h[maxn];
int sz[maxn];

void dfs(int v, int p, int hh = 0) {
	h[v] = hh;
	sz[v] = 1;

	for (int u : ed[v]) {
		if (u != p) {
			dfs(u, v, hh + 1);
			sz[v] += sz[u];
		}
	}
}

int main() {
	int n, k;

	cin >> n >> k;

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		x--;
		y--;
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	dfs(0, -1);

	vector <pii> g;

	for (int i = 0; i < n; i++) {
		sz[i]--;
		g.push_back(mp(h[i] - sz[i], i));
	}

	sort(all(g));
	reverse(all(g));

	ll ans = 0;

	for (int i = 0; i < k; i++) {
		ans += g[i].first;
	}

	cout << ans << '\n';
}