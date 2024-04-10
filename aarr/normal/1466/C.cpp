#include <bits/stdc++.h>
using namespace std;

string s;

bool check(int x) {
	if (x > 0 && s[x] == s[x - 1])
		return false;
	if (x > 1 && s[x] == s[x - 2])
		return false;
	return true;
}

bool check2(int x) {
	if (!check(x))
		return false;
	if (x + 1 < s.size() && s[x] == s[x + 1])
		return false;
	if (x + 2 < s.size() && s[x] == s[x + 2])
		return false;
	return true;
} 

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		cin >> s;
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			if (!check(i)) {
			//	cout << "72 " << i << endl;
				s[i] = 'a';
				ans++;
				while (!check2(i)) {
					s[i]++;
				}
			}

		}
		cout << ans << '\n';
	}
	
	return 0;
}