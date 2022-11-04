#include <bits/stdc++.h>
#define M 555
#define P 998244353
#define int long long
using namespace std;

typedef long long ll;

int n, A[M], B[M], X[M], Y[M], fac[M], C[M][M], stl[M][M], cnt[5], cyc = 0, vis[M], g[M], G[M], Ans[M];

#undef int
int main()
#define int long long
{
	scanf("%d", &n), memset(X, -1, sizeof X), memset(Y, -1, sizeof Y);
	for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &B[i]), X[B[i]] = A[i], Y[A[i]] = B[i];
	for(int i = 0; i <= n; i++) fac[i] = i == 0 ? 1 : (ll) fac[i - 1] * i % P;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= i; j++)
			C[i][j] = !j ? 1 : (C[i - 1][j - 1] + C[i - 1][j]) % P,
			stl[i][j] = !j ? !i : (stl[i - 1][j - 1] + (ll) stl[i - 1][j] * (i - 1)) % P;
	for(int i = 1, tmp; i <= n; i++) if(X[i] <= 0 && !(X[i] == -1 && Y[i] == -1)) {
		for(int j = i; ; j = Y[j]) if(Y[j] > 0) vis[j] = 1; else {tmp = Y[j], vis[j] = 1; break;}
		cnt[X[i] * 2 + tmp + 3]++;
	}
	for(int i = 1; i <= n; i++) if(A[i] == 0 && B[i] == 0) cnt[3]++;
	for(int i = 1; i <= n; i++) if(A[i] && !vis[A[i]]) {
		vis[A[i]] = 1, cyc++;
		for(int j = Y[A[i]]; j != A[i]; j = Y[j]) vis[j] = 1;
	}
	int a = cnt[1], b = cnt[2], c = cnt[3];
	for(int i = 0; i <= n; i++) g[i] = (i + c == 0 ? 1ll : (ll) C[i + c - 1][i] * fac[i] % P) * fac[c] % P;
	for(int i = 0; i <= n - cyc; i++)
		for(int j = 0; j <= i; j++)
			for(int k = 0; k <= b; k++)
				Ans[n - (i + cyc)] = (Ans[n - (i + cyc)] + (ll) g[k] * stl[b - k][j] % P * stl[a + c][i - j] % P * C[b][k]) % P;
	for(int i = 0; i < n; i++) printf("%d ", Ans[i]);
	return putchar('\n'), 0;
}