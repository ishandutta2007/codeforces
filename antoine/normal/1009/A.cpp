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

	int n, m;
	cin >> n >> m;
	vector<int> c(n), a(m);
	for (int i = 0; i < n; ++i)
		cin >> c[i];
	for (int j = 0; j < m; ++j)
		cin >> a[j];

	int i = 0, j = 0, ans = 0;
	while (i < n && j < m) {
		if (c[i] <= a[j]) {
			++ans;
			++i;
			++j;
		}
		else
			++i;
	}
	cout << ans;
	return 0;
}