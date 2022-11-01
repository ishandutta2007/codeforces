#include <bits/stdc++.h>
using namespace std;

const int N = 300 * 1000 + 5;

int x[N], y[N];
int f[N];
bool mark[N];

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n, m, ans = 0;
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			cin >> x[i] >> y[i];
			f[x[i]] = y[i];
			if (x[i] != y[i]) {
				ans++;
			}
			else {
				mark[x[i]] = true;
			}
		}
	//	cout << "73 " << x[1] << " " << ans << endl;
		for (int i = 1; i <= m; i++) {
			if (!mark[x[i]] && !mark[y[i]]) {
				int v = y[i];
				mark[x[i]] = true;
			//	cout << "71 " << v << endl;
				while (v != 0 && v != x[i] && !mark[v]) {
				//	cout << "72 " << v << endl;
					mark[v] = true;
					v = f[v];
				}
				if (v == x[i]) {
					ans++;
				}
			}
		}
		mark[0] = false;
		for (int i = 1; i <= n; i++) {
			mark[i] = false;
			x[i] = y[i] = f[i] = 0;
		}
		for (int i = 1; i <= m; i++) {
			mark[x[i]] = mark[y[i]] = mark[i] = false;
			x[i] = y[i] = 0;
			f[x[i]] = f[y[i]] = f[i] = 0;
		}
		cout << ans << '\n';
	}
	return 0;
}