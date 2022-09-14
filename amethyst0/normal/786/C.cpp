/*AMETHYSTS*/
//#pragma comment(linker, "/STACK:1000000000")
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

#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair

using namespace std;

const int maxn = (int)1e5 + 10;
vector <pair <int, pii> > t[4 * maxn];
int v[maxn];

void build(int it, int l, int r) {
	if (l == r) {
		t[it].push_back(mp(v[l], mp(0, 0)));
	} else {
		int m = (l + r) >> 1;

		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);

		int a = 0;
		int b = 0;

		pii now = mp(-1, -1);

		while (a != t[2 * it].size() || b != t[2 * it + 1].size()) {
			if (b == (int)t[2 * it + 1].size()) {
				now.first = a;
				t[it].push_back(mp(t[2 * it][a].first, now));
				a++;
			} else if (a == (int)t[2 * it].size()) {
				now.second = b;
				t[it].push_back(mp(t[2 * it + 1][b].first, now));
				b++;
			} else if (t[2 * it][a].first < t[2 * it + 1][b].first) {
				now.first = a;
				t[it].push_back(mp(t[2 * it][a].first, now));
				a++;
			} else {
				now.second = b;
				t[it].push_back(mp(t[2 * it + 1][b].first, now));
				b++;
			}
		}
	}
}

int go(int it, int l, int r, int lm, int rm, int w, int &d) {
	if (l == r) {
		if (w + 1 <= d) {
			d -= w + 1;
			return r + 1;
		} else {
			return r;
		}
	} else if (l == lm && r == rm) {
		if (w + 1 <= d) {
			d -= w + 1;
			return r + 1;
		}

		int lit = -1, rit = -1;

		if (w != -1) {
			lit = t[it][w].second.first;
			rit = t[it][w].second.second;
		}

		int m = (l + r) >> 1;

		int ans = go(2 * it, l, m, lm, m, lit, d);

		if (ans == m + 1) {
			ans = go(2 * it + 1, m + 1, r, m + 1, rm, rit, d);
		}

		return ans;
	} else {
		int lit = -1, rit = -1;

		if (w != -1) {
			lit = t[it][w].second.first;
			rit = t[it][w].second.second;
		}

		int m = (l + r) >> 1;

		if (rm <= m) {
			return go(2 * it, l, m, lm, rm, lit, d);
		} else if (lm > m) {
			return go(2 * it + 1, m + 1, r, lm, rm, rit, d);
		} else {
			int ans = go(2 * it, l, m, lm, m, lit, d);
			if (ans == m + 1) {
				ans = go(2 * it + 1, m + 1, r, m + 1, rm, rit, d);
			}

			return ans;
		}
	}
}

int main() {
	int n;

	cin >> n;

	map <int, int> m;

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);
		//x = rand() % n + 1;

		if (!m.count(x)) {
			v[i] = -1;
		} else {
			v[i] = m[x];
		}

		m[x] = i;
	}

	build(1, 0, n - 1);

	for (int d = 1; d <= n; d++) {
		int pos = 0;
		int ans = 0;

		while (pos != n) {
			ans++;

			int x = d;

			pos = go(1, 0, n - 1, pos, n - 1, lower_bound(t[1].begin(), t[1].end(), mp(pos, mp(-1, -1))) - t[1].begin() - 1, x);
		}

		printf("%d ", ans);
	}

	return 0;
}