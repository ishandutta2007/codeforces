#include<bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	int q;
	cin >> q;
	while (q--) {
		long long k, n, a, b;
		cin >> k >> n >> a >> b;
		if (n * a < k) cout << n << endl;
		else {
			long long tmp = (n*a - k) / (a - b) + 1;
			if (n - tmp < 0) cout << -1 << endl;
			else cout << n - tmp << endl;
		}
	}
	return 0;
}