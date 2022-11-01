#include <bits/stdc++.h>
using namespace std;

const int N = 105;

bool mark[N];
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
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <i ;j ++) {
				mark[abs(a[i] - a[j])] = true;
			}
		}
		int ans = 0;
		for (int i = 1; i < N; i++) {
			if (mark[i]) {
				ans++;
			}
			mark[i] = false;
		}
		cout << ans << '\n';
	}
	
	return 0;
}