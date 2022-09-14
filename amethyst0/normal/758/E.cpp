/*AMETHYSTS*/
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
#include <unordered_set>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10;

vector <pair <pii, pii> > ed[maxn];
ll z[maxn];
ll ww[maxn];
int xx[maxn], yy[maxn], pp[maxn], we[maxn];

ll ans = 0;

pll go(int v, int pr = -1) {
	pll sum = mp(0, 0);

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i].first.first;
		int w = ed[v][i].second.first;
		int p = ed[v][i].second.second;

		if (u == pr) {
			continue;
		}

		pll f = go(u, v);

		if (p < f.first) {
			cout << -1 << endl;
			exit(0);
		}

		ans += max(0ll, f.second - p);

		if (f.second > p) {
			z[u] = f.second - p;
			f.second = p;
		}

		ww[abs(ed[v][i].first.second)] = w - max(1ll, w - p + f.first);

		sum.second += f.second + w;
		sum.first += f.first + max(1ll, w - p + f.first);
	}

	return sum;
}

ll make(int v, ll cnt = 0, int pr = -1) {
	cnt += z[v];

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i].first.first;

		if (u == pr) {
			continue;
		}

		cnt = make(u, cnt, v);

		if (ww[abs(ed[v][i].first.second)] > cnt) {
			ww[abs(ed[v][i].first.second)] = cnt;
			cnt = 0;
		} else {
			cnt -= ww[abs(ed[v][i].first.second)];
		}
	}

	return cnt;
}

int main() {
	int n;

	cin >> n;

	for (int i = 1; i < n; i++) {
		int x, y, w, p;

		scanf("%d %d %d %d", &x, &y, &w, &p);

		xx[i] = x;
		yy[i] = y;
		pp[i] = p;
		we[i] = w;

		ed[x].push_back(mp(mp(y, i), mp(w, p)));
		ed[y].push_back(mp(mp(x, -i), mp(w, p)));
	}

	go(1);

	cout << n << endl;

	make(1);

	for (int i = 1; i < n; i++) {
		printf("%d %d %I64d %I64d\n", xx[i], yy[i], we[i] - ww[i], pp[i] - ww[i]);
	}

	return 0;
}