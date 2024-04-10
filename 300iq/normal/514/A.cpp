#include <bits/stdc++.h>
#define int long long
using namespace std;



main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s;
	int ans = 0;
	while (cin >> s) {
		int x = 0;
		for (int i = 0; i < s.length(); i++) {
			x = s[i] - '0';
			if (9 - x < x && !(x == 9 && ans == 0)) {
				ans = ans * 10 + 9 - x;
			}
			else {
				ans = ans * 10 + x;
			}
		}
		cout << ans << endl;	
	}
}