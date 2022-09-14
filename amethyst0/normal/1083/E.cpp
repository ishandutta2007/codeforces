#pragma comment(linker, "/STACK:1000000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <ctime>
//#include <priority_queue>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ld long double
#define pii pair <int, int>
#define ll long long
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e6 + 10;

ll operator *(pll a, pll b) {
	return a.first * b.first + a.second * b.second;
}

pll operator -(pll a, pll b) {
	a.first -= b.first;
	a.second -= b.second;

	return a;
}

ld operator %(pll a, pll b) {
	return (ld)a.first * b.second - (ld)a.second * b.first;
}

ll dp[maxn];
int x[maxn], y[maxn];
ll a[maxn];

bool cmp(int i, int j) {
	return x[i] < x[j];
}

int main() {
	vector <pll> g;

	int n;

	cin >> n;

	vector <int> f;

	for (int i = 0; i < n; i++) {
		scanf("%d %d %lld", &x[i], &y[i], &a[i]);

		f.push_back(i);
	}

	sort(f.begin(), f.end(), cmp);

	ll ans = 0;

	for (int ii = n - 1; ii >= 0; ii--) {
		int i = f[ii];

		pll v = mp(x[i], 1);

		if (g.empty()) {
			dp[ii] = 0;
		}
		else {
			ll res = 0;

			int l = 0, r = (int)g.size() - 1;

			while (l != r) {
				int m = (l + r) >> 1;

				if (g[m] * v < g[m + 1] * v) {
					l = m + 1;
				}
				else {
					r = m;
				}
			}

			res = max(res, g[l] * v);

			dp[ii] = res;
		}

		v = mp(-y[i], dp[ii] + (ll)x[i] * y[i] - a[i]);

		while ((int)g.size() >= 2 && (g.back() - g[(int)g.size() - 2]) % (v - g[(int)g.size() - 2]) <= 0) {
			g.pop_back();
		}

		g.push_back(v);
	}

	for (int ii = 0; ii < n; ii++) {
		int i = f[ii];
		ans = max(ans, dp[ii] + (ll)x[i] * y[i] - a[i]);
	}

	cout << ans << endl;

	//system("pause");

	return 0;
}