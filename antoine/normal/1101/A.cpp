#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q;
	cin >> q;
	while (q--) {
		ll l, r, d;
		cin >> l >> r >> d;

		ll a = (l + d - 1) / d;
		ll b = r / d;

		if (a > b || a > 1) {
			cout << d << '\n';
		} else
			cout << (b + 1) * d << '\n';
	}
	return 0;
}