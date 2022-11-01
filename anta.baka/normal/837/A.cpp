#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int t = 0;
		for(char x : s)
			t += ('A' <= x && x <= 'Z');
		ans = max(ans, t);
	}
	cout << ans;
}