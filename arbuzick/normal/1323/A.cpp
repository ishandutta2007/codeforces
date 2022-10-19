#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int j = 0; j < n; j++)
			cin >> a[j];
		if (n > 2) {
			cout << 2 << endl;
			int a1, a2;
			a1 = -1;
			a2 = -1;
			for (int j = 0; j < n; j++) {
				if (a[j] % 2 == 0) {
					if (a2 == -1)
						a2 = j;
					else {
						cout << a2 + 1 << " " << j + 1 << endl;
						break;
					}
				}
				else {
					if (a1 == -1)
						a1 = j;
					else {
						cout << a1 + 1 << " " << j + 1 << endl;
						break;
					}
				}
			}
		}
		else {
			if (n == 1) {
				if (a[0] % 2 == 0) {
					cout << 1 << endl;
					cout << 1 << endl;
				}
				else
					cout << -1 << endl;
			}
			else {
				if (a[0] % 2 == a[1] % 2) {
					cout << 2 << endl;
					cout << 1 << " " << 2 << endl;
				}
				else {
					if (a[0] % 2 == 0) {
						cout << 1 << endl;
						cout << 1 << endl;
					}
					else {
						cout << 1 << endl;
						cout << 2 << endl;
					}
				}
			}
		}
	}
	return 0;
}