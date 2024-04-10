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

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int maxn = (int)2e5 + 10;
vector <pii> a, b;

vector <pair <pii, int> > w;

ll t[4 * maxn];
ll st[4 * maxn];

void sets(int it, int x) {
	t[it] += x;
	st[it] += x;
}

void push(int it) {
	if (st[it] != 0) {
		sets(2 * it, st[it]);
		sets(2 * it + 1, st[it]);
		st[it] = 0;
	}
}

void change(int it, int l, int r, int lm, int rm, int x) {
	if (l == lm && r == rm) {
		sets(it, x);
	}
	else {
		int m = (l + r) >> 1;
		push(it);

		if (rm <= m) {
			change(2 * it, l, m, lm, rm, x);
		}
		else if (lm > m) {
			change(2 * it + 1, m + 1, r, lm, rm, x);
		}
		else {
			change(2 * it, l, m, lm, m, x);
			change(2 * it + 1, m + 1, r, m + 1, rm, x);
		}

		t[it] = max(t[2 * it], t[2 * it + 1]);
	}
}

int main() {
	int n, m, p;

	cin >> n >> m >> p;

	for (int i = 0; i < n; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		a.push_back(mp(x, y));
	}

	for (int i = 0; i < m; i++) {
		int x, y;

		scanf("%d %d", &x, &y);
		b.push_back(mp(x, y));
	}

	sort(all(a));
	sort(all(b));

	for (int i = 0; i < m; i++) {
		change(1, 0, m - 1, i, i, -b[i].second);
	}

	for (int i = 0; i < p; i++) {
		int x, y, c;

		scanf("%d %d %d", &x, &y, &c);
		w.push_back(mp(mp(x, y), c));
	}

	sort(all(w));

	int pos = 0;

	ll ans = (ll)-1e18;

	for (int i = 0; i < n; i++) {
		while (pos < p && w[pos].first.first < a[i].first) {
			int x = w[pos].first.second;

			int ps = lower_bound(all(b), mp(x + 1, -1)) - b.begin();

			if (ps < m) {
				change(1, 0, m - 1, ps, m - 1, w[pos].second);
			}

			pos++;
		}

		ans = max(ans, t[1] - a[i].second);
	}

	cout << ans << '\n';
}