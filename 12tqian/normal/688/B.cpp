#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s; 
	cin >> s;
	string t = s;
	reverse(t.begin(), t.end());
	s += t;
	cout << s << '\n';
	return 0;
}