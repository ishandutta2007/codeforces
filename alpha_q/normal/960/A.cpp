#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	int i = 0, n = s.size(), a = 0, b = 0, c = 0;
	while (i < n and s[i] == 'a') ++i, ++a;
	while (i < n and s[i] == 'b') ++i, ++b;
	while (i < n and s[i] == 'c') ++i, ++c;
	if (i < n) {
		cout << "NO\n";
		return 0;
	}
	if (a > 0 and b > 0 and (c == a or c == b)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
	return 0;
}