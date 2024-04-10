#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N];
bool mark[N * 2];


int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (mark[a[i]] && !mark[a[i] + 1]) {
				mark[a[i] + 1] = true;
			}
			if (!mark[a[i]]) {
				mark[a[i]] = true;
			}
		}
		int ans = 0;
		for (int i = 0; i <= n * 2 + 1; i++) {
			if (mark[i]) {
				ans++;
			}
			mark[i] = false;
		}
		cout << ans << '\n';
	}
	
	return 0;
}