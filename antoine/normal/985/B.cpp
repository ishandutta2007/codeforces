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
	vector<string> a(n);
	vector<int> dp(m, 0);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 0; j < m; ++j)
			dp[j] += a[i][j] == '1';
	}
	for (int i = 0; i < n; ++i) {
		bool ans = true;
		for (int j = 0; j < m; ++j)
			if (a[i][j] == '1' && dp[j] == 1)
				ans = false;
		if(ans) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}