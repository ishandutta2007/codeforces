#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

const int mod = 1e9 + 7, N = 1e5;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
    	lli p, q;
    	cin >> p >> q;
		if (p % q != 0) {
			cout << p << endl;
		} else {
			vector <long long> fa;
			long long old = q;
			for (lli i = 2; i * i <= old; ++i) if (old % i == 0) {
				fa.push_back(i);
				while (old % i == 0) old /= i;
			}
			if (old > 1) fa.push_back(old);
			lli ans = 0;
			for (lli i : fa) {
				long long cur = p;
				while (cur % q == 0) cur /= i;
				ans = max(ans, cur);
			}
			cout << ans << endl;
		}
	}
}