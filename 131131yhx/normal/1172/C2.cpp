#include <bits/stdc++.h>
#define M 200010
#define P 998244353

using namespace std;

typedef long long ll;

ll powmod(ll x, ll y = P - 2, ll p = P) {
	ll ans = 1;
	while(y) {
		if(y & 1) ans = ans * x % p;
		x = x * x % p;
		y >>= 1;
	}
	return ans;
}

int n, m;

ll W[M];

int A[M];

ll F[3010][6010]; // -m ~ m, kakongjian!

//ll F[111][111];

void add(ll &x, ll y) {x = (x + y) % P;}

ll rev[6010];

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= n; i++) scanf("%lld", &W[i]);
	ll totw = 0, totg = 0, totb = 0;
	for(int i = 1; i <= n; i++) {
		totw += W[i];
		if(A[i]) totg += W[i]; else totb += W[i];
	}
	for(int i = -m; i <= m; i++) rev[i + m] = powmod(totw + i);
	F[0][m] = 1;
	for(int i = 0; i < m; i++)
		for(int j = m - i; j <= m + i; j++) if(F[i][j]) {
			ll g = totg + (i + (j - m)) / 2, b = totb - (i - (j - m)) / 2;
			add(F[i + 1][j + 1], F[i][j] * rev[j] % P * g);
			add(F[i + 1][j - 1], F[i][j] * rev[j] % P * b);
		}
	ll Eg = 0, Eb = 0;
	for(int i = -m; i <= m; i++) {
		ll pr = F[m][i + m];
		ll g = totg + (m + i) / 2, b = totb - (m - i) / 2;
		Eg = (Eg + g * pr % P) % P;
		Eb = (Eb + b * pr % P) % P;
	}
	ll rtotg = powmod(totg), rtotb = powmod(totb);
	ll tmpg = (Eg - totg) * rtotg % P;
	ll tmpb = (totb - Eb) * rtotb % P;
	for(int i = 1; i <= n; i++)
		if(A[i] == 0) {
			ll tmp = (1 - tmpb) * W[i] % P;
			printf("%lld\n", (tmp % P + P) % P);
		} else {
			ll tmp = (1 + tmpg) * W[i] % P;
			printf("%lld\n", (tmp % P + P) % P);
		}
	return 0;
}