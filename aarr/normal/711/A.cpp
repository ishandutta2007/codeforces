#include <iostream>
using namespace std;


string s[1005];
int main() {
	bool b = false;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (!b && s[i][0] == 'O' && s[i][1] == 'O') {
			b = true;
			s[i][0] = s[i][1] = '+';
		}
		if (!b && s[i][3] == 'O' && s[i][4] == 'O') {
			b = true;
			s[i][3] = s[i][4] = '+';
		}		
	}
	if (b) {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			cout << s[i] << endl;
		}
	}
	else {
		cout << "NO" << endl;
	}
}