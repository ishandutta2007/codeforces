/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <fstream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <map>
#include <unordered_map>
#define ld double
#define mp make_pair
#define ll long long
#define pii pair <int, int>

using namespace std;

const int maxn = (int)1e5 + 10;

vector <int> ed[maxn];
int h[maxn];
int it;
int c[maxn];
vector <int> ver[maxn];
int dst[maxn];

int dfs(int v, int p) {
	h[v] = 0;
	c[v] = it;
	ver[it - 1].push_back(v);

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p) {
			h[v] = max(h[v], dfs(u, v) + 1);
		}
	}

	return h[v];
}

void make(int v, int p, int g) {
	dst[c[v] - 1] = max(dst[c[v] - 1], h[v] + g);
	h[v] = max(h[v], g);

	vector <int> z;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p) {
			z.push_back(h[u]);
		}
	}

	sort(z.rbegin(), z.rend());

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p) {
			if (h[u] != z[0]) {
				make(u, v, max(g + 1, z[0] + 2));
			} else {
				if ((int)z.size() == 1) {
					make(u, v, g + 1);
				} else {
					make(u, v, max(g + 1, z[1] + 2));
				}
			}
		}
	}
}

vector <int> d[maxn];
vector <ll> sum[maxn];

map <pii, ld> res;

int main() {
	int n, m, q;

	cin >> n >> m >> q;

	for (int i = 0; i < m; i++) {
		int a, b;

		scanf("%d %d", &a, &b);

		ed[a].push_back(b);
		ed[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (c[i] == 0) {
			it++;
			dfs(i, -1);
			make(i, -1, 0);
		}
	}

	for (int i = 0; i < it; i++) {
		for (int j = 0; j < (int)ver[i].size(); j++) {
			d[i].push_back(h[ver[i][j]]);
		}

		sort(d[i].begin(), d[i].end());

		sum[i].assign(d[i].size(), 0);

		ll now = 0;

		for (int j = (int)d[i].size() - 1; j >= 0; j--) {
			now += d[i][j];

			sum[i][j] = now;
		}
	}

	for (int i = 0; i < q; i++) {
		int a, b;

		scanf("%d %d", &a, &b);

		if (c[a] == c[b]) {
			printf("-1\n");
			continue;
		}

		a = c[a] - 1;
		b = c[b] - 1;

		if (ver[a].size() > ver[b].size()) {
			swap(a, b);
		}

		if (ver[a].size() == ver[b].size() && a > b) {
			swap(a, b);
		}

		if (res.count(mp(a, b))) {
			printf("%.10lf\n", res[mp(a, b)]);
			continue;
		}

		ld ans = 0;

		int ds = max(dst[a], dst[b]);

		for (int i = 0; i < (int)d[a].size(); i++) {
			int pos = lower_bound(d[b].begin(), d[b].end(), ds - d[a][i]) - d[b].begin();

			ans += (ld)ds / (int)d[a].size() * pos;
			ans += (ld)(d[a][i] + 1) / (int)d[a].size() * ((int)d[b].size() - pos);

			if (pos != (int)d[b].size()) {
				ans += (ld)sum[b][pos] / (int)d[a].size();
			}
		}

		printf("%.10lf\n", ans / (int)d[b].size());

		res[mp(a, b)] = ans / (int)d[b].size();
	}

	return 0;
}