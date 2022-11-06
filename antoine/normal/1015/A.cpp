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
	int n, m;
	cin >> n >> m;
	vector<int> a(m + 1, 0);
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		a[l]++;
		a[r + 1]--;
	}
	partial_sum(a.begin(), a.end(), a.begin());
	vector<int> ans;
	for (int i = 0; i < m; ++i)
		if (!a[i])
			ans.push_back(i);
	cout << ans.size() << endl;
	for (auto &&x : ans)
		cout << x  + 1 << ' ';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	f();
	return 0;
}