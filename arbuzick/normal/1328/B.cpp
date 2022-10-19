#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int n, k;
		cin >> n >> k;
		int a;
		a = 0;
		for (int i = 1; i < n; ++i) {
			a += i;
			if (a >= k) {
				for (int j = 0; j < n - i - 1; ++j)
					cout << "a";
				cout << "b";
				k = k - (a - i);
				for (int j = n - i; j < n; ++j) {
					if (n - k == j)
						cout << "b";
					else
						cout << "a";
				}
				cout << endl;
				break;
			}
		}
	}
	return 0;
}