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
#define ld long double

using namespace std;

const int maxn = (int)2e5 + 10;
pii v[maxn];
int n;

pii trans(int x, int y) {
	return mp((x + y) >> 1, (y - x) >> 1);
}

pii g[2][2 * maxn];

ll go() {
	vector <pair <pii, int> > a, b;

	for (int i = 0; i < n; i++) {
		if ((v[i].first + v[i].second) & 1) {
			a.push_back(mp(trans(v[i].first + 1, v[i].second), 0));
			a.push_back(mp(trans(v[i].first, v[i].second + 1), 1));

			b.push_back(mp(trans(v[i].first - 1, v[i].second), 1));
			b.push_back(mp(trans(v[i].first, v[i].second - 1), 0));
		}
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ll ans = 0;

	int l = (int)1e9;
	int r = -(int)1e9;

	int pos = 0;

	for (int i = -maxn; i < maxn; i++) {
		while (pos < (int)a.size() && a[pos].first.first == i) {
			if (a[pos].second == 0) {
				r = max(r, a[pos].first.second);
			}
			else {
				l = min(l, a[pos].first.second);
			}

			pos++;
		}

		g[0][i + maxn] = mp(l, r);
	}

	l = (int)1e9;
	r = -(int)1e9;

	pos = (int)b.size() - 1;

	for (int i = maxn - 1; i >= -maxn; i--) {
		while (pos >= 0 && b[pos].first.first == i) {
			if (b[pos].second == 0) {
				r = max(r, b[pos].first.second);
			}
			else {
				l = min(l, b[pos].first.second);
			}

			pos--;
		}

		g[1][i + maxn] = mp(l, r);
	}

	for (int i = 0; i < 2 * maxn; i++) {
		int l = max(g[0][i].first, g[1][i].first);
		int r = min(g[0][i].second, g[1][i].second);

		if (l <= r) {
			ans += r - l + 1;
		}
	}

	return ans;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}

	ll ans = go();

	for (int i = 0; i < n; i++) {
		v[i].first++;
	}

	ans += go();

	cout << ans << endl;

	//system("pause");
}