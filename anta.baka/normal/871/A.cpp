#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q; cin >> q;
	while(q--) {
		int n; cin >> n;
		if(n % 4 == 0) { cout << n / 4 << '\n'; continue; }
		if(n >= 6 && (n - 6) % 4 == 0) { cout << 1 + (n - 6) / 4 << '\n'; continue; }
		if(n >= 9 && (n - 9) % 4 == 0) { cout << 1 + (n - 9) / 4 << '\n'; continue; }
		if(n >= 15 && (n - 15) % 4 == 0) { cout << 2 + (n - 15) / 4 << '\n'; continue; }
		cout << -1 << '\n';
	}
}