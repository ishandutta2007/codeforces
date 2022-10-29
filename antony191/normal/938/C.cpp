#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <set>
#include <map>


using namespace std;

int main() {
	int t;
	cin >> t;
	for (int qq = 0; qq < t; ++qq) {
		int x;
		cin >> x;
		if (x == 0) {
			cout << "1 1\n";
			continue;
		}
		if (x % 2 == 0 && x % 4 != 0) {
			cout << "-1\n";
			continue;
		}
		int a, b;
		bool q = false;
		if (x & 1) {
			for (int k = 1; k * k < x; k++) {
				if (x % k == 0) {
					a = k; b = x / k;
					int n = (a + b) / 2;
					int w = n - a;
					int m = n / w;
					if (n / m == w) {
						cout << n << ' ' << m << endl;
						q = true;
						break;
					}
				}
			}
		}
		else {
			for (int k = 2; k * k < x; k += 2) {
				if (x % k == 0 && ((x / k) & 1) == 0) {
					int a = k, b = x / k;
					int n = (a + b) / 2;
					int w = n - a;
					int m = n / w;
					if (n / m == w) {
						cout << n << ' ' << m << endl;
						q = true;
						break;
					}
				}
			}
		}
		if (!q)
			cout << "-1\n";
	}
	return 0;
}