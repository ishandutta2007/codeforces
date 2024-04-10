#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	auto check = [&](int i) {
		if (i < 0 || i >= n - 2) {
			return 0;
		} else {
			return (int)(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c');
		}
	};
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += check(i);
	}
	while (q--) {
		int p;
		char c;
		cin >> p >> c;
		--p;
		ans -= check(p) + check(p - 1) + check(p - 2);
		s[p] = c;
		ans += check(p) + check(p - 1) + check(p - 2);
		cout << ans << '\n';
	}
	return 0;
}