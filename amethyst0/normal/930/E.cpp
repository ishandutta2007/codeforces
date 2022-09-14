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
#define ld double

using namespace std;

const int maxn = (int)1e5 + 10, p = (int)1e9 + 7;
pii a[maxn], b[maxn];

int my_pow(int a, int b) {
	if (b == 0) {
		return 1;
	}

	if (b & 1) {
		return (ll)a * my_pow(a, b - 1) % p;
	}

	int z = my_pow(a, b >> 1);

	return (ll)z * z % p;
}

int dp[maxn][2];
int sum[maxn][2];
int len[2];
pii f[2][maxn];

int getsum(int it, int l, int r) {
	int ans = sum[l][it] - sum[r][it];
	if (ans < 0) {
		ans += p;
	}

	return ans;
}

bool cmp(pii a, pii b) {
	return f[a.second][a.first].first < f[b.second][b.first].first;
}

bool cmp1(pii a, pii b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}

	return a.first >= b.first;
}

int main() {
	int k, n, m;

	cin >> k >> n >> m;

	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &b[i].first, &b[i].second);
	}

	sort(a, a + n, cmp1);

	int l = -1;

	int pos = 0;

	for (int i = 0; i < n; i++) {
		if (a[i].first <= l) {
			continue;
		}

		f[0][pos++] = a[i];
		l = a[i].first;
	}

	n = pos;

	l = -1;
	pos = 0;

	sort(b, b + m, cmp1);

	for (int i = 0; i < m; i++) {
		if (b[i].first <= l) {
			continue;
		}

		f[1][pos++] = b[i];
		l = b[i].first;
	}

	m = pos;

	len[0] = n;
	len[1] = m;

	vector <pii> ind;

	sort(f[0], f[0] + len[0]);
	sort(f[1], f[1] + len[1]);

	for (int i = 0; i < n; i++) {
		ind.push_back(mp(i, 0));
	}

	for (int i = 0; i < m; i++) {
		ind.push_back(mp(i, 1));
	}

	sort(ind.begin(), ind.end(), cmp);

	for (int q = (int)ind.size() - 1; q >= 0; q--) {
		int i = ind[q].first;
		int it = ind[q].second;

		int ans = 0;

		int lnk = lower_bound(f[it], f[it] + len[it], mp(f[it][i].second + 1, -1)) - f[it];

		ans += dp[lnk][it];

		if (ans >= p) {
			ans -= p;
		}

		ans += (ll)getsum(it, i + 1, lnk) * my_pow(2, f[it][i].second + 1) % p;

		if (ans >= p) {
			ans -= p;
		}

		lnk = lower_bound(f[it ^ 1], f[it ^ 1] + len[it ^ 1], mp(f[it][i].second + 1, -1)) - f[it ^ 1];

		ans += dp[lnk][it ^ 1];

		if (ans >= p) {
			ans -= p;
		}

		ans = 1 - ans;

		if (ans < 0) {
			ans += p;
		}

		ans = (ll)ans * my_pow(2, p - 1 - (f[it][i].second - f[it][i].first + 1)) % p;

		sum[i][it] = (ll)ans * my_pow(2, p - 1 - f[it][i].first) % p;

		sum[i][it] += sum[i + 1][it];
		if (sum[i][it] >= p) {
			sum[i][it] -= p;
		}

		ans += dp[i + 1][it];

		if (ans >= p) {
			ans -= p;
		}

		dp[i][it] = ans;

		//cout << "!" << it << ' ' << i << ' ' << (ll)dp[i][it] * my_pow(2, k) % p << endl;
	}

	int ans = dp[0][0] + dp[0][1];
	ans %= p;

	ans = (ll)ans * my_pow(2, k) % p;

	ans = my_pow(2, k) - ans;

	if (ans < 0) {
		ans += p;
	}

	cout << ans << endl;

	//system("pause");
}