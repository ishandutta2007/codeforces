#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool f(vector<pair<int, int>> &v) {
	int x = 0;
	for (auto p : v)
		x ^= p.second;
	if (!x)
		return false;

	cout << "TAK\n";
	for (auto p : v)
		cout << p.first << ' ';
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> res1, res2;

	bool diff = false;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			int x;
			cin >> x;
			if (j == 1) {
				res1.push_back( { 1, x });
				res2.push_back( { 1, x });
			} else if (x != res1.back().second && !diff) {
				res2.back() = {j, x};
			}
		}
		diff |= res1.back() != res2.back();
	}

	if (!f(res1) && !f(res2))
		cout << "NIE";

	return 0;
}