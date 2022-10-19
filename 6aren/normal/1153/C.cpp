#include<bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n;
	cin >> s;
	if (s[0] == '(' || s[0] == '?') s[0] = '(';
	else return cout << ":(", 0;
	if (s[n - 1] == ')' || s[n - 1] == '?') s[n - 1] = ')';
	else return cout << ":(", 0;
	int cnt = 0;
	for (int i = 1; i < n - 1; i++) {
		if (s[i] == '(') cnt++;
	}
	int t = (n - 2) / 2 - cnt;
	for (int i = 1; i < n - 1; i++) {
		if (s[i] == '?') {
			if (t > 0) {
				s[i] = '(';
				t--;
			} else {
				s[i] = ')';
			}
		}
	}
	cnt = 0;
	for (int i = 1; i < n - 1; i++) {
		if (s[i] == '(') cnt++;
		else cnt--;
		if (cnt < 0) return cout << ":(", 0;
	}
	if (cnt != 0) return cout << ":(", 0;
	cout << s;
	return 0;
}