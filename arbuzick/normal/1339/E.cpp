#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	vector<int>st4(30);
	st4[0] = 1;
	for (int i = 1; i < 30; ++i) {
		st4[i] = st4[i - 1] * 4;
	}
	vector<vector<pair<int, int>>> ans(3);
	ans[0].push_back({ 0, 0 });
	ans[0].push_back({ 0, 1 });
	ans[0].push_back({ 1, 0 });
	ans[0].push_back({ 1, 1 });
	ans[1].push_back({ 0, 0 });
	ans[1].push_back({ 1, 0 });
	ans[1].push_back({ 1, 1 });
	ans[1].push_back({ 0, 1 });
	ans[2].push_back({ 0, 0 });
	ans[2].push_back({ 1, 1 });
	ans[2].push_back({ 0, 1 });
	ans[2].push_back({ 1, 0 });
	for (int j = 0; j < t; ++j) {
		int n;
		cin >> n;
		int b = n % 3-1;
		if (b == -1)
			b = 2;
		int x = (n - 1) / 3 + 1;
		int k;
		for(int i = 0; i < 30; ++i)
			if (st4[i] > n) {
				k = i;
				break;
			}
		x -= (st4[k-1] - 1) / 3;
		x -= 1;
		vector<pair<int, int>> a(k);
		for (int i = k-1; i >= 0; --i) {
			if (i == 0) {
				a[i] = ans[b][x % 4 + 1];
			}
			else 
				a[i] = ans[b][x % 4];
			x /= 4;
		}
		int c = 0;
		for (int i = 0; i < k; ++i) {
			c = c * 2 + a[i].first;
			c = c * 2 + a[i].second;
		}
		cout << c << endl;
	}
	return 0;
}