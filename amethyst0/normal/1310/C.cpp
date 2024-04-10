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
#include <fstream>
#include <bitset>
#include <cstring>
#include <limits.h>
#include <unordered_map>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int maxn = 1010;
vector <pii> ed[maxn];
string s;

const int p = 998244353, q = (int)1e9 + 7;

int add(int x, int y, int mod) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
	return x;
}

int sub(int x, int y, int mod) {
	x -= y;
	if (x < 0) {
		x += mod;
	}
	return x;
}

int mul(int x, int y, int mod) {
	return (ll)x * y % mod;
}

pii operator +(pii a, pii b) {
	a.first = add(a.first, b.first, p);
	a.second = add(a.second, b.second, q);
	return a;
}

pii operator -(pii a, pii b) {
	a.first = sub(a.first, b.first, p);
	a.second = sub(a.second, b.second, q);
	return a;
}

pii operator *(pii a, pii b) {
	a.first = mul(a.first, b.first, p);
	a.second = mul(a.second, b.second, q);
	return a;
}

pii st[maxn];
pii hsh[maxn];

pii get_hsh(int l, int r) {
	return (l == 0 ? hsh[r] : hsh[r] - hsh[l - 1] * st[r - l + 1]);
}

const ll inf = (ll)1e18 + 10;

ll dp[2][maxn];
int lm[maxn];

ll solve(int n, int m, int up) {
	memset(dp, 0, sizeof dp);
	int it = 0;
	dp[it][0] = 1;

	for (int i = 0; i < n; i++) {
		lm[i] = -1;
		for (auto[u, f] : ed[i]) {
			if (f <= up) {
				if (lm[i] == -1) {
					lm[i] = u;
				}
				else {
					lm[i] = min(lm[i], u);
				}
			}
		}
	}

	for (int i = 0; i < m; i++) {
		memset(dp[it ^ 1], 0, sizeof dp[it ^ 1]);

		for (int j = 0; j < n; j++) {
			if (lm[j] == -1) {
				continue;
			}

			dp[it ^ 1][lm[j]] += dp[it][j];
			if (dp[it ^ 1][lm[j]] > inf) {
				dp[it ^ 1][lm[j]] = inf;
			}
		}

		for (int j = 1; j <= n; j++) {
			dp[it ^ 1][j] += dp[it ^ 1][j - 1];
			if (dp[it ^ 1][j] > inf) {
				dp[it ^ 1][j] = inf;
			}
		}

		it ^= 1;
	}

	return dp[it][n];
}

int wh[maxn][maxn];

int main() {
	st[0] = mp(1, 1);

	for (int i = 1; i < maxn; i++) {
		st[i] = st[i - 1] * mp(1234567, 7654321);
	}

	int n, m;
	ll k;

	bool read = true;

	if (read) {
		cin >> n >> m >> k;
		cin >> s;
	}
	else {
		n = 1000, m = 30, k = (ll)1e18;
		for (int i = 0; i < n; i++) {
			s.push_back('a' + rand() % 26);
		}
	}

	pii cur = mp(0, 0);

	for (int i = 0; i < (int)s.size(); i++) {
		cur = cur * st[1];
		cur = cur + mp(s[i] - 'a' + 1, s[i] - 'a' + 1);
		hsh[i] = cur;
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int l = 0;
			int r = n - j;

			while (l != r) {
				int m = (l + r) >> 1;

				if (get_hsh(i, i + m) == get_hsh(j, j + m)) {
					l = m + 1;
				}
				else {
					r = m;
				}
			}

			wh[i][j] = l;
		}
	}

	vector <pii> ord;

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			ord.push_back(mp(i, j));
		}
	}

	sort(all(ord), [&](pii a, pii b) {
		int l = wh[min(a.first, b.first)][max(a.first, b.first)];

		if (a.first + l <= a.second && b.first + l <= b.second) {
			return s[a.first + l] < s[b.first + l];
		}
		else {
			return a.second - a.first < b.second - b.first;
		}
	});

	reverse(all(ord));

	for (int i = 0; i < (int)ord.size(); i++) {
		ed[ord[i].first].push_back(mp(ord[i].second + 1, i));
	}

	int l = 0;
	int r = (int)ord.size() - 1;

	while (l != r) {
		int md = (l + r) >> 1;

		if (solve(n, m, md) < k) {
			l = md + 1;
		}
		else {
			r = md;
		}
	}

	for (int i = ord[l].first; i <= ord[l].second; i++) {
		cout << s[i];
	}

	cout << '\n';
}