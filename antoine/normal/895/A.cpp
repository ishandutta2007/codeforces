#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int main() {


	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int ans = 360;
	for (int i = 0; i < n; ++i) {
		rotate(a.begin(), a.begin() + 1, a.end());
		int sum = 0;
		for (int j = 0; sum < 180; ++j)
			sum += a[j];
		ans = min(ans, sum - (360 - sum));
	}
	cout << ans;
	return 0;
}