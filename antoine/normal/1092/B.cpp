#include <bits/stdc++.h>

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

	int ans = 0;
	for (int i = 0; i < n; i += 2)
		ans += a[i + 1] - a[i];

	cout << ans;
	return 0;
}