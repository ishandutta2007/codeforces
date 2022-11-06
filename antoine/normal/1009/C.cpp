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
	cin.tie(0);
	cout.tie(0);
	
	cout << fixed << setprecision(10);

	int n, m;
	cin >> n >> m;

	ll maxSum = 0, minSum = 0;

	for (int i = 0; i < n; ++i) {
		maxSum += i;
		minSum += abs(i - n / 2);
	}

	long double ans = 0;
	for (int i = 0; i < m; ++i) {
		long double x, d;
		cin >> x >> d;
		ans += x * n + max(d * maxSum, d * minSum);
	}
	cout << ans / n;
	return 0;
}