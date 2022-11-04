#include <bits/stdc++.h>
#define M 400010
#define P 1000000007

using namespace std;

typedef long long ll;

int C[7][7], n, m, Tg[6][M], Sm[6][M], X[M], tot[6][M], x, y, z;

ll powmod(ll x, ll y, ll p = P)
{
	ll ans = 1;
	while(y) {if(y & 1) ans = ans * x % p; x = x * x % p, y >>= 1;}
	return ans;
}

void Build(int x, int L, int R, int s)
{
	if(L == R) {Sm[s][x] = (ll)X[L] * powmod(L, s) % P; return;}
	Build(x * 2, L, (L + R) / 2, s), Build(x * 2 + 1, (L + R) / 2 + 1, R, s);
	Sm[s][x] = (Sm[s][x * 2] + Sm[s][x * 2 + 1]) % P;
}

void pd(int x, int L, int R, int s)
{
	int md = (L + R) / 2;
	if(Tg[s][x] != -1) {
		Tg[s][x * 2] = Tg[s][x * 2 + 1] = Tg[s][x];
		Sm[s][x * 2] = (ll)Tg[s][x] * (tot[s][md] - tot[s][L - 1]) % P;
		Sm[s][x * 2 + 1] = (ll)Tg[s][x] * (tot[s][R] - tot[s][md]) % P;
		Tg[s][x] = -1;
	}
}

void insert(int x, int L, int R, int l, int r, int s, int v)
{
	if(L == l && R == r) {Sm[s][x] = (ll)(Tg[s][x] = v) * (tot[s][R] - tot[s][L - 1]) % P; return;}
	int md = (L + R) / 2;
	pd(x, L, R, s);
	if(l <= md) insert(x * 2, L, md, l, min(md, r), s, v);
	if(r > md) insert(x * 2 + 1, md + 1, R, max(md + 1, l), r, s, v);
	Sm[s][x] = (Sm[s][x * 2] + Sm[s][x * 2 + 1]) % P;
}

int query(int x, int L, int R, int l, int r, int s)
{
	if(L == l && R == r) return Sm[s][x];
	int md = (L + R) / 2, ans = 0;
	pd(x, L, R, s);
	if(l <= md) ans = query(x * 2, L, md, l, min(md, r), s);
	if(r > md) ans = (ans + query(x * 2 + 1, md + 1, R, max(md + 1, l), r, s)) % P;
	return ans;
}

int main()
{
	memset(Tg, -1, sizeof Tg);
	char ch[7];
	scanf("%d%d", &n, &m);
	for(int i = 0; i <= 5; i++)
		for(int j = 1; j <= n; j++) tot[i][j] = (tot[i][j - 1] + powmod(j, i)) % P;
	for(int i = 1; i <= n; i++) scanf("%d", &X[i]);
	for(int i = 0; i <= 5; i++) Build(1, 1, n, i);
	for(int i = 0; i <= 5; i++)
		for(int j = 0; j <= i; j++) C[i][j] = !j ? 1 : (C[i - 1][j - 1] + C[i - 1][j]) % P;
	while(m--)
		if(scanf("%s%d%d%d", ch, &x, &y, &z), ch[0] == '=') for(int i = 0; i <= 5; i++) insert(1, 1, n, x, y, i, z); else {
			int ans = 0;
			for(ll i = 0, s = 1; i <= z; i++, s = s * (-x + 1) % P)
				ans = (ans + s * C[z][i] % P * query(1, 1, n, x, y, z - i)) % P;
			printf("%d\n", (ans + P) % P);
		}
	return 0;
}