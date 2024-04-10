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
#include <memory>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int n, m;
ll a[20][20];
map<ll, int> dp1[20][20];
map<ll, int> dp2[20][20];

void dfs1(int x, int y, int d, ll xxor) {
	xxor ^= a[x][y];
	if (d == 0) {
		++dp1[x][y][xxor];
	}
	else {
		if (x + 1 < n)
			dfs1(x + 1, y, d - 1, xxor);
		if (y + 1 < m)
			dfs1(x, y + 1, d - 1, xxor);
	}
}

void dfs2(int x, int y, int d, ll xxor) {
	if (d == 0) {
		++dp2[x][y][xxor];
	}
	else {
		xxor ^= a[x][y];
		if (x)
			dfs2(x - 1, y, d - 1, xxor);
		if (y)
			dfs2(x, y - 1, d - 1, xxor);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	a[0][0] ^= k;

	dfs1(0, 0, (n + m - 2) / 2, 0);
	dfs2(n - 1, m - 1, (n + m - 1) / 2, 0);


	ll ans = 0;
	for(int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			for (auto &&x : dp1[i][j])
				ans += (ll)x.second * (ll)dp2[i][j][x.first];
	cout << ans;
	
	return 0;
}