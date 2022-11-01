#include <iostream>
using namespace std;


bool f(string t, string s) {
	int j = 0;
	for (int i = 0; i < t.size(); i++) {
		//if (s[j] != t[i])
		//	return false;
		int x = 1, y = 0;
		while (i < t.size() - 1 && t[i] == t[i + 1]) {
			i++;
			x++;
		}
		while (j < s.size() && s[j] == t[i]) {
			j++;
			y++;
		}
		//cout << i << " " << j << " " << x << " " << y << endl;
		if (y < x)
			return false;
	}
	if (j < s.size())
		return false;
	return true;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s, t;
		cin >> s;
		cin >> t;
		if (f(s, t))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}