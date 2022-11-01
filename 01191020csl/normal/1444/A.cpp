#include<bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		long long p;
		int q;
		cin >> p >> q;
		if (p % q != 0) cout << p << endl;
		else {
			long long ans = 1;
			int x = q;
			for (int i = 2; i * i <= q; i++)
				if (x % i == 0) {
					long long tmp = p;
					while (tmp % q == 0) tmp /= i;
					ans = max(ans, tmp);
					tmp = p;
					while (x % i == 0) x /= i;
				}
			long long tmp = p;
			if (x > 1) {
				while (tmp % q == 0) tmp /= x;
				ans = max(ans, tmp);
			}
			cout << ans << endl;
		}
	}
}