#include <iostream>
using namespace std;



int main() {
	int n;
	string s, t;
	cin >> n >> s >> t;
	if (t.back() == 'k') {
		if (n == 5 || n == 6) {
			cout << 53;
		}
		else {
			cout << 52;
		}
	}
	else {
		if (n == 31) {
			cout << 7;
		}
		if (n == 30) 
			cout << 11;
		if (n < 30) 
			cout << 12;
	}
	return 0;
}