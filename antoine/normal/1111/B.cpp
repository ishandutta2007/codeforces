#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k, m;
	cin >> n >> k >> m;
	vector<ll> a(n);
	for (ll &x : a)
		cin >> x;

	sort(a.begin(), a.end());
	partial_sum(a.rbegin(), a.rend(), a.rbegin());

	double ans = 0;
	for (int i = 0; i < n && i <= m; ++i)
		ans = max(ans, (a[i] + min<ll>((ll)k * (n - i), m - i)) / double(n - i));
	cout << fixed << setprecision(10) << ans;
	return 0;
}