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
#undef NDEBUG
#include <assert.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, K;
	cin >> n >> K;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a.begin(), a.end());
	int ans = n;
	for (int i = 0, j = 1; j < n; ++i) {
		while (j < n && a[i] == a[j])
			++j;
		ans -= j < n && a[j] <= a[i] + K;
	}
	cout << ans;
	return 0;
}