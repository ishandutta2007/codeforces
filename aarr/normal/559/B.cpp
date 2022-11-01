#include <iostream>
using namespace std;

const int N = 200 * 1000 + 5;

string get(string s) {
	if (s.size() % 2) {
		return s;
	}
	string x, y;
	for (int i = 0; i < s.size() / 2; i++) {
		x += s[i];
	}
	for (int i = s.size() / 2; i < s.size(); i++) {
		y += s[i];
	}
	string a = get(x), b = get(y);
	if (a < b) {
		return a + b;
	}
	return b + a;
}

int main() {
	string a, b;
	cin >> a >> b;
	string s = get(a), t = get(b);
	if (s == t) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	
	return 0;
}