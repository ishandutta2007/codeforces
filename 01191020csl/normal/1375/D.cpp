#include<bits/stdc++.h>
using namespace std;
int a[1001], cnt[1001];
int mex(int n) {
	for (int i = 0; i <= n; i++) cnt[i] = 0;
	for (int i = 0; i < n; i++) ++cnt[a[i]];
	for (int i = 0; i <= n; i++)
		if (!cnt[i]) return i;
}
int ans[2001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		int p = 0, m = mex(n);
		while (1) {
			if (m < n) a[m] = m, ans[++p] = m;
			else {
				bool flag = 1;
				for (int i = n - 1; i >= 0; i--)
					if (a[i] != i) {
						ans[++p] = i, a[i] = m;
						flag = 0;
						break;
					}
				if (flag) break;
			}
			m = mex(n);
		}
		cout << p << endl;
		for (int i = 1; i <= p; i++) cout << ans[i] + 1 << ' ';
		cout << endl;
	}
}