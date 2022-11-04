#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
inline int qp(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return res;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d\n", (int)(1ll * qp(n + 1, m - 1) * qp(2, m) % mod * (n - m + 1) % mod));
	return 0;
}