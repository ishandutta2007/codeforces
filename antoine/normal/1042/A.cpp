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


int ceil(int a, int b) {
	return (a + b - 1) / b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	const int minA = *min_element(a.begin(), a.end());
	const int maxA = *max_element(a.begin(), a.end());
	const int sumA = accumulate(a.begin(), a.end(), 0);

	const int ans1 = max(maxA, ceil(sumA + m, n));
	const int ans2 = maxA + m;
	cout << ans1 << ' ' << ans2 << '\n';
	return 0;
}