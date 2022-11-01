#include <iostream>
#include <algorithm>
using namespace std;



int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		if (s[0] == s.back()) {
			cout << -1 << endl;
		}
		else {
			cout << s << endl;
		}
	}
	
	return 0;
}