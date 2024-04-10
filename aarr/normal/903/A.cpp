#include <iostream>
using namespace std;



int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int x;
		cin >> x;
		if (x >= 21 || x % 3 == 0 || x % 7 == 0 || (x >= 7 && (x - 7) % 3 == 0) || (x >= 14 && (x - 14) % 3 == 0)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}