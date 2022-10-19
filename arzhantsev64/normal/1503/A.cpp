#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

bool check(string & s) {
	int b = 0;
	for (char c : s) {
		if (c == '(')
			b++;
		if (c == ')')
			b--;
		if (b < 0)
			return 0;
	}
	return (b == 0);
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (n % 2 != 0) {
		cout << "NO\n";
		return;
	}
	int z = 0;
	for (char c : s)
		z += (c == '0');
	if (z % 2 != 0) {
		cout << "NO\n";
		return;
	}
	int nn = (n - z) / 2;
	int cnt = 0;
	int od = 0;
	string ans1;
	ans1.resize(n);
	string ans2;
	ans2.resize(n);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			if (cnt < nn) {
				ans1[i] = ans2[i] = '(';
				cnt++;
			} else {
				ans1[i] = ans2[i] = ')';
			}
		} else {
			if (od == 0) {
				ans1[i] = '(';
				ans2[i] = ')';
			} else {
				ans1[i] = ')';
				ans2[i] = '(';
			}
			od = 1 - od;
		}
	}
	if (!check(ans1) || !check(ans2))
		cout << "NO\n";
	else {
		cout << "YES\n";
		cout << ans1 << '\n';
		cout << ans2 << '\n';
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}