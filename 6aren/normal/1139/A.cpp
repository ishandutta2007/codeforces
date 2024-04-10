#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	int n, ans = 0;
	string s;
	cin >> n;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '8') {
			ans += i + 1;
		}
	}
	cout << ans;
	return 0;
}