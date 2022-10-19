#include<bits/stdc++.h>
using namespace std;

string a;
vector<string> v;
string s, t;

bool check(string u) {
	if (u[0] == s[0] && u[1] == s[1]) return false;
	if (u[0] == t[0] && u[1] == t[1]) return false;
	if (u[1] == s[0] && u[2] == s[1]) return false;
	if (u[1] == t[0] && u[2] == t[1]) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	cin >> s >> t;
	cout << "YES" << endl;
	v.push_back("abc");
	v.push_back("acb");
	v.push_back("bca");
	v.push_back("bac");
	v.push_back("cab");
	v.push_back("cba");
	a = "abc";
	if (t[0] == t[1]) {
		string tmp = t;
		t = s;
		s = tmp;
	}
	if (s[0] == s[1]) {
		if (t[0] == t[1]) {
			for (int i = 1; i <= n; i++) {
				cout << "abc";
			}
		} else {
			for (int i = 1; i <= n; i++) {
				cout << t[1] << t[0];
				cout << a[3 - (int) (t[1] - 'a') - (int) (t[0] - 'a')];
			}
		}
	} else {
		for (auto u : v) {
			if (check(u)) {
				for (int i = 0; i < 3; i++) {
					for (int j = 1; j <= n; j++) {
						cout << u[i];
					}
				}
				return 0;
			}
		}
	}
	return 0;
}