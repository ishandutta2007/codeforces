#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int tc;
	cin >> tc;
	while (tc--) {
		ll hC, dC;
		ll hM, dM;
		int k;
		ll w, a;
		cin >> hC >> dC;
		cin >> hM >> dM;
		cin >> k >> a >> w;
		bool flag = 0;
		for (int i = 0; i <= k; i++) {
			ll hc = hC + 1LL * i * w;
			ll dc = dC + 1LL * (k - i) * a;
			ll step1 = (hM + dc - 1) / dc;
			ll step2 = (dM + hc - 1) / dM;
			if (step1 <= step2) {
				cout << "YES\n";
				flag = 1;
				break;
			}
		}
		if (!flag)
			cout << "NO\n";
	}
}