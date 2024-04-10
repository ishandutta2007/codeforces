#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N];
int c[N];


int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n, mx = 0, cx = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			c[a[i]]++;
			if (c[a[i]] > mx) {
				mx = c[a[i]];
				cx = 0;
			}
			if (c[a[i]] == mx) {
				cx++;
			}
		}
		for (int i = 0; i < n; i++) {
			c[a[i]] = 0;
		}
		cout << (n - cx) / (mx - 1) - 1 << endl;
	}
	
	return 0;
}