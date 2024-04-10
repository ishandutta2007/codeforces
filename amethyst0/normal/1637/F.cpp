//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
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
#include <cstdio>
#include <cassert>
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

const int maxn = (int)2e5 + 10;
int h[maxn];
vector <int> ed[maxn];
ll dp[maxn][2];

ll ans = 0;

int go(int v, int p) {
	int best = 0;
	int sbest = 0;

	int to = -1;
	ll s = 0;

	for (int u : ed[v]) {
		if (u == p) {
			continue;
		}

		auto x = go(u, v);
		s += dp[u][1];

		if (x > best) {
			sbest = best;
			best = x;
			to = u;
		}
		else if (x > sbest) {
			sbest = x;
		}
	}

	if (h[v] < best) {
		dp[v][0] = min(s - dp[to][1] + dp[to][0], s + best - sbest);
		dp[v][1] = s;
	}
	else if (to == -1) {
		dp[v][0] = (ll)1e18;
		dp[v][1] = h[v];
	}
	else {
		dp[v][0] = dp[v][1] = s;

		dp[v][0] += h[v] - best;
		dp[v][0] += h[v] - sbest;
		dp[v][1] += h[v] - best;
	}
	return max(best, h[v]);
}

int main() {
	int n;
	scanf("%d", &n);

	int root = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);

		if (h[i] > h[root]) {
			root = i;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		x--;
		y--;
		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	go(root, -1);
	cout << dp[root][0] << '\n';
}