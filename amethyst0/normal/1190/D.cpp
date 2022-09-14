#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <random>
#include <bitset>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int maxn = (int)2e5 + 10;
pii v[maxn];
int p[maxn];
int g[maxn];

vector <int> t[4 * maxn];

void build(int it, int l, int r) {
	if (l == r) {
		t[it].push_back(g[l]);
	}
	else {
		int m = (l + r) >> 1;

		build(2 * it, l, m);
		build(2 * it + 1, m + 1, r);
		t[it].resize(t[2 * it].size() + t[2 * it + 1].size());
		merge(t[2 * it].begin(), t[2 * it].end(), t[2 * it + 1].begin(), t[2 * it + 1].end(), t[it].begin());
		if (t[it].size() != r - l + 1) {
			throw 1;
		}
	}
}

int go(int it, int l, int r, int lm, int rm, int y) {
	if (l == lm && r == rm) {
		return t[it].end() - lower_bound(t[it].begin(), t[it].end(), y);
	}
	else {
		int m = (l + r) >> 1;

		if (rm <= m) {
			return go(2 * it, l, m, lm, rm, y);
		}
		else if (lm > m) {
			return go(2 * it + 1, m + 1, r, lm, rm, y);
		}
		else {
			return go(2 * it, l, m, lm, m, y) + go(2 * it + 1, m + 1, r, m + 1, rm, y);
		}
	}
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}

	sort(v, v + n);

	p[0] = 0;
	g[0] = v[0].second;

	for (int i = 1; i < n; i++) {
		if (v[i].first == v[i - 1].first) {
			p[i] = p[i - 1];
		}
		else {
			p[i] = p[i - 1] + 1;
		}

		g[p[i]] = max(g[p[i]], v[i].second);
	}

	build(1, 0, p[n - 1]);

	map <int, int> w;

	ll ans = 0;

	for (int i = 0; i < n; i++) {
		int y = v[i].second;

		if (!w.count(y)) {
			ll x = 1, t = 1;

			if (p[i] != 0) {
				x += go(1, 0, p[n - 1], 0, p[i] - 1, y);
			}

			if (p[i] != p[n - 1]) {
				t += go(1, 0, p[n - 1], p[i] + 1, p[n - 1], y);
			}

			ans += x * t;
		}
		else {
			int z = w[y];
			ll x = 1, t = 1;

			if (p[i] - 1 != p[z]) {
				x += go(1, 0, p[n - 1], p[z] + 1, p[i] - 1, y);
			}

			if (p[i] != p[n - 1]) {
				t += go(1, 0, p[n - 1], p[i] + 1, p[n - 1], y);
			}

			ans += x * t;
		}

		w[y] = i;
	}

	cout << ans << endl;

	//system("pause");
	return 0;
}