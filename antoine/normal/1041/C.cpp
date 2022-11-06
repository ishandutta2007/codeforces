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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n; ll m, d;
	cin >> n >> m >> d;
	
	set<pair<ll, int>> s;

	vector<ll> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s.emplace(a[i], i);
	}
	
	int day = 0;
	
	vector<int> ans(n, -1);
	for(; !s.empty(); ++day) {
		for (auto it = s.begin(); it != s.end();) {
			ans[it->second] = day;
			ll curr = it->first;
			s.erase(it);
			it = s.lower_bound({ curr + d + 1, -1 });
		}
	}

	cout << day << '\n';
	for (auto &&x : ans) {
		assert(x != -1);
		cout << x + 1 << ' ';
	}
	return 0;
}