#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q;
	cin >> q;
	while (q--) {
		ll k, x;
		cin >> k >> x;
		cout << x + (k - 1) * 9 << '\n';
	}
	return 0;
}