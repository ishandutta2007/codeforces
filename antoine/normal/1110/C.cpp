#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int f() {
	int x;
	cin >> x;
	if (!(x & (x + 1))) {
		for (int y = 2; y * y <= x; ++y)
			if (x % y == 0)
				return x / y;
		return 1;
	}
	int cnt = 0;
	while (x) {
		++cnt;
		x >>= 1;
	}
	return (1 << cnt) - 1;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cout << f() << '\n';

	}
	return 0;
}