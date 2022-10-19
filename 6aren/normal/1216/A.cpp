#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	s = " " + s;
	int cnt = 0;
	for (int i = 1; i <= n; i += 2) {
		if (s[i] == s[i + 1]) {
			cnt++;
			s[i] = 'a';
			s[i + 1] = 'b';
		}
	}
	cout << cnt << endl;
	for (int i = 1; i <= n; i++) cout << s[i];
	return 0;
}