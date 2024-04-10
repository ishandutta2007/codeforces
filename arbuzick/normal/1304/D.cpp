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
		string a;
		cin >> a;
		vector<int> minp(n), maxp(n);
		int l;
		l = 0;
		int b;
		b = n;
		for (int j = 0; j < n; j++) {
			if (j == n - 1 || a[j] == '>') {
				for (int k = j; k >= l; k--) {
					minp[k] = b;
					b -= 1;
				}
				l = j + 1;
			}
			}
		for (int j = 0; j < n; j++)
			cout << minp[j] << " ";
		cout << endl;
		l = 0;
		b = 1;
		for (int j = 0; j < n; j++) {
			if (j == n - 1 || a[j] == '<') {
				for (int k = j; k >= l; k--) {
					maxp[k] = b;
					b += 1;
				}
				l = j + 1;
			}
		}
		for (int j = 0; j < n; j++)
			cout << maxp[j] << " ";
		cout << endl;
	}
	return 0;
}