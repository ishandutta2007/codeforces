#include <iostream>
using namespace std;



int main() {
	int l, p, q;
	cin >> l >> p >> q;
	cout << fixed;
	cout << (double) l * p / (p + q);
	
	return 0;
}