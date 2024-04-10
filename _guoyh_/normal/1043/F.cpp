# include <bits/stdc++.h>
# define ll long long
# define fst first
# define snd second
using namespace std;
const int MAXN = 300051;
const int P = 998244353;
int p[MAXN], psz;
bool flag[MAXN];
int n, m, mx;
int a[MAXN];
ll ans[MAXN], ans1[MAXN];
ll f1[MAXN], f2[MAXN];
void work(ll f[]){
	for (int i = 1; i <= psz; i++){
		for (int j = (MAXN - 1) / p[i]; j >= 1; j--) f[j] = (f[j] + f[j * p[i]]) % P;
	}
}
void work2(ll f[]){
	for (int i = psz; i >= 1; i--){
		for (int j = 1; j * p[i] < MAXN; j++) f[j] = (f[j] - f[j * p[i]]) % P;
	}
}
int main(){
	// freopen("1.out", "w", stdout);
	for (int i = 2; i < MAXN; i++){
		if (!flag[i]) p[++psz] = i;
		for (int j = 1; j <= psz && i * p[j] < MAXN; j++){
			flag[i * p[j]] = true;
			if (i % p[j] == 0) break;
		}
	}
	scanf("%d", &n);
	m = 1;
	mx = m;
	memset(ans, 0x3f, sizeof(ans));
	for (int i = 1; i <= n; i++){
		scanf("%d", a + i);
		mx = max(mx, a[i]);
		f1[a[i]]++;
		ans[a[i]] = 1;
	}
	work(f1);
	// for (int j = 1; j <= mx; j++) printf("%lld ", f1[j]);
	// putchar('\n');
	memcpy(ans1, f1, sizeof(f1));
	memcpy(f2, f1, sizeof(f1));
	for (int i = 2; i <= 7; i++){
		for (int j = 1; j < MAXN; j++) f2[j] = f2[j] * f1[j] % P;
		work2(f2);
		// for (int j = 1; j <= mx; j++) printf("%d ", f2[j]);
		// putchar('\n');
		for (int j = 1; j <= m; j++) if (f2[j]) ans[j] = min(ans[j], (ll)i);
		work(f2);
	}
	for (int i = 1; i <= m; i++){
		if (ans[i] < 1e9) printf("%lld\n", ans[i]);
		else printf("-1\n");
	}
	return 0;
}