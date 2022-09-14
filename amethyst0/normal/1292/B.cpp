#pragma comment(linker, "/STACK:1000000000")
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

#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define pll pair <ll, ll>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

vector <pll> g;

ll dst(ll a, ll b) {
	return abs(a) + abs(b);
}

const int maxn = 1010;
const ll inf = (ll)1e18;

ll dp[maxn][maxn][2];
ll xs, ys;

ll go(int l, int r, int tp) {
	if (dp[l][r][tp] != -1) {
		return dp[l][r][tp];
	}

	dp[l][r][tp] = inf;

	if (l == r) {
		dp[l][r][tp] = min(dp[l][r][tp], dst(xs - g[l].first, ys - g[l].second));
	}
	else {
		if (tp == 0) {
			dp[l][r][tp] = min(dp[l][r][tp], go(l + 1, r, 1) + dst(g[r].first - g[l].first, g[r].second - g[l].second));
			dp[l][r][tp] = min(dp[l][r][tp], go(l + 1, r, 0) + dst(g[l + 1].first - g[l].first, g[l + 1].second - g[l].second));
		}
		else {
			dp[l][r][tp] = min(dp[l][r][tp], go(l, r - 1, 0) + dst(g[l].first - g[r].first, g[l].second - g[r].second));
			dp[l][r][tp] = min(dp[l][r][tp], go(l, r - 1, 1) + dst(g[r - 1].first - g[r].first, g[r - 1].second - g[r].second));
		}
	}

	return dp[l][r][tp];
}

int main() {
	ll x0, y0, ax, ay, bx, by;

	cin >> x0 >> y0 >> ax >> ay >> bx >> by;

	ll t;

	cin >> xs >> ys >> t;

	while (true) {
		if (x0 > xs && y0 > ys && dst(xs - x0, ys - y0) > t) {
			break;
		}

		if (dst(xs - x0, ys - y0) <= t) {
			g.push_back(mp(x0, y0));
		}

		x0 = ax * x0 + bx;
		y0 = ay * y0 + by;
	}

	memset(dp, -1, sizeof dp);

	int ans = 0;

	for (int i = 0; i < (int)g.size(); i++) {
		for (int j = i; j < (int)g.size(); j++) {
			for (int tp = 0; tp < 2; tp++) {
				if (go(i, j, tp) <= t) {
					ans = max(ans, j - i + 1);
				}
			}
		}
	}

	cout << ans << endl;
}