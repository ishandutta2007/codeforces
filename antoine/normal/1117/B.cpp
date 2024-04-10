#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(n);
	for (ll &x : a)
		cin >> x;
	sort(a.rbegin(), a.rend());

	const ll ans = m / (k + 1) * (a[0] * k + a[1]) + m % (k + 1) * a[0];
	cout << ans;
	return 0;
}