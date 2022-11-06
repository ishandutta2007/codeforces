#include <bits/stdc++.h>
typedef long long LL;
const int N = 300005, P = 998244353;
int n, a[2*N], inv[N], ans = 0;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 2*n; i++) scanf("%d", &a[i]);
	std::sort(a+1, a+2*n+1);
	for (int i = 1; i <= n; i++) (ans += P-a[i]) %= P;
	for (int i = n+1; i <= 2*n; i++) (ans += a[i]) %= P;
	inv[1] = 1;
	for (int i = 2; i <= n; i++) inv[i] = 1LL*(P-P/i)*inv[P%i]%P, ans = 1LL*ans*inv[i]%P;
	for (int i = n+1; i <= 2*n; i++) ans = 1LL*ans*i%P;
	printf("%d", ans);
	return 0;
}