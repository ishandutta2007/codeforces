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
	vector<int> x(n), h(n);

	for (int i = 0; i < n; ++i)
		cin >> x[i] >> h[i];

	int ans = min(n, 2);
	for (int i = 1; i + 1 < n; ++i)
		if (x[i] - x[i - 1] > h[i])
			ans++;
		else if (x[i + 1] - x[i] > h[i]) {
			x[i] += h[i];
			ans++;
		}
		cout << ans;
		return 0;
}