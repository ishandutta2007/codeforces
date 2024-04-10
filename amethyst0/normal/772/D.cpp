/*AMETHYSTS*/
#pragma comment(linker, "/STACK:1000000000")
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
//#include "sort.h"

#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define mp make_pair

using namespace std;

const int maxn = (int)1e6 - 1, mod = (int)1e9 + 7;
int cnt[maxn + 1];
ll sum[maxn + 1];
ll sumsq[maxn + 1];
ll sumo[maxn + 1];
int st[6];

void push(int x, int y, int pos, int cn, int now) {
	if (pos == 6) {
		if (now == x) {
			return;
		}

		if (cn == 1) {
			sum[now] = (sum[now] + sum[x]) % mod;
			sumsq[now] = (sumsq[now] + sumsq[x]) % mod;
			sumo[now] = sumo[now] + sumo[x];
		} else {
			sum[now] = (sum[now] - sum[x]);
			sumsq[now] = (sumsq[now] - sumsq[x]);
			sumo[now] = sumo[now] - sumo[x];

			if (sum[now] < 0) {
				sum[now] += mod;
			}

			if (sumsq[now] < 0) {
				sumsq[now] += mod;
			}
		}
	} else {
		int z = y % 10;
		push(x, y / 10, pos + 1, cn, now + z * st[pos]);
		if (z != 0) {
			push(x, y / 10, pos + 1, cn ^ 1, now + (z - 1) * st[pos]);
		}
	}
}

ll ans[maxn + 1];

void go(int x, int y, int pos, int cn, int now) {
	if (pos == 6) {
		if (now == x) {
			return;
		}

		if (cn == 1) {
			ans[x] -= ans[now];
			if (ans[x] < 0) {
				ans[x] += mod;
			}
		} else {
			ans[x] += ans[now];

			if (ans[x] >= mod) {
				ans[x] -= mod;
			}
		}
	} else {
		int z = y % 10;
		go(x, y / 10, pos + 1, cn, now + z * st[pos]);
		if (z != 9) {
			go(x, y / 10, pos + 1, cn ^ 1, now + (z + 1) * st[pos]);
		}
	}
}

ll my_pow(ll a, ll b) {
	if (b == 0) {
		return 1;
	}

	if (b & 1) {
		return a * my_pow(a, b - 1) % mod;
	}

	ll z = my_pow(a, b >> 1);

	return z * z % mod;
}

ll m[maxn + 10];

int main() {
	m[0] = 1;
	st[0] = 1;
	for (int i = 1; i < 6; i++) {
		st[i] = st[i - 1] * 10;
	}

	for (int i = 1; i < maxn + 10; i++) {
		m[i] = m[i - 1] * 2;

		if (m[i] >= mod) {
			m[i] -= mod;
		}
	}

	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;

		scanf("%d", &x);

		cnt[x]++;
	}

	for (int i = maxn; i >= 0; i--) {
		sumo[i] = (sumo[i] + cnt[i]) % mod;
		sum[i] = (sum[i] + (ll)i * cnt[i]) % mod;
		sumsq[i] = (sumsq[i] + (ll)((ll)i * i % mod) * cnt[i]) % mod;

		if (sumo[i] != 0) {
			push(i, i, 0, 0, 0);
		}
	}

	ll res = 0;

	for (int i = maxn; i >= 0; i--) {
		ll sq = sumsq[i];
		ll sums = (sum[i] * sum[i] - sumsq[i]);
		sums %= mod;

		if (sums < 0) {
			sums += mod;
		}

		ll o = sumo[i];
		
		if (o > 1) {
			ans[i] = (sq * m[o - 1] + sums * m[o - 2]);
			ans[i] %= mod;
		} else if (o == 1) {
			ans[i] = sq;
		}

		ll h = ans[i];

		go(i, i, 0, 0, 0);

		res ^= ans[i] * i;

		ans[i] = h;
	}

	cout << res << endl;

	return 0;
}