#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <ctime>

#define mp make_pair
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)1e5 + 10, maxlog = 20, sq = 400;
int par[maxlog][maxn];
int tin[maxn], tout[maxn];
int tt = -1;
vector <int> ed[maxn];

void dfs(int v, int p) {
	par[0][v] = p;

	for (int i = 1; i < maxlog; i++) {
		par[i][v] = par[i - 1][par[i - 1][v]];
	}

	tin[v] = ++tt;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		dfs(u, v);
	}

	tout[v] = tt;
}

int anc(int x, int y) {
	return tin[x] <= tin[y] && tout[y] <= tout[x];
}

int lca(int x, int y) {
	if (anc(x, y)) {
		return x;
	}

	for (int i = maxlog - 1; i >= 0; i--) {
		if (!anc(par[i][x], y)) {
			x = par[i][x];
		}
	}

	return par[0][x];
}

int s[maxn];
bool in[maxn];

bool cmp(int x, int y) {
	return tin[x] < tin[y];
}

bool us[maxn];

vector <int> cur;
int pr[maxn];
bool is[maxn];

bool make(int v) {
	is[v] = us[v];

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (make(u)) {
			is[v] = true;
		}
	}

	return is[v];
}

vector <pii> g[maxn];
int st[maxn];
int ps[maxn];

int answer = 0;

void build(int v, int p) {
	if (!is[v]) {
		return;
	}

	if (!us[v]) {
		if (in[v]) {
			cur.push_back(s[v]);
		}

		for (int i = 0; i < (int)ed[v].size(); i++) {
			int u = ed[v][i];

			if (is[u]) {
				build(u, p);
			}
		}
	}
	else {
		sort(cur.begin(), cur.end());
		st[v] = 0;
		g[v].clear();

		for (int i = 0; i < (int)cur.size(); ) {
			int r = i;

			while (r < (int)cur.size() && cur[r] == cur[i]) {
				r++;
			}

			g[v].push_back(mp(cur[i], r - i));
			i = r;
		}

		ps[v] = -1;

		while (ps[v] < (int)g[v].size() - 1 && g[v][ps[v] + 1].first < st[v]) {
			ps[v]++;
		}

		pr[v] = p;

		cur.clear();

		for (int i = 0; i < (int)ed[v].size(); i++) {
			int u = ed[v][i];

			build(u, v);
		}
	}
}

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 2; i <= n; i++) {
		int p;

		scanf("%d", &p);
		//p = i - 1;
		ed[p].push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &s[i]);
		//s[i] = 0;
		in[i] = true;
	}

	dfs(1, 1);

	for (int it = 0; it < m; it += sq) {
		memset(us, 0, sizeof us);

		vector <int> v;
		vector <int> z;

		for (int j = it; j < min(m, it + sq); j++) {
			int x;

			scanf("%d", &x);
			//x = rand() % 10 + n - 10;
			x = abs(x);
			v.push_back(x);
			us[x] = true;
		}

		z = v;

		sort(v.begin(), v.end(), cmp);

		for (int i = 0; i < (int)v.size() - 1; i++) {
			int x = v[i];
			int y = v[i + 1];
			int l = lca(x, y);

			us[l] = true;
		}

		make(1);
		build(1, -1);

		for (int i = 0; i < (int)v.size(); i++) {
			int x = z[i];

			int dx = 1;

			if (in[x]) {
				dx = -1;
			}

			in[x] = !in[x];

			if (s[x] < 0 && in[x]) {
				answer++;
			}

			if (s[x] < 0 && !in[x]) {
				answer--;
			}

			while (x != -1) {
				if (in[x]) {
					answer -= (s[x] < 0);
				}

				s[x] += dx;

				if (in[x]) {
					answer += (s[x] < 0);
				}

				if (dx == 1) {
					st[x]--;

					if (ps[x] != -1 && g[x][ps[x]].first == st[x]) {
						answer -= g[x][ps[x]].second;
						ps[x]--;
					}
				}
				else {
					st[x]++;

					if (ps[x] + 1 != (int)g[x].size() && g[x][ps[x] + 1].first < st[x]) {
						ps[x]++;
						answer += g[x][ps[x]].second;
					}
				}

				x = pr[x];
			}

			printf("%d\n", answer);
		}

		for (int i = 1; i <= n; i++) {
			if (!us[i]) {
				continue;
			}

			int rt = pr[i];

			int x = i;

			while (true) {
				if (x == par[0][x]) {
					break;
				}

				x = par[0][x];

				if (x == rt) {
					break;
				}

				s[x] -= st[i];
			}
		}
	}

	//system("pause");
}