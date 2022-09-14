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
#include <cstdio>
#include <cassert>
#include <cstring>
#include <unordered_set>

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
vector <int> ed[maxn];
int used[maxn];

bool dfs(int v) {
	used[v] = 1;

	for (int u : ed[v]) {
		if (used[u] == 1) {
			return true;
		}
		if (used[u] == 0) {
			if (dfs(u)) {
				return true;
			}
		}
	}

	used[v] = 2;
	return false;
}

int dp[maxn];

int go(int v) {
	if (dp[v] != -1) {
		return dp[v];
	}

	dp[v] = 0;

	for (int u : ed[v]) {
		if (u < v) {
			dp[v] = max(dp[v], go(u));
		}
		else {
			dp[v] = max(dp[v], go(u) + 1);
		}
	}

	return dp[v];
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			ed[i].clear();
			used[i] = 0;
			dp[i] = -1;
		}

		for (int i = 0; i < n; i++) {
			int k;
			scanf("%d", &k);

			for (int j = 0; j < k; j++) {
				int x;
				scanf("%d", &x);
				x--;
				ed[i].push_back(x);
			}
		}

		bool ok = false;

		for (int i = 0; i < n; i++) {
			if (used[i] == 0) {
				ok |= dfs(i);
			}
		}

		if (ok) {
			printf("-1\n");
			continue;
		}

		int ans = 0;

		for (int i = 0; i < n; i++) {
			ans = max(ans, go(i));
		}

		printf("%d\n", ans + 1);
	}
}