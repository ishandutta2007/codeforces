#include <iostream>
using namespace std;



int main() {
	int n;
	cin >> n;
	int i;
	for (i = 1; n >= i * (i + 1) / 2; i++) {
		n -= i * (i + 1) / 2;
	}
	cout << i - 1;
	return 0;
}