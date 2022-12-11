#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int nbTest;
	cin >> nbTest;

	for(int iTest = 0;iTest < nbTest;iTest++) {
		int x, y;
		cin >> x >> y;

		if(__gcd(x, y) == 1) {
			cout << "Finite" << endl;
		}
		else {
			cout << "Infinite" << endl;
		}
	}
	return 0;
}