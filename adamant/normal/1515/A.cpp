#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
    if(accumulate(a, a + n, 0) == x) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
        int s = 0;
        for(int i = 0; i < n; i++) {
            if(s + a[i] == x) {
                cout << a[i + 1] << ' ' << a[i] << ' ';
                s += a[i] + a[i + 1];
                i++;
            } else {
                s += a[i];
                cout << a[i] << ' ';
            }
        }
        cout << "\n";
    }
}

signed main() {
    //freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}