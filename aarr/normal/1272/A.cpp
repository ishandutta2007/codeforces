#include <iostream>
#include <algorithm>
using namespace std;

int a[5];

int main() {
	int t;
	cin >> t;
	for (int i = 0 ; i < t; i++) {
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		cout << max(0, (a[2] - a[0] - 2) * 2) << endl;
 	}
	return 0;
}