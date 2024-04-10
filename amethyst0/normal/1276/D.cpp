//#pragma comment(linker, "/STACK:1000000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
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
#define pll pair <ll, ll>
#define ld double

using namespace std;

const int maxn = (int)2e5 + 10, mod = 998244353;
vector <pii> ed[maxn];

int dp[maxn][4];

int mul(int x, int y) {
	return (ll)x * y % mod;
}

int add(int x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}

	return x;
}

int sub(int x, int y) {
	x -= y;
	if (x < 0) {
		x += mod;
	}

	return x;
}

int my_pow(int x, int y) {
	int ans = 1;

	while (y) {
		if (y & 1) {
			ans = mul(ans, x);
		}

		y >>= 1;
		x = mul(x, x);
	}

	return ans;
}

vector <pii> g[4];

int sum(int it, int l, int r) {
	if (l > r) {
		return 1;
	}

	if (l == 0) {
		if (g[it][r].second > 0) {
			return 0;
		}

		return g[it][r].first;
	}

	if (g[it][r].second > g[it][l - 1].second) {
		return 0;
	}

	return mul(g[it][r].first, my_pow(g[it][l - 1].first, mod - 2));
}

void go(int v, int p) {
	sort(ed[v].begin(), ed[v].end());

	int pos = (int)ed[v].size();

	for (int i = 0; i < (int)ed[v].size(); i++) {
		if (ed[v][i].second != p) {
			go(ed[v][i].second, v);
		}
		else {
			pos = i;
		}
	}

	for (int i = 0; i < 4; i++) {
		g[i].clear();
	}

	for (int it = 0; it < 4; it++) {
		pii cur = mp(1, 0);
		for (int i = 0; i < (int)ed[v].size(); i++) {
			if (ed[v][i].second != p) {
				if (dp[ed[v][i].second][it] != 0) {
					cur.first = mul(cur.first, dp[ed[v][i].second][it]);
				}
				else {
					cur.second++;
				}
			}

			g[it].push_back(cur);
		}
	}

	dp[v][2] = mul(sum(3, 0, pos - 1), sum(1, pos + 1, (int)ed[v].size() - 1));
	dp[v][0] = sum(3, 0, (int)ed[v].size() - 1);

	for (int i = pos + 1; i < (int)ed[v].size(); i++) {
		int u = ed[v][i].second;
		if (u == p) {
			continue;
		}

		dp[v][0] = add(dp[v][0], mul(sum(3, 0, i - 1), mul(dp[u][0], sum(1, i + 1, (int)ed[v].size() - 1))));
	}

	dp[v][1] = sum(3, 0, (int)ed[v].size() - 1);

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i].second;
		if (u == p) {
			continue;
		}

		dp[v][1] = add(dp[v][1], mul(sum(3, 0, i - 1), mul(dp[u][0], sum(1, i + 1, (int)ed[v].size() - 1))));
	}

	dp[v][3] = mul(sum(3, 0, pos - 1), sum(1, pos + 1, (int)ed[v].size() - 1));

	for (int i = 0; i < pos; i++) {
		int u = ed[v][i].second;

		dp[v][3] = add(dp[v][3], mul(sum(3, 0, i - 1), mul(dp[u][0], sum(1, i + 1, (int)ed[v].size() - 1))));
	}

	for (int it = 0; it < 4; it++) {
		//cout << v << ' ' << it << ' ' << dp[v][it] << endl;
	}
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		ed[x].push_back(mp(i, y));
		ed[y].push_back(mp(i, x));
	}

	go(1, -1);

	cout << dp[1][1] << '\n';

	//system("pause");
}