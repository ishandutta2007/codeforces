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
		int x, y = 1;
		cin >> x;
		while (x > 0) {
			if (x % 10) {
				vec.push_back((x % 10) * y);
			}
			x /= 10;
			y *= 10;
		}
		cout << vec.size() << endl;
		for (auto x : vec) {
			cout << x << " ";
		}
		cout << endl;
		vec.clear();
	}
	return 0;
}