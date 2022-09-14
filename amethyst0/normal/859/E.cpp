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
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <unordered_map>
#include <random>

#define ll long long
#define ld double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10, mod = (int)1e9 + 7;
int p[maxn];
int used[maxn];
bool cyc[maxn];
vector <int> ed[maxn];

int ans = 1;

int gen(int x) {
	used[x] = 1;

	int y = p[x];

	if (y == -1) {
		used[x] = 2;
		return -1;
	}

	if (used[y] == 0) {
		int z = gen(y);

		if (z != -1) {
			cyc[x] = true;
			if (z == x) {
				z = -1;
			}
		}

		used[x] = 2;
		return z;
	}

	if (used[y] == 1) {
		ans *= 2;

		if (ans >= mod) {
			ans -= mod;
		}

		cyc[x] = true;
		used[x] = 2;
		return y;
	}

	used[x] = 2;
	return -1;
}

bool fl[maxn];
int dp[maxn][2];

int go_sz(int v) {
	int ans = 1;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		ans += go_sz(u);
	}

	return ans;
}

int main() {
	int n;

	cin >> n;

	memset(p, -1, sizeof p);

	for (int i = 1; i <= n; i++) {
		int x;

		scanf("%d", &x);

		scanf("%d", &p[x]);

		fl[x] = true;
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (i == p[i]) {
			used[i] = 2;
			cyc[i] = true;
			continue;
		}
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (used[i] == 0) {
			gen(i);
		}
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (p[i] != -1) {
			if (!cyc[p[i]]) {
				ed[p[i]].push_back(i);
			}
		}
	}

	memset(dp, -1, sizeof dp);

	for (int i = 1; i <= 2 * n; i++) {
		if (p[i] == -1) {
			ans = (ll)ans * go_sz(i) % mod;
		}
	}

	cout << ans << endl;

	return 0;
}