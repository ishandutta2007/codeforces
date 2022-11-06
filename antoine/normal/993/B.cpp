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

int common(pair<int, int> p1, pair<int, int> p2) {
	set<int> s{ p2.first, p2.second };
	return s.count(p1.first) ? p1.first : p1.second;
}

bool valid(pair<int, int> p1, pair<int, int> p2) {
	set<int> s{ p2.first, p2.second };
	return (int)s.count(p1.first) + (int)s.count(p1.second) == 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> v1(n), v2(m);
	for (int i = 0; i < n; ++i)
		cin >> v1[i].first >> v1[i].second;
	for (int i = 0; i < m; ++i)
		cin >> v2[i].first >> v2[i].second;

	int ans= -2;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (valid(v1[i], v2[j])) {
				int c = common(v1[i], v2[j]);
				if (ans == -1) break;
				if (ans == -2) ans = c;
				else if (ans != c)
					ans = -1;
			}

	assert(ans != -2);
	if (ans > 0) {
		cout << ans;
		return 0;
	}


	for (int i = 0; i < n; ++i) {
		int ans = -2;
		for (int j = 0; j < m; ++j)
			if (valid(v1[i], v2[j])) {
				int c = common(v1[i], v2[j]);
				if (ans == -1) break;
				if (ans == -2) ans = c;
				else if (ans != c)
					ans = -1;
			}
		if (ans == -1) {
			cout << -1;
			return 0;
		}
	}


	for (int j = 0; j < m; ++j) {
		int ans = -2;
		for (int i = 0; i < n; ++i)
			if (valid(v1[i], v2[j])) {
				int c = common(v1[i], v2[j]);
				if (ans == -1) break;
				if (ans == -2) ans = c;
				else if (ans != c)
					ans = -1;
			}
		if (ans == -1) {
			cout << -1;
			return 0;
		}
	}

	cout << 0;
	return 0;
}