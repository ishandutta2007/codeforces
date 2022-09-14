#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <memory.h>
#include <cstring>
#include <queue>
#include <set>
#include <string>

using namespace std;

#define pii pair <int, int>
#define mp make_pair
#define ll long long

const int maxn = (int)2e5 + 10;
vector <int> ed[maxn];
int w[maxn];

int c[maxn];
bool used[maxn];

vector <int> red[maxn];

ll nw[maxn];
int cnt[maxn];

ll go(int v, int p) {
	ll ans = nw[v];

	ll res = 0;

	for (int i = 0; i < (int)red[v].size(); i++) {
		int u = red[v][i];

		if (u != p) {
			res = max(res, go(u, v));
		}
	}

	return ans + res;
}

int pr[maxn];

void make(int v, int p) {
	pr[v] = p;

	for (int i = 0; i < (int)red[v].size(); i++) {
		int u = red[v][i];

		if (u != p) {
			make(u, v);
		}
	}
}

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	set <pii> q;

	for (int i = 1; i <= n; i++) {
		c[i] = 0;
		cnt[i] = (int)ed[i].size();
		q.insert(mp(cnt[i], i));
	}

	int s;

	cin >> s;

	if (m != n - 1) {
		while (!q.empty()) {
			int v = q.begin()->second;
			q.erase(q.begin());

			if (cnt[v] >= 2) {
				break;
			}

			c[v] = v;
			for (int i = 0; i < (int)ed[v].size(); i++) {
				int u = ed[v][i];

				if (cnt[u] > 1) {
					q.erase(mp(cnt[u], u));
					cnt[u]--;
					q.insert(mp(cnt[u], u));
				}
			}
		}
	}
	else {
		for (int i = 1; i <= n; i++) {
			c[i] = i;
		}
	}

	for (int i = 1; i <= n; i++) {
		nw[c[i]] += w[i];
		for (int j = 0; j < (int)ed[i].size(); j++) {
			int u = ed[i][j];
			int x = c[i];
			int y = c[u];

			if (x != y) {
				red[x].push_back(y);
			}
		}
	}

	if (m == n - 1) {
		cout << go(c[s], -1) << endl;
	}
	else {
		make(0, -1);

		int x = c[s];
		ll ans = 0;

		while (x != 0) {
			ans += nw[x];
			nw[x] = 0;
			x = pr[x];
		}

		cout << ans + go(0, -1) << endl;
	}
	
	//system("pause");

	return 0;
}