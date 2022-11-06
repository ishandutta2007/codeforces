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


	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];

	}

	ll sum1 = 0, sum3 = 0, ans = 0;
	for (int i = 0, j = n - 1;; ++i) {
		sum1 += a[i];
		while (i < j && sum1 > sum3)
			sum3 += a[j--];
		if (i > j) break;
		if (sum1 == sum3)
			ans = sum1;
	}
	cout << ans;
	return 0;
}