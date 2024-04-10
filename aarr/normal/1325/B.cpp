#include <bits/stdc++.h>
using namespace std;

int a[100 * 1000 + 5];
map <int, bool> mark;
int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, ans = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (!mark[a[i]]) {
				ans++;
				mark[a[i]] = true;
			}
		}
		for (int i = 1; i <= n; i++) {
			mark[a[i]] = false;
		}
		cout << ans << '\n';
	}
	
	return 0;
}