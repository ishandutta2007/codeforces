#include <iostream>
#include <algorithm>
using namespace std;



int main() {
	int n;
	cin >> n;
	int a = 0, b = 0;
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		if (x < 0) {
			a++;
		}
		else {
			b++;
		}
	}
	if (min(a, b) <= 1) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}