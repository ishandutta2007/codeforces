#include <iostream>
using namespace std;



int main() {
	int n;
	cin >> n;
	if (n % 2 == 1) {
		cout << n / 2 << " " << n / 2 + 1;
	}
	if (n % 4 == 0) {
		cout << n / 2 - 1 << " " << n / 2 + 1;
	}	
	if (n % 4 == 2) {
		cout << n / 2 - 2 << " " << n / 2 + 2;
	}
	return 0;
}