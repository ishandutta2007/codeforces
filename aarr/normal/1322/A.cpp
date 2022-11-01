#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	int x = 0, ans = 0;
	for (int i = 0; i < s.size(); i++) {
		bool b = false;
		if (x < 0) {
			b = true;
		}
		if (s[i] == '(') {
			x++;
		}
		else {
			x--;
		}
		if (x < 0 || b) {
			ans++;
		}
	}
	if (x == 0)
		cout << ans;
	else
		cout << -1;
	return 0;
}