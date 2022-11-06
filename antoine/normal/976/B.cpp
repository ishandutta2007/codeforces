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
#include <assert.h>

using namespace std;
typedef long long ll;

pair<int, int> f() {
	ll n, m, k;
	cin >> n >> m >> k;
	if (k < n)
		return{ 1 + k, 1 };
	k -= n;
	int row = n - k / (m - 1);
	k %= 2 * (m - 1);
	int col = k < m - 1 ? 2 + k : m - (k - (m - 1));
	return{ row, col };
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	auto res = f();
	cout << res.first << ' ' << res.second;

	return 0;
}