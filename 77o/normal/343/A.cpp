#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll p, q;
	cin >> p >> q;
	ll ans = 0;
	while (p && q) {
		if (p < q) {
			swap(p, q);
		}
		ans += p / q;
		p %= q;
	}
	cout << ans << endl;
    return 0;
}