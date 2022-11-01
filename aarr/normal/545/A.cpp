#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int a[100 * 1000 + 5];
vector <int> vec;

int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		bool b = false;
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x >= 0 && (x & 1)) {
				b = true;
			}
		}
		if (!b) {
			vec.push_back(i + 1);
		}
	}
	cout << vec.size() << endl;
	for (auto x : vec) {
		cout << x << " ";
	}
	return 0;
}