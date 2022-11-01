#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int a[300001], inv[300001];
int fact[300001], invfact[300001];
int c(int n, int m) {
	if (n < m) return 0;
	return 1ll*fact[n]*invfact[m]%mod*invfact[n-m]%mod;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n * 2; i++) cin >> a[i];
	sort(a + 1, a + n * 2 + 1);
	int ans = 0;
	for (int i = n + 1; i <= n * 2; i++) ans = (ans + a[i]) % mod;
	for (int i = 1; i <= n; i++) ans = (mod + ans - a[i]) % mod;
	inv[1] = 1;
	for (int i = 2; i <= n * 2; i++) inv[i] = 1ll*(mod-mod/i)*inv[mod%i]%mod;
	fact[0] = invfact[0] = 1;
	for (int i = 1; i <= n * 2; i++) fact[i] = 1ll*fact[i-1]*i%mod, invfact[i] = 1ll*invfact[i-1]*inv[i]%mod;
	cout << 1ll*ans*c(n*2,n)%mod << endl;
}