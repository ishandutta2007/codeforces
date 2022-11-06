#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<ll> a(n);
	ll sum = 0;
	for (ll &x : a) {
		cin >> x;
		sum += x;
	}

	sort(a.begin(), a.end());

	int m;
	cin >> m;
	while (m--) {
		int i;
		cin >> i;
		cout << sum - a[n - i] << '\n';

	}
	return 0;
}