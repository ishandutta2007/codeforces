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

void f() {
	int n;
	cin >> n;
	map<int, int> occ;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++occ[x];
	}
	for (auto it = occ.begin(); it != occ.end();) {
		if (it->second >= 4) {
			for (int i = 0; i < 4; ++i)
				cout << it->first << " \n"[i == 3];
			return;
		}
		if (it->second == 1)
			it = occ.erase(it);
		else
			++it;
	}
	assert(occ.size() >= 2);

	vector<int> ans;
	double ansCost;

	for (auto it = occ.begin(); it != occ.end() && next(it) != occ.end(); ++it) {
		auto it2 = next(it);
		const double cost = (double)it->first / it2->first + (double)it2->first / it->first;
		if (ans.empty() || cost < ansCost) {
			ansCost = cost;
			ans = { it->first, it->first, it2->first, it2->first };
		}
	}
	assert(!ans.empty());
	for (auto &&x : ans)
		cout << x << ' ';
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T;
	cin >> T;
	while (T--) f();
	return 0;
}