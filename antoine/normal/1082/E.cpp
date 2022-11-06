#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, c;
	cin >> n >> c;
	vector<int> a(n);
	for(int &x : a)
		cin >> x;

	int ans = 0;
	map<int, int> dp;
	int lazy = 0;

	for(const int &x : a) {
		if(x == c)
			--lazy;
		else {
			int y = dp[x] + lazy;
			y = max(0, y) + 1;
			ans = max(ans, y);
			dp.at(x) = y - lazy;
		}
	}

	ans += count(a.begin(), a.end(), c);
	cout << ans << '\n';
	return 0;
}