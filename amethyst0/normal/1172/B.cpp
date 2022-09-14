#pragma comment(linker, "/STACK:1000000000")
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

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int maxn = (int)2e5 + 10, mod = 998244353;

vector <int> ed[maxn];
int f[maxn];

int dp[maxn];

int dfs(int v, int p) {
	int cnt = 0;

	int res = 1;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p) {
			cnt++;

			res = (ll)res * dfs(u, v) % mod;
		}
	}

	if (cnt == 0) {
		return dp[v] = 1;
	}

	dp[v] = (ll)res * f[cnt + 1] % mod;

	return dp[v];
}

int main() {
	f[0] = 1;

	for (int i = 1; i < maxn; i++) {
		f[i] = (ll)f[i - 1] * i % mod;
	}

	int n;

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;

		scanf("%d %d", &a, &b);

		ed[a].push_back(b);
		ed[b].push_back(a);
	}

	int x = -1;

	for (int i = 1; i <= n; i++) {
		if ((int)ed[i].size() == 1) {
			x = i;
		}
	}

	dfs(x, -1);

	int v = ed[x][0];

	int res = dp[v];

	cout << (ll)res * n % mod << endl;

	//system("pause");
}