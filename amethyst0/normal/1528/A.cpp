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
#include <limits.h>
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
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)1e5 + 10;
int l[maxn], r[maxn];
vector <int> ed[maxn];

ll dp[maxn][2];

void go(int v, int p) {
	dp[v][0] = dp[v][1] = 0;

	for (int u : ed[v]) {
		if (u == p) {
			continue;
		}

		go(u, v);

		dp[v][0] += max(dp[u][0] + abs(l[v] - l[u]), dp[u][1] + abs(l[v] - r[u]));
		dp[v][1] += max(dp[u][0] + abs(r[v] - l[u]), dp[u][1] + abs(r[v] - r[u]));
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &l[i], &r[i]);
			ed[i].clear();
		}

		for (int i = 0; i < n - 1; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			x--;
			y--;
			ed[x].push_back(y);
			ed[y].push_back(x);
		}

		go(0, -1);

		printf("%lld\n", max(dp[0][1], dp[0][0]));
	}
}