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
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		ans += t*a[i];
		if (t) a[i] = 0;
	}
	ll sum = 0;
	ll maxSum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		if (i - k >= 0)
			sum -= a[i - k];
		maxSum = max(maxSum, sum);
	}
	cout << ans + maxSum;
	return 0;
}