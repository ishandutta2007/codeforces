#include <iostream>
#include <map>
#include <set>
using namespace std;

bool vow(char c) {
	if (c == 'a' || c == 'i' || c == 'o' || c == 'u' || c == 'e' || c == 'y')
		return true;
	return false;
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (i == 0 || !vow(s[i]) || !vow(s[i - 1])) {
			cout << s[i];
		}
	}
	return 0;
}