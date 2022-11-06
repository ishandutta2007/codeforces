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
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	int U;
	cin >> n >> U;

	vector<int> a(n);
	set<pair<int, int>> s;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		s.insert({ a[i], i });
	}

	double ans = -1;
	for (int i = 0; i + 2 < n; ++i) {
		auto it = s.upper_bound({ a[i] + U, (int)(1e9) + 1 });
		if (it == s.begin()) continue;
		--it;
		const int j = i + 1;
		const int k = it->second;
		if (k <= j) continue;
		
		double temp = ((double)(a[k] - a[i + 1])) / (a[k] - a[i]);
		ans = max(ans, temp);
	}
	cout << fixed << setprecision(11);
	if (ans < .1)
		cout << -1;
	else
		cout << ans;
	return 0;
}