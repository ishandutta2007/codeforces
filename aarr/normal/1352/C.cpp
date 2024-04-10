#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int a[100 * 1000 + 5];
vector <int> vec;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, k;
		cin >> n >> k;
		int x = k / (n - 1) * n;
		x += k % (n - 1);
		if (k % (n - 1) == 0) {
			x--;
		}
		cout << x << endl;
	}
	return 0;
}