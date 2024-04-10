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

const int maxn = 14;
ll dp[maxn][1 << maxn];
ll dp1[1 << maxn];

vector <int> e[1 << maxn];
int ed[maxn];
char s[20];
int cnt[1 << maxn];

int n;

ll num[1 << maxn];

vector <int> bt[2][1 << maxn];

void go(int pos, int x) {
	if (pos == n) {
		num[x] = dp1[(1 << n) - 1];
	}
	else {
		for (int ms : e[pos]) {
			if (dp1[ms] == 0) {
				continue;
			}

			for (int j : bt[1][ms]) {
				dp1[ms | (1 << j)] += dp1[ms];
				dp[j][ms | (1 << j)] += dp1[ms];
			}
		}

		go(pos + 1, x << 1);

		for (int ms : e[pos + 1]) {
			for (int j : bt[0][ms]) {
				dp1[ms] = 0;
				dp[j][ms] = 0;
			}
		}

		for (int ms : e[pos]) {
			for (int i : bt[0][ms]) {
				if (dp[i][ms] == 0) {
					continue;
				}

				for (int j : bt[1][ms]) {
					if ((ed[i] >> j) & 1) {
						dp1[ms | (1 << j)] += dp[i][ms];
						dp[j][ms | (1 << j)] += dp[i][ms];
					}
				}
			}
		}

		go(pos + 1, (x << 1) + 1);

		for (int ms : e[pos + 1]) {
			for (int j : bt[0][ms]) {
				dp1[ms] = 0;
				dp[j][ms] = 0;
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;

		/*for (int j = 0; j < n; j++) {
			if (j == i) {
				s[j] = '0';
			}
			else {
				s[j] = '1';
			}
		}*/

		for (int j = 0; j < n; j++) {
			if (s[j] == '1') {
				ed[i] |= (1 << j);
			}
		}
	}

	cnt[0] = 0;
	e[0].push_back(0);

	dp1[0] = 1;

	for (int i = 1; i < (1 << maxn); i++) {
		cnt[i] = (i & 1) + cnt[i >> 1];
		e[cnt[i]].push_back(i);
	}

	for (int i = 0; i < (1 << maxn); i++) {
		for (int j = 0; j < maxn; j++) {
			if ((i >> j) & 1) {
				bt[0][i].push_back(j);
			}
			else {
				bt[1][i].push_back(j);
			}
		}
	}

	go(0, 0);

	for (int ms = 0; ms < (1 << (n - 1)); ms++) {
		int m = ms ^ ((1 << n) - 1);

		ll ans = num[ms];

		for (int i = m; i > 0; i = (i - 1) & m) {
			if (cnt[i] & 1) {
				ans -= num[ms | i];
			}
			else {
				ans += num[ms | i];
			}
		}

		cout << ans << ' ';
	}
}