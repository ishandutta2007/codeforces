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
#define forn(i, n) for (int i = 0; i < (ll)n; i++)
#define mp make_pair
#define ui unsigned ll

using namespace std;

const int maxn = (int)1e5 + 10;
vector <int> ed[maxn];
int x[maxn], y[maxn], w[maxn], b[maxn];
bool used[maxn];
ll dst[maxn];

ll ford(int s, int t, int n) {
	for (int i = 0; i <= n; i++) {
		dst[i] = (ll)1e18;
		used[i] = false;
	}

	queue <int> q;

	dst[s] = 0;
	q.push(s);
	used[s] = true;

	while (!q.empty()) {
		int v = q.front();
		used[v] = false;
		q.pop();

		for (int i = 0; i < (int)ed[v].size(); i++) {
			int it = ed[v][i];
			int u = x[it];
			if (u == v) {
				u = y[it];
			}

			int d = w[it];

			if (dst[u] > dst[v] + d) {
				dst[u] = dst[v] + d;

				if (!used[u]) {
					used[u] = true;
					q.push(u);
				}
			}
		}
	}

	return dst[t];
}

int main() {
	int cnt = 0;

	int n, m, f, s, t;

	cin >> n >> m >> f >> s >> t;

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x[i], &y[i], &w[i]);

		ed[x[i]].push_back(i);
		ed[y[i]].push_back(i);

		if (w[i] == 0) {
			cnt++;
			b[i] = 1;
		}
	}

	ll l = -1;
	ll r = (ll)cnt * f;

	while (l != r) {
		ll mm = (l + r + 1) >> 1;

		ll sum = mm;

		for (int i = 0; i < m; i++) {
			if (b[i]) {
				w[i] = 1 + (int)min(sum, (ll)f);
				sum -= min(sum, (ll)f);
			}
		}

		ll now = ford(s, t, n);

		if (now == f) {
			printf("YES\n");
			for (int i = 0; i < m; i++) {
				printf("%d %d %d\n", x[i], y[i], w[i]);
			}
			return 0;
		}

		if (now > f) {
			r = mm - 1;
		} else {
			l = mm;
		}
	}

	cout << "NO" << endl;

	return 0;
}