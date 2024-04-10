#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N];

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int ans = 2;
		for (int i = n; i; i--) {
			if (ans == 1) {
				if (a[i] > 1) {
					ans = 1;
				}
				else {
					ans = 2;
				}
			}
			else {
				ans = 1;
			}
		}
		if (ans == 1) {
			cout << "First\n";
		}
		else {
			cout << "Second\n";
		}
	}
	
	return 0;
}