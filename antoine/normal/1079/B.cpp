#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s;
	cin >> s;

	for (int n = 1; n <= 5; ++n)
		for (int m = 1; m <= 20; ++m)
			if (n * m >= (int) s.size()) {
				cout << n << ' ' << m << '\n';
				while (!s.empty()) {
					if (s.size() % m) {
						cout << s.substr(0, m - 1) << "*\n";
						s = s.substr(m - 1);
					} else {
						cout << s.substr(0, m) << '\n';
						s = s.substr(m);
					}
				}
				return 0;
			}
	return 0;
}