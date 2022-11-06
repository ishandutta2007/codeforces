#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;
	partial_sum(a.begin(), a.end(), a.begin());

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		int sum = a[--r] - (--l ? a[l - 1] : 0);
		cout << sum / 10 << '\n';
	}
	return 0;
}