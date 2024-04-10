#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;

	while (ntest--) {
		int n;
		string s;
		cin >> n >> s;
		bool check1 = 0;
		bool check2 = 0;
		for (char ch : s) {
			if (ch == '<')
				check1 = 1;
			if (ch == '>')
				check2 = 1;
		}

		if ((check1 && check2) == 0) {
			cout << n << '\n';
		} else {
			int ans = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] == '-' || s[(i + n - 1) % n] == '-')
					ans++;
			}
			cout << ans << '\n';
		}
	}

	return 0;
}