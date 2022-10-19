#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t-- > 0) {
		long long n;
		cin >> n;
		long long o = n;
		long long e = 1;
		while (o % 2 == 0) {
			o /= 2;
			e *= 2;
		}
		if (o != 1) {
			if (o > e * 2) {
				cout << e * 2 << endl;
			}
			else {
				cout << o << endl;
			}
		}
		else {
			cout << -1 << endl;
		}
	}
}