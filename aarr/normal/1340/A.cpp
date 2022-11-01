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
		bool ans = true;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int lt = 1;
		for (int i = 2; i <= n; i++) {
			if (a[i] > a[i - 1] && a[i] - a[i - 1] > 1) {
				ans = false;
				break;
			}
			if (a[i] < a[i - 1]) {
				reverse(a + lt, a + i);
				lt = i;
			}

		}
		reverse(a + lt, a + n + 1);
		for (int i = 2; i <= n; i++) {
			if (a[i] > a[i - 1]) {
				ans = false;
			}
		}
	//	if (lt != 1) {
	//		ans = false;
	//	}
		if (ans) {
			cout << "Yes" << '\n';
		}
		else {
			cout << "No" << '\n';
		}		
	}
	return 0;
}