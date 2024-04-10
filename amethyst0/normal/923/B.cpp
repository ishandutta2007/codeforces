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

const int maxn = (int)1e5 + 10;
int v[maxn], t[maxn];

ll sum[maxn];

ll get_sum(int l, int r) {
	if (l == 0) {
		return sum[r];
	}

	return sum[r] - sum[l - 1];
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	ll now = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);

		now += t[i];

		sum[i] = now;
	}

	vector <pair <pair <int, ll>, int> > g;

	for (int i = 0; i < n; i++) {
		g.push_back(mp(mp(i, v[i]), 1));

		int l = i;
		int r = n;

		while (l != r) {
			int m = (l + r) >> 1;

			if (get_sum(i, m) >= v[i]) {
				r = m;
			}
			else {
				l = m + 1;
			}
		}

		g.push_back(mp(mp(l, v[i] - get_sum(i, l - 1)), -1));
	}

	sort(g.begin(), g.end());

	ll ans = 0;
	int cnt = 0;

	int pos = 0;

	for (int i = 0; i < n; i++) {
		ll cur = 0;


		while (pos < (int)g.size() && g[pos].first.first == i) {
			if (g[pos].second == 1) {
				ans += g[pos].first.second;
				cnt++;
			}
			else {
				cur += g[pos].first.second;
				ans -= g[pos].first.second;
				cnt--;
			}

			pos++;
		}

		ans -= (ll)t[i] * cnt;

		printf("%lld ", (ll)t[i] * cnt + cur);
	}

	//system("pause");
}