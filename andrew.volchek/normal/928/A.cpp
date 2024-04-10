#include <iostream>
#include <string>

using namespace std;

char canon(char c) {
	c = tolower(c);
	if (c == 'o') {
		return '0';
	}
	if (c == 'l' || c == 'i') {
		return '1';
	}
	return c;
}

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif

	string s;
	cin >> s;
	int n;
	cin >> n;
	bool flag = true;
	while (n--) {
		string t;
		cin >> t;
		if (s.length() == t.length()) {
			bool cur = false;
			for (int i = 0; i < (int)s.length(); ++i) {
				if (canon(s[i]) != canon(t[i])) {
					cur = true;
					break;
				}
			}
			if (!cur) {
				flag = false;
				break;
			}
		}
	}
	if (flag) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}