#include<bits/stdc++.h>

using namespace std;

int main(){
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	#endif
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		long long k, n, a, b;
		cin >> k >> n >> a >> b;
		long long l = -1, r = n + 1;
		while (r - l > 1) {
			int m = (l + r) / 2;
			if (k - m * a - (n - m) * b <= 0) {
				r = m;
			}
			else {
				l = m;
			}
		}
		cout << l << "\n";
	}
	return 0;
}