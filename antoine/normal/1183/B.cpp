#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

void f() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;
	sort(a.begin(), a.end());

	int res = min(a[0] + k, a.back() + k);
	if (res < a.back() - k)
		res = -1;
	cout << res << '\n';
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int q;
	cin >> q;
	while (q--)
		f();
	return 0;
}