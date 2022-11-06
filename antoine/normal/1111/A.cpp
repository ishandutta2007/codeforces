#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool f(char c) {
	string s = "aeiou";
	for (char d : s)
		if (c == d)
			return true;
	return false;
}

bool f() {
	string s, t;
	cin >> s >> t;
	if (s.size() != t.size())
		return false;
	for (int i = 0; i < (int) s.size(); ++i)
		if (f(s[i]) != f(t[i]))
			return false;
	return true;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cout << (f() ? "Yes" : "No");
	return 0;
}