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
#include <unordered_map>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (ll)n; i++)
#define mp make_pair
#define ui unsigned ll

using namespace std;

const int maxn = (int)1e5 + 10;

struct edge {
	int x, y;
	ll f, c;
	int w;

	edge() {

	}

	edge(int x, int y, ll f, ll c, int w): x(x), y(y), f(f), c(c), w(w) {

	}
};

edge mas[maxn];
int posit = 0;
vector <int> ed[maxn];
int iter[maxn];

void add(int x, int y, ll f, ll c, int w) {
	ed[x].push_back(posit);
	mas[posit++] = edge(x, y, f, c, w);
	ed[y].push_back(posit);
	mas[posit++] = edge(y, x, 0, 0, -w);
}

const ll inf = (ll)1e18;

int dst[maxn];
bool used[maxn];
int lnk[maxn];

ll ford(int s, int t) {
	for (int i = s; i <= t; i++) {
		dst[i] = (int)1e9;
		used[i] = false;
	}

	dst[s] = 0;
	used[s] = true;
	queue <int> q;

	q.push(s);

	while (!q.empty()) {
		int v = q.front();
		used[v] = false;
		q.pop();

		for (int i = 0; i < (int)ed[v].size(); i++) {
			int it = ed[v][i];
			int u = mas[it].y;
			
			if (mas[it].f == mas[it].c) {
				continue;
			}

			if (dst[u] > dst[v] + mas[it].w) {
				dst[u] = dst[v] + mas[it].w;
				lnk[u] = it;

				if (!used[u]) {
					q.push(u);
					used[u] = true;
				}
			}
		}
	}

	if (dst[t] == (int)1e9) {
		return (int)1e9;
	}

	ll ans = dst[t];

	int tt = t;
	ll best = (ll)1e18;

	while (t != s) {
		int it = lnk[t];

		best = min(best, mas[it].c - mas[it].f);
		t = mas[it].x;
	}

	t = tt;

	while (t != s) {
		int it = lnk[t];

		mas[it].f += best;
		mas[it ^ 1].f -= best;
		t = mas[it].x;
	}

	return ans * best;
}

int main() {
	int n;

	scanf("%d", &n);

	int s = 0;
	int t = n + 2;

	add(1, t, 0, inf, 0);
	add(n + 1, t, 0, inf, 0);

	int last = 0;

	for (int i = 1; i <= n; i++) {
		int x;

		scanf("%d", &x);

		if (i != 1) {
			int y = x - last;

			if (y <= 0) {
				add(s, i, 0, -y + 1, 0);
			} else {
				add(i, t, 0, y - 1, 0);
			}
		}

		last = x;
	}

	for (int i = 1; i <= n; i++) {
		add(i, i - 1, 0, inf, 1);
		add(i, i + 1, 0, inf, 1);
	}

	ll ans = 0;

	while (true) {
		ll now = ford(s, t);
		if (now == (int)1e9) {
			break;
		}

		ans += now;
	}

	cout << ans << endl;

	return 0;
}