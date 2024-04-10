#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>
using namespace std;
int main() {
	long long int a, b;
	cin >> a;
	cin >> b;
	if ( b - a> (long long int)5) {
		cout << "0" << endl;
	}
	else if (a == b) {
		cout << "1" << endl;
	}
	else {
		int c = 1;
		for (long long int i = a + 1; i <= b; i++) {
			c = (c*(i % 10)) % 10;
		}
		cout << c << endl;
	}
}