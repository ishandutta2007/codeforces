#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>

#define ll long long

using namespace std;

const int maxn = (int)1e5 + 10, maxm = 12;

int v[maxm][maxn];
int ps[maxm][maxn];

int dp[maxn];

int n, m;

int go(int x) {
	if (dp[x] != -1) {
		return dp[x];
	}
	
	if (ps[0][x] == n - 1) {
		return dp[x] = 1;
	}
	
	int el = v[0][ps[0][x] + 1];
	
	bool fl = true;
	
	for (int i = 1; i < m; i++) {
		if (ps[i][x] + 1 != ps[i][el]) {
			fl = false;
			break;
		}
	}
	
	if (!fl) {
		return dp[x] = 1;
	} else {
		return dp[x] = 1 + go(el);
	}
}

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &v[i][j]);
			v[i][j]--;
			ps[i][v[i][j]] = j;
		}
	}
	
	memset(dp, -1, sizeof dp);

	ll ans = 0;
	
	for (int i = 0; i < n; i++) {
		ans += go(i);
	}
	
	cout << ans << endl;
	
	return 0;
}