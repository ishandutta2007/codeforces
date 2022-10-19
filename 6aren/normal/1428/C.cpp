#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;

	while (ntest--) {
		string s;
		cin >> s;
		int rem = 0;
		int ans = 0;
		int cur = 0;
		for (char ch : s) {
			if (ch == 'A') {
				cur++;
			} else {
				if (cur > 0) {
					ans += 2;
					cur--;
				} else rem++;
			}
		}
		ans += rem - rem % 2;
		cout << s.size() - ans << '\n';
	}

	return 0;
}