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
#include <stack>

using namespace std;


int diameter(const vector<int> &v) {
	if (v.empty())
		return 0;
	return *max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end());
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, d;
	cin >> n >> d;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	int ans = 1e9;
	for (int i = 0; i < v.size(); ++i) {
		vector<int> u(v.begin() + i, v.end());
		while (diameter(u) > d)
			u.pop_back();
		ans = min(ans, (int)v.size() - (int)u.size());
	}
	cout << ans;
	return 0;
}