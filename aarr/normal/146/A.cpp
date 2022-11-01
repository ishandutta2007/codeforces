#include <bits/stdc++.h>
using namespace std;

string s;


int main() {
	int n;
	cin >> n >> s;
	int x = 0;
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != '4' && s[i] != '7') {
			cout << "NO";
			return 0;
		}
		x += s[i] - '0';
	}
	
	for (int i = s.size() / 2; i < s.size(); i++) {
		if (s[i] != '4' && s[i] != '7') {
			cout << "NO";
			return 0;
		}
		x -= s[i] - '0';
	}
	if (x == 0) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	
	return 0;
}