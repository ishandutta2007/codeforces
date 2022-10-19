#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int n;
		cin >> n;
		vector<int> t(n);
		int c = 0;
		int b = 0;
		for (int j = 0; j < n; ++j) {
			cin >> t[j];
			if (j > 0) {
				if (t[j] != t[j - 1])
					c = 1;
				else
					b = 1;
			}
		}
		if (t[n - 1] == t[0])
			b = 1;
		if (c == 0) {
			cout << 1 << endl;
			for (int j = 0; j < n; ++j)
				cout << 1 << " ";
			cout << endl;
		}
		else {
			if (n % 2 == 0) {
				cout << 2 << endl;
				for (int j = 0; j < n; ++j)
					cout << j % 2 + 1 << " ";
				cout << endl;
			}
			else {
				if (b == 0) {
					cout << 3 << endl;
					for (int j = 0; j < n - 1; ++j)
						cout << j % 2 + 1 << " ";
					cout << 3 << endl;
				}
				else {
					cout << 2 << endl;
					int pr;
					pr = 1;
					cout << 1 << " ";
					for (int j = 1; j < n; ++j) {
						if (t[j] == t[j - 1] && b == 1) {
							cout << pr << " ";
							b = 0;
						}
						else {
							cout << 3 - pr << " ";
							pr = 3 - pr;
						}
					}
					cout << endl;
				}
			}
		}
	}
	return 0;
}