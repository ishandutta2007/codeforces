#include <iostream>
using namespace std;

int main() {
	int k2, k3, k5, k6;
	cin >> k2 >> k3 >> k5 >> k6;
	
	int nb256 = min(min(k2, k5), k6);
	k2 -= nb256;
	int nb32 = min(k3, k2);
	
	cout << nb256 * 256 + nb32 * 32 << endl;
	return 0;
}