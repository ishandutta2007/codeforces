#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q;
	cin >> q;
	while (q--) {
		ll n, a, b;
		cin >> n >> a >> b;
		b = min(b, a << 1);
		cout << n / 2 * b + n % 2 * a << '\n';
	}
	return 0;
}