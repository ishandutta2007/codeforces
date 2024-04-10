#include<bits/stdc++.h>
using namespace std;

int n, a[105];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> q;
	while (q--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + 1 + n);
		bool flag = true;
		for (int i = 2; i <= n; i++) {
			if (a[i - 1] + 1 == a[i]) flag = false;
		}
		if (flag) cout << 1 << endl;
		else cout << 2 << endl;
	}
	return 0;
}