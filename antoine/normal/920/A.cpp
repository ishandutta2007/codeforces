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

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t;
	cin >> t;
	while (t-- > 0) {
		int n, k;
		cin >> n >> k;
		vector<int> v(k);
		int count = 0;
		for (int i = 0; i < k; ++i)
			cin >> v[i];
		sort(v.begin(), v.end());
		int ans = max(v[0], 1 + n - v.back());
		for (int i = 0; i + 1 < k; ++i) {
			if (v[i] == v[i + 1])
				continue;
			ans = max(ans, 1 + (v[i + 1] - v[i] - 1 + 1) / 2);
		}
		cout << ans << '\n';
	}
	return 0;
}