#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>
#include <array>
#include <queue>

using namespace std;

int n;
const int MaxN = 1e5;
int a[MaxN];
int ans[MaxN];
vector<int> indexes[MaxN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	vector<int> dp;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		auto it = lower_bound(dp.begin(), dp.end(), a[i]);
		indexes[it - dp.begin()].emplace_back(i);
		if (it == dp.end())
			dp.emplace_back(a[i]);
		else
			*it = a[i];
	}

	if (indexes[dp.size() - 1].size() == 1)
		ans[indexes[dp.size() - 1][0]] = 3;
	else
		for (auto &&x : indexes[dp.size() - 1])
			ans[x] = 2;

	for (int i = dp.size() - 2; i >= 0; --i) {
		for (auto &&x : indexes[i]) {
			auto it = lower_bound(indexes[i + 1].begin(), indexes[i + 1].end(), x);
			ans[x] = (it == indexes[i + 1].end() || a[x] >= a[*it]) ? 1 : 2;
		}
		indexes[i].erase(remove_if(indexes[i].begin(), indexes[i].end(), [](const int &x) {
			return ans[x] == 1;
		}), indexes[i].end());
		if (indexes[i].size() == 1)
			ans[indexes[i].back()] = 3;
	}

	for (int i = 0; i < n; ++i)
		cout << ans[i];

	return 0;
}