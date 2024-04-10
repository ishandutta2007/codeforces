#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	for (char &c : s) {
		if (c >= 'A' and c <= 'Z') c = c - 'A' + 'a';
	}
	for (char &c : t) {
		if (c >= 'A' and c <= 'Z') c = c - 'A' + 'a';
	}
	if (s > t) cout << 1 << endl;
	else if (s == t) cout << 0 << endl;
	else cout << -1 << endl;
}