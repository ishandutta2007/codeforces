#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a) {
		cin >> x;
		x = abs(x);
	}

	sort(a.begin(), a.end());

	ll ans = 0;
	for (int i = 0, j = 0; j < n; ++j) {
		while (i < j && a[i] < (a[j] + 1) / 2)
			++i;
		ans += j - i;
	}
	cout << ans;

	return 0;
}