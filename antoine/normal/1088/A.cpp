#include <bits/stdc++.h>

using namespace std;
typedef int ll;

const ll mod = (int) 2e5;
ll a[(int) 1e5 + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int x;
	cin >> x;
	for (int a = 1; a <= x; ++a)
		for (int b = 1; b <= x; ++b)
			if (a % b == 0 && a * b > x && a / b < x) {
				cout << a << ' ' << b;
				return 0;
			}
	cout << -1;
	return 0;
}