//#pragma comment(linker, "/STACK:1000000000")
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
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double

using namespace std;

const int maxn = 16;
vector <int> g[maxn];

void panic() {
	cout << "No\n";
	//system("pause");
	exit(0);
}

ll sum[maxn];

map <ll, int> nx;
ll f = 0;

bool ok[1 << maxn];
int start[1 << maxn], val[1 << maxn];

int dp[1 << maxn];

int dfs(int mask) {
	if (dp[mask] != -1) {
		return dp[mask];
	}

	if (mask == 0) {
		return dp[mask] = 0;
	}

	dp[mask] = -2;

	for (int ms = mask; ms > 0; ms = (ms - 1) & mask) {
		if (ok[ms] && dfs(mask ^ ms) != -2) {
			dp[mask] = ms;
			break;
		}
	}

	return dp[mask];
}

ll giv[maxn];
int wh[maxn];

void print(int mask) {
	if (mask == 0) {
		return;
	}

	int ms = dp[mask];
	print(mask ^ ms);

	int v = start[ms];
	ll x = val[ms];

	while (ms != 0) {
		x = f - (sum[v] - x);
		ms ^= (1 << v);
		int u = nx[x];

		giv[u] = x;
		wh[u] = v;
		v = u;
	}
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int k;

		cin >> k;

		g[i].resize(k);

		for (int j = 0; j < k; j++) {
			scanf("%d", &g[i][j]);
			f += g[i][j];
			sum[i] += g[i][j];
			nx[g[i][j]] = i;
		}

		sort(g[i].begin(), g[i].end());
	}

	if (abs(f) % n != 0) {
		panic();
	}

	f /= n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)g[i].size(); j++) {
			ll x = g[i][j];
			int msk = (1 << i);

			int v = i;

			while (true) {
				x = f - (sum[v] - x);
				if (!nx.count(x)) {
					break;
				}

				int u = nx[x];

				if ((msk >> u) & 1) {
					if (u == i && x == g[i][j]) {
						ok[msk] = true;
						start[msk] = i;
						val[msk] = g[i][j];
					}

					break;
				}
				else {
					msk |= (1 << u);
				}

				v = u;
			}
		}
	}

	memset(dp, -1, sizeof dp);

	if (dfs((1 << n) - 1) == -2) {
		panic();
	}

	cout << "Yes\n";

	print((1 << n) - 1);

	for (int i = 0; i < n; i++) {
		cout << giv[i] << ' ' << wh[i] + 1 << '\n';
	}

	//system("pause");
	return 0;
}