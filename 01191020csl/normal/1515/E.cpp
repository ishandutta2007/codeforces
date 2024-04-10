#include<bits/stdc++.h>
using namespace std;
int mod;
unsigned f[410][410];
int inv[401], fact[401], invfact[401];
int C(int n, int m) {
	return m <= n && m >= 0 ? 1ll*fact[n]*invfact[m]%mod*invfact[n-m]%mod : 0;
}
int invC(int n, int m) {
	return 1ll*invfact[n]*fact[m]%mod*fact[n-m]%mod;
}
int main() {
	int n;
	cin >> n >> mod;
	inv[1] = 1;
	for (int i = 2; i <= n; i++) inv[i] = 1ll*(mod-mod/i)*inv[mod%i]%mod;
	fact[0] = invfact[0] = 1;
	for (int i = 1; i <= n; i++) fact[i] = 1ll*fact[i-1]*i%mod;
	for (int i = 1; i <= n; i++) invfact[i] = 1ll*invfact[i-1]*inv[i]%mod;
	f[1][1] = n;
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= i && n-i-j+2 >= j; j++) {
			int tot = 1ll*f[i][j]*invC(n-i-j+2, j)%mod;
			f[i+1][j+1] = (f[i+1][j+1] + 1ll*C(n-i-j,j+1)*(j+1)%mod*tot)%mod;
			f[i+1][j] = (f[i+1][j] + 2ll*C(n-i-j+1,j)*j%mod*tot)%mod;
			f[i+2][j] = (f[i+2][j] + 2ll*C(n-i-j,j)*j%mod*tot)%mod;
			f[i+2][j-1] = (f[i+2][j-1] + 2ll*C(n-i-j+1,j-1)*(j-1)%mod*tot)%mod;
			f[i+3][j-1] = (f[i+3][j-1] + 1ll*C(n-i-j,j-1)*(j-1)%mod*tot)%mod;
		}
	cout << f[n][1] << endl;
}