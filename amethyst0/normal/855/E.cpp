/*AMETHYSTS*/
#include <cstdio>
#include <fstream>
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
#include <unordered_set>
#include <random>

#define ll long long
#define ld long double
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair
#define ui unsigned ll
#define pll pair <ll, ll>

using namespace std;

ll dp[70][1 << 10][11][2];

ll go(int pos, int mask, int b, int z) {
	if (dp[pos][mask][b][z] != -1) {
		return dp[pos][mask][b][z];
	}

	if (pos == 0) {
		return dp[pos][mask][b][z] = (mask == 0 && z != 0);
	}

	ll ans = 0;

	for (int i = 0; i < b; i++) {
		if (z == 0 && i == 0) {
			ans += go(pos - 1, mask, b, 0);
		} else {
			ans += go(pos - 1, mask ^ (1 << i), b, 1);
		}
	}

	return dp[pos][mask][b][z] = ans;
}

ll solve(ll x, int b) {
	vector <int> z;

	if (x == 0) {
		return 0;
	}

	while (x != 0) {
		z.push_back(x % b);
		x /= b;
	}

	reverse(z.begin(), z.end());

	ll ans = 0;

	int mask = 0;

	for (int i = 0; i < (int)z.size(); i++) {
		for (int j = 0; j < z[i]; j++) {
			if (i == 0 && j == 0) {
				ans += go((int)z.size() - i - 1, mask, b, 0);
			} else {
				ans += go((int)z.size() - i - 1, mask ^ (1 << j), b, 1);
			}
		}

		mask ^= (1 << z[i]);
	}

	if (mask == 0) {
		return ans + 1;
	}

	return ans;
}

int main() {
	memset(dp, -1, sizeof dp);

	int q;

	cin >> q;

	while (q--) {
		ll l, r;
		int b;

		scanf("%d %lld %lld", &b, &l, &r);

		ll ans = solve(r, b) - solve(l - 1, b);

		printf("%lld\n", ans);
	}

	return 0;
}