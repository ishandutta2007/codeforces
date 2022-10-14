#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m)-((m)>(n));i!=(n)-((m)>(n));i+=2*((m)<(n))-1)
#define test(x) cout << #x << ' ' << x << endl;
#define eb emplace_back
#define pb push_back
#define mp make_pair 
#define pii pair<int,int>

int MOD = 1e9+7;

long long modinv(int a, int b, int x, int y) {
	if (b == 0) return x;
	return modinv(b, a%b, y, x - a / b * y);
}

long long Div(int a, int b) {
	return 1ll * a * modinv(b,MOD,1,0) % MOD;
}

long long myPow(int a, int b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	long long aa = myPow(a,b/2);
	aa = aa * aa % MOD;
	aa = aa * myPow(a,b%2) % MOD;
	return aa;
}


int main () {
	int  n,k;
	cin >> n >> k;
	lli frac[k+2];
	frac[0] = 1;
	fop (i,1,k+2) frac[i] = (frac[i-1] * i) % MOD;
	lli firstK[k+2];
	firstK[0] = 0;
	fop (i,1,k+2) {
		firstK[i] = (firstK[i-1] + myPow(i,k)) % MOD;
	}
	if (n <= k + 1) {
		cout << firstK[n] << endl;
		return 0;
	}
	lli summ = 1;
	fop (i,0,k+2) {
		summ *= (n - i);
		summ %= MOD;
	}
	lli ans = 0;
	fop (i,0,k+2) {
		lli aa = firstK[i] * Div(Div(Div(summ, n - i) , frac[k+1-i]), frac[i]) % MOD;
		if (!((i + k) % 2)) aa *= -1;
		ans += aa;
		ans %= MOD;
	}
    if (ans < 0) ans += MOD;
	cout << ans << endl;
	return 0;
}