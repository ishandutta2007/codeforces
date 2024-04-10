#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <stack>

using namespace std;
typedef long long ll;

vector<pair<int, char>> adj[100];
int dp[100][100][27];

bool f(int i, int j, int k) {
	if (dp[i][j][k] != -1)
		return dp[i][j][k];
	for (auto &&x : adj[i])
		if (x.second >= 'a' + k && !f(j, x.first, x.second - 'a'))
			return dp[i][j][k] = true;
	return dp[i][j][k] = false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	memset(dp, -1, sizeof dp);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		char z;
		cin >> x >> y >> z;
		--x, --y;
		adj[x].emplace_back(y, z);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			cout << (char)(!f(i, j, 0) + 'A');
		cout << '\n';
	}
	return 0;
}