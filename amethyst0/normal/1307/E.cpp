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

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>
#define uint int

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int maxn = 5010, mod = (int)1e9 + 7;
int cnt[maxn];
vector <int> wh[maxn];
int num[maxn];
int dp[2][maxn];
int le[maxn];
int s[maxn];

int add(int x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
	return x;
}

int mul(int x, int y) {
	return (ll)x * y % mod;
}

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x;

		cin >> x;
		s[i] = x;
		cnt[x]++;
		wh[x].push_back(i);
	}

	vector <pii> g;

	for (int i = 0; i < m; i++) {
		int x, y;

		cin >> x >> y;
		g.push_back(mp(x, y));
	}

	sort(all(g));

	int numb = 0;
	int ans = 0;

	for (int d = 0; d <= n; d++) {
		if (d != 0) {
			dp[0][d] = 1;
		}
		else {
			dp[1][d] = 1;
		}

		num[d] = 0;

		int l = 0;

		memset(le, 0, sizeof le);

		for (int i = 0; i < d; i++) {
			le[s[i]]++;
		}

		while (l < m) {
			int r = l;
			int t = g[l].first;
			int numl = 0;
			int numr = 0;
			int numlr = 0;

			while (r < m && g[r].first == t) {
				if (g[r].second <= le[t]) {
					numl++;
				}

				if (g[r].second <= cnt[t] - le[t]) {
					numr++;
				}

				if (g[r].second <= le[t] && g[r].second <= cnt[t] - le[t]) {
					numlr++;
				}

				r++;
			}

			if (numl == 0 && numr == 0) {
				l = r;
				continue;
			}

			if (numl == 0 || numr == 0 || (numlr == 1 && numl == 1 && numr == 1)) {
				num[d]++;

				int cf = 0;
				int cf1 = 0;

				for (int i = l; i < r; i++) {
					int x = g[i].second;

					if (x <= le[t] && wh[t][x - 1] + 1 == d) {
						cf++;
					}
					
					if ((x <= le[t] && wh[t][x - 1] + 1 != d)) {
						cf1++;
					}

					if (x <= cnt[t] - le[t]) {
						cf1++;
					}
				}

				dp[1][d] = add(mul(dp[1][d], cf1 + cf), mul(dp[0][d], cf));
				dp[0][d] = mul(dp[0][d], cf1);
			}
			else {
				num[d] += 2;

				ll cf = 0;
				ll cf1 = 0;

				for (int i = l; i < r; i++) {
					int x = g[i].second;
					int z = 0;

					if (x <= le[t] && x <= cnt[t] - le[t]) {
						z = 1;
					}

					if (x <= le[t] && wh[t][x - 1] + 1 == d) {
						cf += numr - z;
					}

					if (x <= le[t] && wh[t][x - 1] + 1 != d) {
						cf1 += numr - z;
					}
				}

				cf %= mod;
				cf1 %= mod;

				dp[1][d] = add(mul(dp[1][d], (int)cf1 + (int)cf), mul(dp[0][d], (int)cf));
				dp[0][d] = mul(dp[0][d], (int)cf1);
			}

			l = r;
		}

		if (num[d] > numb) {
			numb = num[d];
			ans = dp[1][d];
		}
		else if (num[d] == numb) {
			ans = add(ans, dp[1][d]);
		}
	}

	cout << numb << ' ' << ans << endl;
}