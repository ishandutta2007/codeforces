#include<bits/stdc++.h>
using namespace std;

string s;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	int cntl = 0, cntr = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != '0') break;
		cntl++;
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] != '0') break;
		cntr++;
	}
	if (cntl > cntr) {
		cout << "NO" << endl;
		return 0;
	}
	int n = s.size();
	n -= cntr;
	for (int i = 0; i < n; i++) {
		if (s[i] != s[n - 1 - i]) {
			return cout << "NO", 0;
		}
	}
	cout << "YES" << endl;

	return 0;
}