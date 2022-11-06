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


	int n, k;
	cin >> n >> k;
	vector<double> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	vector<double> cs(n);
	partial_sum(a.begin(), a.end(), cs.begin());

	double ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; ++j)
			if (j - i + 1 >= k)
				ans = max(ans, (cs[j] - (i ? cs[i - 1] : 0.0)) / (j - i + 1));
	cout << fixed << setprecision(11);
	cout << ans;
	return 0;
}