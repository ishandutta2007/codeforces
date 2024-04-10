#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

int get(int x) {
	cout << "? " << x + 1 << endl;
	int res;
	cin >> res;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int l = 0;
	int r = n - 1;
	if (n == 1) {
		cout << "! " << 1 << endl;
		return 0;
	}
	if (get(0) < get(1)) {
		cout << "! " << 1 << endl;
		return 0;
	}
	if (get(n - 1) < get(n - 2)) {
		cout << "! " << n << endl;
		return 0;
	}
	while (r != l + 2) {
		int m1 = (r + 2 * l) / 3;
		int m2 = (2 * r + l) / 3;

		int val1 = get(m1);
		int val2 = get(m2);
		if (val1 < val2)
			r = m2;
		else
			l = m1;
	}
	cout << "! " << (r + l) / 2 + 1 << endl;
	return 0;
}