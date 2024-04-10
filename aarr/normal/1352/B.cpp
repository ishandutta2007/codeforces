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
		if (n % 2 == 1 && k % 2 == 0) {
			cout << "NO\n";
		}
		if (n % 2 == k % 2) {
			if (n >= k) {
				cout << "YES\n";
				for (int i = 1; i < k; i++) {
					cout << "1 ";
				}
				cout << n - k + 1;
			}
			else {
				cout << "NO";
			}
			cout << '\n';
		}
		if (n % 2 == 0 && k % 2 == 1) {
			if (n >= 2 * k) {
				cout << "YES\n";
				for (int i = 1; i < k; i++) {
					cout << "2 ";
				}
				cout << n - 2 * k + 2;
			}
			else {
				cout << "NO";
			}
			cout << '\n';
		}
	}
	return 0;
}