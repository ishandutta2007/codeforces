#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int query(const int c, const int d) {
	cout << "? " << c << ' ' << d << endl;
	int res;
	cin >> res;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int prev = query(0, 0);
	int a = 0, b = 0;

	for (int m = 1 << 29; m; m >>= 1) {
		const int curr = query(a ^ m, b ^ m);

		if (!curr || curr == prev) { // eq
			if (query(a, b ^ m) == 1) {
				a ^= m;
				b ^= m;
			}
		} else { // diff
			assert(prev);
			if (prev == -1)
				b ^= m;
			else
				a ^= m;
			prev = query(a, b);
		}
	}
	cout << "! " << a << ' ' << b << endl;
	return 0;
}