#include <bits/stdc++.h>
using namespace std;
const int N = 250005;
int n, mod, fct[N];
int main() {
	cin >> n >> mod;
	fct[0] = 1;
	for (int i = 1; i <= n; i++) fct[i] = 1ll * fct[i - 1] * i % mod;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cf1 = n - i + 1;
		ans = (ans + 1ll * cf1 * fct[n - i + 1] % mod * fct[i] % mod) % mod;
	}
	cout << ans;
	return 0;
}