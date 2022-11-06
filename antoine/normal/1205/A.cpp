#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	vector<int> a(2 * n);
	for (int i = 0; i < n; ++i) {
		a[i] = 2 * i + 1;
		a[i + n] = 2 * i + 2;
		if (i & 1)
			swap(a[i], a[i + n]);
	}
	for (int x : a)
		cout << x << ' ';
	return 0;
}