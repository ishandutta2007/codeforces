#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

bool mark[N];

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n, m, ans = -1;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			mark[x] = true;
		}
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			if (mark[x]) {
				ans = x;
			}
		}
		if (ans >= 0) {
			cout << "YES\n1 " << ans << endl;
		}
		else {
			cout << "NO\n";
		}
		fill(mark, mark + N, false);
	}
	
	return 0;
}