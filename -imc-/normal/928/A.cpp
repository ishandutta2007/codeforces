#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

bool charSimilar(char c, char d) {
	c = tolower(c);
	d = tolower(d);
	if (c == d) {
		return true;
	}

	if (c == '0' && d == 'o') {
		return true;
	}
	if (c == '1' && d == 'i') {
		return true;
	}
	if (c == '1' && d == 'l') {
		return true;
	}
	if (c == 'i' && d == 'l') {
		return true;
	}
	swap(c, d);
	if (c == '0' && d == 'o') {
		return true;
	}
	if (c == '1' && d == 'i') {
		return true;
	}
	if (c == '1' && d == 'l') {
		return true;
	}
	if (c == 'i' && d == 'l') {
		return true;
	}
	return false;
}

bool strSimilar(const string& s, const string& t) {
	if (s.length() != t.length()) {
		return false;
	}
	for (int i = 0; i < (int)s.length(); ++i) {
		if (!charSimilar(s[i], t[i])) {
			return false;
		}
	}
	return true;
}

int main() {
	string s;
	cin >> s;

	int n = nxt();
	while (n--) {
		string t;
		cin >> t;
		if (strSimilar(s, t)) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");

	return 0;
}