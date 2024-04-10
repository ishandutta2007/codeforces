#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

void f() {
	int n, k;
	cin >> n >> k;
	vector<int> v;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (x & 1)
			v.push_back(i);
	}

	if ((int) v.size() < k || (int) v.size() % 2 != k % 2) {
		cout << "NO\n";
		return;
	}
	v.resize(k);
	v.back() = n;
	cout << "YES\n";
	for(int i : v)
		cout << i << ' ';
	cout << '\n';
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		f();
	}
	return 0;
}