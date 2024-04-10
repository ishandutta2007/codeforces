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

	for (int &x : a)
		cin >> x;
	const int total = accumulate(a.begin(), a.end(), 0);

	int curr = 0, cnt = 0;
	for (int i = 0; i < n; ++i)
		if (i == 0 || a[i] * 2 <= a[0]) {
			curr += a[i];
			cnt++;
		}

	if (curr * 2 <= total)
		cout << 0;
	else {
		cout << cnt << '\n';

		for (int i = 0; i < n; ++i)
			if (i == 0 || a[i] * 2 <= a[0]) {
				cout << i + 1 << ' ';
			}
	}
	return 0;
}