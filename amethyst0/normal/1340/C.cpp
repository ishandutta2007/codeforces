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
#include <unordered_map>
#include <iomanip>

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
#define uint unsigned int

const int maxn = (int)1e4 + 10;

int d[maxn];
int dst[maxn][1010];

int main() {
	int n, m;

	scanf("%d %d", &m, &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &d[i]);
	}

	int g, r;

	scanf("%d %d", &g, &r);

	sort(d, d + n);
	n = unique(d, d + n) - d;

	const int inf = (int)1e9;

	memset(dst, -1, sizeof dst);

	queue <pii> q[2];
	q[0].push(mp(0, g));
	dst[0][g] = 0;
	int it = 0;

	while (true) {
		if (q[it].empty()) {
			break;
		}

		while (!q[it].empty()) {
			int pos = q[it].front().first;
			int c = q[it].front().second;
			q[it].pop();

			if (c == 0 && dst[pos][g] == -1) {
				dst[pos][g] = dst[pos][c] + 1;
				q[it ^ 1].push(mp(pos, g));
			}

			if (pos && d[pos] - d[pos - 1] <= c) {
				int ds = c - (d[pos] - d[pos - 1]);
				if (dst[pos - 1][ds] == -1) {
					q[it].push(mp(pos - 1, ds));
					dst[pos - 1][ds] = dst[pos][c];
				}
			}

			if (pos != n - 1 && d[pos + 1] - d[pos] <= c) {
				int ds = c - (d[pos + 1] - d[pos]);
				if (dst[pos + 1][ds] == -1) {
					q[it].push(mp(pos + 1, ds));
					dst[pos + 1][ds] = dst[pos][c];
				}
			}
		}

		it ^= 1;
	}

	ll ans = (ll)1e18;

	for (int i = 0; i <= g; i++) {
		if (dst[n - 1][i] != -1) {
			ans = min(ans, (ll)(g + r) * dst[n - 1][i] + g - i);
		}
	}

	if (ans == (ll)1e18) {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}
}