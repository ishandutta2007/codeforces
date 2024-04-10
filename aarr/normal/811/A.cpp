#include <iostream>
#include <set>
#include <algorithm>
using namespace std;



int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i; i++) {
		if (i % 2) {
			if (n >= i) {
				n -= i;
			}
			else {
				cout << "Vladik";
				return 0;				
			}
		}
		else {
			if (m >= i) {
				m -= i;
			}
			else {
				cout << "Valera";
				return 0;				
			}
		}
	}
	return 0;
}