#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

void f() {
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;
	sort(a.begin(), a.end());

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		bool ok = false;
		for (int j = 0; j < i; ++j)
			if (a[i] % a[j] == 0)
				ok = true;
		cnt += !ok;
	}
	cout << cnt;

	return 0;
}