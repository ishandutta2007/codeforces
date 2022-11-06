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
	string s, t;
	cin >> n >> s >> t;
	if (multiset<char>(s.begin(), s.end()) != multiset<char>(t.begin(), t.end())) {
		cout << -1;
		return;
	}
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		int j = i;
		while (s[j] != t[i]) assert(++j < n);
		while (j > i) {
			ans.push_back(--j);
			swap(s[j], s[j + 1]);
		}
	}
	cout << ans.size() << '\n';
	for (auto &&x : ans)
		cout << x + 1 << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	f();
	return 0;
}