#include <bits/stdc++.h>
using namespace std;
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

string norm(string s) {
	for(int i = 0; i < sz(s); i++) {
		if('A' <= s[i] && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
		if(s[i] == 'o') s[i] = '0';
		if(s[i] == 'i' || s[i] == 'l') s[i] = '1';
	}
	return s;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s; int n; cin >> s >> n;
	s = norm(s);
	for(int i = 0; i < n; i++) {
		string t; cin >> t;
		if(s == norm(t)) return cout << "No", 0;
	}
	cout << "Yes";
}