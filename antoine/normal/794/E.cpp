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
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<int> ans(n, 0);
	for (int k = 0; k < n; ++k) {
		if (k == n - 1)
			ans[k] = *max_element(a.begin(), a.end());
		else if ((n - k) & 1) {
			for (int c : {(n - k) / 2, (n + k) / 2})
				ans[k] = max(ans[k], min(a[c], max(a[c - 1], a[c + 1])));
		}
		else {
			for (int c : {(n - k) / 2, (n + k) / 2})
				ans[k] = max(ans[k], max(a[c], a[c - 1]));

		}
		if (k > 1)
			ans[k] = max(ans[k], ans[k - 2]);
		cout << ans[k] << ' ';
	}
	// 0 1 2 3
	return 0;
}