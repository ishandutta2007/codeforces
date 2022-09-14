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
//#include "sort.h"

#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair

using namespace std;

const int maxn = (int)3e5 + 10;
vector <int> ed[maxn];
vector <int> tp[maxn];
int pos[maxn];
int h[maxn];

void dfs(int v, int p, int hh) {
	h[v] = hh;
	for (int i = 0; i < (int)tp[v].size(); i++) {
		int c = tp[v][i];

		if (pos[c] == -1 || h[pos[c]] > hh) {
			pos[c] = v;
		}
	}

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p) {
			dfs(u, v, hh + 1);
		}
	}
}

int col[maxn];

bool cmp(pii c, pii d) {
	int a = c.first;
	int b = d.first;
	
	if (b == -1) {
		return false;
	}

	if (a == -1) {
		return true;
	}

	return h[a] < h[b];
}

int pre[maxn];
set <int> s[maxn];

int main() {
	memset(pos, -1, sizeof pos);
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int cnt;

		scanf("%d", &cnt);

		tp[i].resize(cnt);

		for (int j = 0; j < cnt; j++) {
			scanf("%d", &tp[i][j]);
		}
	}

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	dfs(1, -1, 0);

	vector <pii> g;

	for (int i = 1; i <= m; i++) {
		g.push_back(mp(pos[i], i));
	}

	sort(g.begin(), g.end(), cmp);

	memset(col, -1, sizeof col);
	memset(pre, -1, sizeof pre);

	int ans = 1;

	for (int i = 0; i < (int)g.size(); i++) {
		if (g[i].first == -1) {
			col[g[i].second] = 0;
			continue;
		}

		if (pre[g[i].first] == -1) {
			vector <int> ch;

			for (int j = 0; j < (int)tp[g[i].first].size(); j++) {
				if (col[tp[g[i].first][j]] != -1) {
					ch.push_back(col[tp[g[i].first][j]]);
					s[g[i].first].insert(ch.back());
				}
			}

			sort(ch.begin(), ch.end());
			ch.resize(unique(ch.begin(), ch.end()) - ch.begin());

			int cl = 0;

			for (int j = 0; j < (int)ch.size(); j++) {
				if (cl != ch[j]) {
					break;
				}

				cl++;
			}

			col[g[i].second] = cl;
			ans = max(ans, cl + 1);
			pre[g[i].first] = cl;
			s[g[i].first].insert(cl);
		} else {
			while (s[g[i].first].count(pre[g[i].first])) {
				pre[g[i].first]++;
			}

			ans = max(ans, pre[g[i].first] + 1);
			s[g[i].first].insert(pre[g[i].first]);
			col[g[i].second] = pre[g[i].first];
		}
	}

	cout << ans << endl;

	for (int i = 1; i <= m; i++) {
		printf("%d ", col[i] + 1);
	}

	return 0;
}