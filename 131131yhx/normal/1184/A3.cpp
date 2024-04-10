#include <bits/stdc++.h>
#define M 1048576

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll powmod(ll x, ll y, ll p) {
	ll ans = 1;
	while(y) {
		if(y & 1) ans = ans * x % p;
		x = x * x % p;
		y >>= 1;
	}
	return ans;
}

ll F[200010], Fac[200010], Rev[200010], rev[M], r[200010];

int V[200010], st = 0;

vector <ll> C[21], rC[21];

ll P, g;

ull X[M], Y[M];

bool npr[50000010];

void DFT(ull *X, int t) {
	for(int i = 0; i < t; i++)
		for(int j = 0; j < (1 << t); j += (1 << i + 1))
			for(int k = 0; k < (1 << i); k++) {
				ll A = X[j + k], B = X[j + k + (1 << i)] * C[i + 1][k] % P;
				X[j + k] = A + B;
				X[j + k + (1 << i)] = A - B + P;
			}
	for(int i = 0; i < (1 << t); i++) X[i] %= P;
}

void pr(int o) {
	for(int i = 1; i <= o; i++) {
		C[i].resize(1 << i), C[i][0] = 1;
		ll w = powmod(g, (P - 1) >> i, P);
		for(int j = 1; j < (1 << i); j++) C[i][j] = C[i][j - 1] * w % P;
		rC[i] = C[i];
		reverse(rC[i].begin() + 1, rC[i].end());
	}
}

ll getori() {
	for(int g = 2; ; g++) {
		assert(powmod(g, P - 1, P) == 1);
		int flag = 0;
		for(int i = 2; i * i <= P - 1; i++) if((P - 1) % i == 0) {
			if(powmod(g, i, P) == 1 || powmod(g, (P - 1) / i, P) == 1) {flag = 1; break;}
		}
		if(!flag) return g;
	}
}

int n, m;

char ch1[M], ch2[M];

int XX[22][1058571];

int main() {
	scanf("%d%d", &n, &m);
	scanf("%s", ch1 + 1);
	scanf("%s", ch2 + 1);
	for(int o = 0; o < 22; o++)
		for(int i = 1; i <= n; i++) XX[o][(i - 1) & ((1 << o) - 1)] = ((int) XX[o][(i - 1) & ((1 << o) - 1)] + (ch1[i] - ch2[i]));
	for(int i = 2; i <= 100000; i++) if(!npr[i])
		for(int j = i + i; j < 50000000; j += i) npr[j] = 1;
	for(P = m; ; P++) if(!npr[P]) {
		ll tmp = P - 1;
		int o = 0, s = tmp & -tmp;
		while((1 << o) != s) o++; 
		if((1 << o) <= P / 400) continue;
		o = min(o, 20);
		// Do 2^22
		g = getori();
		pr(o);
		for(int i = 0; i < (1 << o); i++) X[i] = (XX[o][i] % P + P) % P; 
		for(int i = 1; i < (1 << o); i++) rev[i] = rev[i / 2] / 2 + (i & 1) * (1 << o - 1);
		for(int i = 0; i < (1 << o); i++) if(rev[i] > i) swap(X[i], X[rev[i]]);
		DFT(X, o);
		tmp = 1;
		s = powmod(g, (P - 1) >> o, P);
		for(int i = 0; i < (1 << o); i++) {
			if(tmp != 1 && tmp != P - 1 && X[i] % P == 0) {
				printf("%lld %lld\n", P, tmp);
				return 0;
				/*ll qwq = 0;
				for(int j = n - 1; j >= 0; j--) qwq = (qwq * tmp + S[j]) % P;
				assert(qwq % P == 0);
				return 0;*/
			}
			tmp = tmp * s % P;
		}
	}
	return 0;
}