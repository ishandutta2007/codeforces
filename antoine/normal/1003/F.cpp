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

int strID(const string &s) {
	static map<string, int> mp;
	auto it = mp.find(s);
	if (it != mp.end())
		return it->second;
	int sz = mp.size();
	return mp[s] = sz;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n), cs(n);
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		a[i] = strID(s);
		cs[i] = s.length();
	}

	partial_sum(cs.begin(), cs.end(), cs.begin());

	int res = 0;
	for (int len = 1; len < n; ++len) {
		map<vector<int>, vector<int>> occ;
		for (int i = 0; i + len <= n; ++i)
			occ[vector<int>(a.begin() + i, a.begin() + i + len)].push_back(i);
		for (auto &&x : occ) {
			vector<int> &v = x.second;
			assert(is_sorted(v.begin(), v.end()));
			const int gain = cs[v[0] + len - 1] - (v[0] ? cs[v[0] - 1] : 0) - 1;
			int cnt = 0;
			while (!v.empty()) {
				int x = v.back();
				v.pop_back();
				cnt++;
				while (!v.empty() && v.back() > x - len)
					v.pop_back();
			}
			if (cnt >= 2)
				res = max(res, cnt * gain);
		}
	}
	cout << cs.back() + n - 1 - res;
	return 0;
}