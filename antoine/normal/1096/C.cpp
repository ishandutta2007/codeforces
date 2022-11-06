#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int x, y = 180;
		cin >> x;
		const int g = gcd(x, y);
		x /= g, y /= g;
		cout << (y-x == 1 ? 2 : 1) * y << '\n';
	}
	return 0;
}