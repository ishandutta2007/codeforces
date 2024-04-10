#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) {
		cin >> x;
		if (x >= 0)
			x = -x - 1;
	}
	if (n & 1) {
		auto &&x = *min_element(a.begin(), a.end());
		x = -x - 1;
	}
	for (int x : a)
		cout << x << ' ';
	return 0;
}