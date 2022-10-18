#include <bits/stdc++.h>

using namespace std;

bool is_sqr(int n) {
    int k = sqrt(n);
    return k * k == n;
}

void solve() {
	int n;
	cin >> n;
	if(is_sqr(n / 2) && n % 2 == 0 || is_sqr(n / 4) && n % 4 == 0) {
        cout << "YES\n";
	} else {
        cout << "NO\n";
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