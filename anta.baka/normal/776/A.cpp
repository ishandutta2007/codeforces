#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s1, s2;
	int n;
	cin >> s1 >> s2 >> n;
	cout << s1 << ' ' << s2 << "\n";
	for(int i = 0; i < n; i++) {
		string t1, t2;
		cin >> t1 >> t2;
		if(s1 == t1) {
			s1 = t2;
		} else {
			s2 = t2;
		}
		cout << s1 << ' ' << s2 << "\n";
	}
}