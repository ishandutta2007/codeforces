#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, X, Y;
	cin >> n >> X >> Y;

	if (X > Y) {
		cout << n;
		return 0;
	}
	vector<int> a(n);
	for (int &x : a)
		cin >> x;

	int ans = 0;

	for (int t = 0; a.size(); t ^= 1) {
		a.erase(remove_if(a.begin(), a.end(), [&](const int &x) {
			return x > X;
		}), a.end());
		sort(a.begin(), a.end());
		if (a.empty())
			break;

		if (t == 0) {
			ans++;
			a.pop_back();
		} else {
			for (int &x : a)
				if (x + Y > x) {
					x += Y;
					break;
				}
		}
	}
	cout << ans;
	return 0;
}