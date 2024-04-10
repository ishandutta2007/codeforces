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

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int > dp;
	int ans = -1;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		dp[a[i]] = dp[a[i] - 1] + 1;
		if (dp[a[i]] > dp[ans])
			ans = a[i];
	}

	cout << dp[ans] << '\n';
	int curr = ans - dp[ans] + 1;
	for(int i = 0; i < n; ++i)
		if (a[i] == curr) {
			cout << i + 1 << ' ';
			curr++;
		}
	return 0;
}