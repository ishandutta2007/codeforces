#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;
	sort(a.begin(), a.end());

	const int sum = accumulate(a.begin(), a.end(), 0);
	int ans = sum;

	for (int i = 0; i < n; ++i) {
		for (int d = 1; d <= a[i]; ++d)
			if (a[i] % d == 0)
				ans = min(ans, sum - a[i] + a[i] / d - a[!i] + a[!i] * d);
	}
	cout << ans;
	return 0;
}