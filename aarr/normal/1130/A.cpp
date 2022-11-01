#include <iostream>
#include <map>
#include <set>
using namespace std;



int main() {
	int n, a = 0, b = 0;;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > 0) {
			a++;
		}
		if (x < 0) {
			b++;
		}
	}
	if (a * 2 >= n) {
		cout << 1;
	}
	else if (b * 2 >= n) {
		cout << -1;
	}
	else
		cout << 0;
	return 0;
}