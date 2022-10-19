#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);


	int ntest;
	cin >> ntest;
	while (ntest--) {
		string s;
		cin >> s;
		int c = s[0] - '0';
		int ans = (c - 1) * 10;
		for (int i = 1; i <= s.size(); i++)
			ans += i;
		cout << ans << '\n';
	}

	return 0;
}