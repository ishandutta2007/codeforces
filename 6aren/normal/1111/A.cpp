#include <bits/stdc++.h>

using namespace std;

string s, t;

int a[30];

int main() {
	cin >> s >> t;
	for (int i = 0; i < 26; i++) {
		if ((i == 'a' - 'a') || (i == 'e' - 'a') || (i == 'i' - 'a') || (i == 'o' - 'a') || (i == 'u' - 'a')) {
			a[i] = 1;
		} else {
			a[i] = 0;
		}
	}
	if (s.size() != t.size()) {
		cout << "No" << endl;
		return 0;
	}
	for (int i = 0; i < s.size(); i++) {
		if (a[s[i] - 'a'] != a[t[i] - 'a']) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
/* 
g++ online.cpp -o online.exe
*/