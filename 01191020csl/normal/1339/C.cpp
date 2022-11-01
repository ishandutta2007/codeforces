#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		int x = a[1], ans = 0;
		for (int i = 2; i <= n; i++) {
			if (a[i] < x) ans = max(ans, x - a[i]);
			if (a[i] > x) x = a[i];
		}
		if (!ans) {
			puts("0");
			continue;
		}
		for (int i = 1; i <= 31; i++)
			if ((1u << i) > ans) {
				cout << i << endl;
				break;
			}
	}
}