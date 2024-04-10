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

const int maxn = 510, maxk = 25;
vector <pii> ed[maxn * maxn];
int dp[maxn * maxn][maxk];

const int inf = (int)1e9;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			int x;
			scanf("%d", &x);
			ed[i * m + j].push_back({ i * m + j + 1, x });
			ed[i * m + j + 1].push_back({ i * m + j, x });
		}
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			scanf("%d", &x);
			ed[i * m + j].push_back({ i * m + j + m, x });
			ed[i * m + j + m].push_back({ i * m + j, x });
		}
	}

	if (k & 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("-1 ");
			}
			printf("\n");
		}
		return 0;
	}

	k >>= 1;

	for (int i = 0; i < n * m; i++) {
		dp[i][k] = 0;
	}

	for (int it = k - 1; it >= 0; it--) {
		for (int v = 0; v < n * m; v++) {
			dp[v][it] = inf;
			for (auto[u, w] : ed[v]) {
				dp[v][it] = min(dp[v][it], dp[u][it + 1] + w);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", dp[i * m + j][0] * 2);
		}
		printf("\n");
	}
}