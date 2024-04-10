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

int countNZ(vector<int> &a) {
	int count = 0;
	for (auto &&x : a)
		count += x != 0;
	return count;
}

vector<int> lis(vector<int> &a) {
	vector<int> dp = { a[0] };
	vector<int> res(a.size(), 1);
	for (int i = 1; i < a.size(); ++i) {
		auto it = upper_bound(dp.begin(), dp.end(), a[i]);
		if (it == dp.end())
			dp.push_back(a[i]);
		else
			dp[it - dp.begin()] = a[i];
		res[i] = dp.size();
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> a(m);
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		++a[l];
		if (r + 1 < m)
			--a[r + 1];
	}

	for (int i = 1; i < m; ++i)
		a[i] += a[i - 1];

	if (countNZ(a) <= 1) {
		cout << (m - 1);
		return 0;
	}

	auto aR = a;
	reverse(aR.begin(), aR.end());

	auto res = lis(a);
	auto resR = lis(aR);
	reverse(resR.begin(), resR.end());

	int ans = max(res.back(), resR.back());
	for (int i = 0; i + 1 < m; ++i)
		ans = max(ans, res[i] + resR[i + 1]);

	cout << ans;
	return 0;
}