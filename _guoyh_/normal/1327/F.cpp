# include <bits/stdc++.h>
# define ll long long
# define fst first
# define snd second
using namespace std;
const int MAXN = 500051;
const int P = 998244353;
int n, m, k;
ll f[MAXN][2], s[MAXN][2];
int l[MAXN][2];
int ql[MAXN], qr[MAXN], qx[MAXN];
ll solve(int p){
	memset(f, 0, sizeof(f));
	memset(l, 0, sizeof(l));
	memset(s, 0, sizeof(s));
	for (int i = 1; i <= m; i++){
		if ((qx[i] >> p) & 1) l[ql[i]][0] = max(l[ql[i]][0], qr[i]);
		else l[qr[i]][1] = max(l[qr[i]][1], ql[i]);
	}
	f[0][0] = f[0][1] = s[0][0] = s[0][1] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 2; j++){
			l[i][j] = max(l[i - 1][j], l[i][j]);
			f[i][j] = l[i][j] == 0 ? s[i - 1][j ^ 1] : (s[i - 1][j ^ 1] - s[min(i - 1, l[i][j] - 1)][j ^ 1]) % P;
			s[i][j] = (s[i - 1][j] + f[i][j]) % P;
			// printf("f %d %d %d %lld %lld\n", i, j, l[i][j], f[i][j], s[i][j]);
		}
	}
	return (f[n][0] + f[n][1]) % P;
}
int main(){
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= m; i++) scanf("%d%d%d", ql + i, qr + i, qx + i);
	ll ans = 1;
	for (int i = 0; i < k; i++) ans = ans * solve(i) % P;
	printf("%lld\n", (ans + P) % P);
	return 0;
}