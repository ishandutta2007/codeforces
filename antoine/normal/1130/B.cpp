#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int d(int x, int y) {
	return abs(x - y);
}
int d(vector<int> a, vector<int> b) {
	assert(a.size() == 2 && b.size() == 2);
	return min(d(a[0], b[0]) + d(a[1], b[1]), d(a[0], b[1]) + d(a[1], b[0]));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> pos(n + 1);
	pos[0] = {1, 1};

	for (int i = 1; i <= 2 * n; ++i) {
		int x;
		cin >> x;
		pos[x].push_back(i);
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += d(pos[i], pos[i + 1]);
	}
	cout << ans;
	return 0;
}