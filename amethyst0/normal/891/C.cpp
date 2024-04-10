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
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)5e5 + 10;
vector <pii> z[maxn];
bool ans[maxn];
pair <pii, int> e[maxn], eg[maxn];

bool cmp(pair <pii, int> a, pair <pii, int> b) {
	return a.second < b.second;
}

int p[maxn];

int get_parent(int x) {
	return p[x] = (x == p[x] ? x : get_parent(p[x]));
}

int it[maxn];
int cur = 0;
int par[maxn];

int get_par(int x) {
	if (it[x] != cur) {
		it[x] = cur;
		par[x] = x;
	}

	if (x == par[x]) {
		return x;
	}

	return par[x] = get_par(par[x]);
}

void check(int w) {
	for (int i = 0; i < (int)z[w].size(); ) {
		int r = i;

		while (r < (int)z[w].size() && z[w][r].second == z[w][i].second) {
			r++;
		}

		cur++;
		for (int j = i; j < r; j++) {
			int num = z[w][j].first;

			int px = get_par(get_parent(e[num].first.first));
			int py = get_par(get_parent(e[num].first.second));

			if (px == py) {
				ans[z[w][i].second] = 1;
				break;
			}

			par[px] = py;
		}

		i = r;
	}
}

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, w;

		scanf("%d %d %d", &x, &y, &w);
		e[i] = mp(mp(x, y), w);
		eg[i] = mp(mp(x, y), w);
	}

	sort(eg, eg + m, cmp);

	int q;

	cin >> q;

	for (int i = 0; i < q; i++) {
		int h;

		scanf("%d", &h);

		for (int j = 0; j < h; j++) {
			int x;

			scanf("%d", &x);
			x--;

			z[e[x].second].push_back(mp(x, i));
		}
	}

	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}

	for (int i = 0; i < m; ) {
		int r = i;

		while (r < m && eg[r].second == eg[i].second) {
			r++;
		}

		check(eg[i].second);

		for (int j = i; j < r; j++) {
			int px = eg[j].first.first;
			int py = eg[j].first.second;

			px = get_parent(px);
			py = get_parent(py);

			p[px] = py;
		}

		i = r;
	}

	for (int i = 0; i < q; i++) {
		if (ans[i] == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
}