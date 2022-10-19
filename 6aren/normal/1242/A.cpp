#include<bits/stdc++.h>
using namespace std;

#define int long long

main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	int res = 0;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {res = i; break;}
	}
	if (res == 0) return cout << n, 0;
	while (n % res == 0) n /= res;
	if (n > 1) cout << 1 << endl;
	else cout << res << endl;
	return 0;
}