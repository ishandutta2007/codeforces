#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll &x : a)
		cin >> x;
	sort(a.begin(), a.end());

	ll ans = 0;
	for (int i = 0, j = n - 1; i < j; ++i, --j)
		ans += (a[i] + a[j]) * (a[i] + a[j]);
	cout << ans;
	return 0;
}