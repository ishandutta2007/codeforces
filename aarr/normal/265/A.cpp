#include <iostream>
using namespace std;


string s, t;
int main() {
	cin >> s >> t;
	int p = 0;
	for (int i = 0; i < t.size(); i++) {
		if (t[i] == s[p])
			p++;
	}
	cout << p + 1 << endl;
	return 0;
}