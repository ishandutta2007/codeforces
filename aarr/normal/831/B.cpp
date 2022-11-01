#include <iostream>
using namespace std;

int a[30];

int main() {
	string s, t, p;
	cin >> s >> t >> p;
	for (int i = 0; i < s.size(); i++) {
		a[s[i] - 'a'] = t[i] - s[i];
	}
	for (int i = 0; i < p.size(); i++) {
		int x;
		if ('0' <= p[i] && p[i] <= '9') {
			cout << p[i];
			continue;
		}
		if ('a' <= p[i] && p[i] <= 'z') {
			x = p[i] - 'a';
		}
		else {
			x = p[i] - 'A';
		}
		cout << (char) (p[i] + a[x]);
	}
	return 0;
}