#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char tr = getchar(), f = 1;
	for (; !isdigit(tr); tr = getchar()) if (tr == '-') f = !f;
	for (; isdigit(tr); tr = getchar()) x = (x << 1) + (x << 3) + (tr ^ '0');
	return f ? x : -x;
}
#define N 200005
int m, n, len[N], L[N], R[N];
char s[N], t[N];
long long ans;
struct AC_Automaton{
	int cnt, tr[N][26], fail[N], sum[N];
	int h, t, Q[N];
	void init(){
		cnt = 0, memset(tr, 0, sizeof tr), memset(fail, 0, sizeof fail), memset(sum, 0, sizeof sum);
	}
	void insert(char *s, int n){
		int u = 0;
		for (register int i = 0; i < n; u = tr[u][s[i] - 'a'], ++i)
			if (!tr[u][s[i] - 'a']) tr[u][s[i] - 'a'] = ++cnt;
		++sum[u];
	}
	void build(){
		h = 0, t = 0;
		for (register int i = 0; i < 26; ++i) if (tr[0][i]) Q[++t] = tr[0][i];
		while (h < t){
			int u = Q[++h];
			sum[u] += sum[fail[u]];
			for (register int i = 0, v; i < 26; ++i)
				if (tr[u][i]) v = tr[u][i], Q[++t] = v, fail[v] = tr[fail[u]][i];
				else tr[u][i] = tr[fail[u]][i];
		}
	}
}T;
int main(){
	scanf("%s", s), m = strlen(s), scanf("%d", &n);
	for (register int i = 1, p = 0; i <= n; ++i)
		scanf("%s", t + p), len[i] = strlen(t + p), T.insert(t + p, len[i]), p += len[i];
	T.build();
	for (register int i = 0, u = 0; i < m; ++i) u = T.tr[u][s[i] - 'a'], L[i] = T.sum[u];
	T.init();
	for (register int i = 1, p = 0; i <= n; ++i)
		std :: reverse(t + p, t + p + len[i]), T.insert(t + p, len[i]), p += len[i];
	T.build();
	for (register int i = m - 1, u = 0; ~i; --i) u = T.tr[u][s[i] - 'a'], R[i] = T.sum[u];
	for (register int i = 1; i < m; ++i) ans += 1ll * L[i - 1] * R[i];
	printf("%lld\n", ans);
}