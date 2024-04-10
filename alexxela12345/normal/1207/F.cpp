#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500000;

const int k = 710;
int arr[MAXN];
int ans[k][k];

int main() {
	int q;
	cin >> q;
	while (q--) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			arr[x - 1] += y;
			for (int i = 1; i < k; i++) {
				ans[i][(x - 1) % i] += y;
			}
		} else {
			if (x < k) {
				cout << ans[x][(y - 1 + x) % x] << endl;
			} else {
				int anss = 0;
				for (int i = (y - 1 + x) % x; i < MAXN; i += x) {
					anss += arr[i];
				}
				cout << anss << endl;
			}
		}
	}
}