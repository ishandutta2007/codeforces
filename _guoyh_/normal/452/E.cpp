# include <cstdio>
# include <cstring>
# include <algorithm>
# define ll long long
using namespace std;
const int MAXN = 300051;
const int MOD = 1000000007;
struct MSU{
	int fa[MAXN];
	int cnt1[MAXN], cnt2[MAXN], cnt3[MAXN];
	int findroot(int nw){
		if (!fa[nw]) return nw;
		else return fa[nw] = findroot(fa[nw]);
	}
	int merge(int u, int v){
		// printf("merge %d %d\n", u, v);
		u = findroot(u);
		v = findroot(v);
		int ans = 0;
		ans = (ans - 1ll * cnt1[u] * cnt2[u] * cnt3[u]) % MOD;
		ans = (ans - 1ll * cnt1[v] * cnt2[v] * cnt3[v]) % MOD;
		cnt1[u] += cnt1[v];
		cnt2[u] += cnt2[v];
		cnt3[u] += cnt3[v];
		fa[v] = u;
		ans = (ans + 1ll * cnt1[u] * cnt2[u] * cnt3[u]) % MOD;
		return ans;
	}
} msu;
int n, l;
int flag[MAXN];
char s[MAXN];
int cnt[MAXN];
int sa[MAXN], sa1[MAXN], rk[MAXN << 1], rk1[MAXN << 1],hgt[MAXN];
char s1[MAXN], s2[MAXN], s3[MAXN];
int a[MAXN];
int ans[MAXN];
bool cmp(int x, int y){
	return s[x] < s[y];
}
bool cmph(int x, int y){
	return hgt[x] > hgt[y];
}
void getsa(){
	for (int i = 1; i <= n; i++) sa[i] = i;
	sort(sa + 1, sa + n + 1, cmp);
	rk[sa[1]] = 1;
	for (int i = 2; i <= n; i++) rk[sa[i]] = (s[sa[i]] == s[sa[i - 1]]) ? rk[sa[i - 1]] : rk[sa[i - 1]] + 1;
	for (int w = 1; w <= n - 1; w <<= 1){
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) cnt[rk[i + w]]++;
		for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
		for (int i = n; i >= 1; i--) sa1[cnt[rk[sa[i] + w]]--] = sa[i];
		memcpy(sa, sa1, sizeof(sa));
		// for (int i = 1; i <= n; i++) printf("%d ", sa[i]);
		// putchar('\n');
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= n; i++) cnt[rk[i]]++;
		for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
		for (int i = n; i >= 1; i--) sa1[cnt[rk[sa[i]]]--] = sa[i];
		memcpy(sa, sa1, sizeof(sa));
		// for (int i = 1; i <= n; i++) printf("%d ", sa[i]);
		// putchar('\n');
		rk1[sa[1]] = 1;
		for (int i = 2; i <= n; i++) rk1[sa[i]] = (rk[sa[i]] == rk[sa[i - 1]] && rk[sa[i] + w] == rk[sa[i - 1] + w]) ? rk1[sa[i - 1]] : rk1[sa[i - 1]] + 1;
		memcpy(rk, rk1, sizeof(rk));
		// for (int i = 1; i <= n; i++) printf("%d ", rk[i]);
		// putchar('\n');
		// putchar('\n');
	}
	for (int i = 1; i <= n; i++){
		hgt[rk[i]] = max(0, hgt[rk[i - 1]] - 1);
		while (i + hgt[rk[i]] <= n && sa[rk[i] - 1] + hgt[rk[i]] <= n && s[i + hgt[rk[i]]] == s[sa[rk[i] - 1] + hgt[rk[i]]]) hgt[rk[i]]++;
	}
	// for (int i = 1; i <= n; i++) printf("%d %s\n", hgt[i], s + sa[i]);
}
int main(){
	// printf("%d %d\n", int('$'), int('#'));
	scanf("%s%s%s", s1 + 1, s2 + 1, s3 + 1);
	l = min(strlen(s1 + 1), min(strlen(s2 + 1), strlen(s3 + 1)));
	strcpy(s + 1, s1 + 1);
	s[strlen(s + 1) + 1] = '$';
	strcpy(s + strlen(s + 1) + 1, s2 + 1);
	s[strlen(s + 1) + 1] = '#';
	strcpy(s + strlen(s + 1) + 1, s3 + 1);
	n = strlen(s + 1);
	flag[0] = 1;
	// printf("%s\n", s + 1);
	for (int i = 1; i <= n; i++){
		if (s[i] == '$') flag[i] = 2;
		else if (s[i] == '#') flag[i] = 3;
		else flag[i] = flag[i - 1];

		if (flag[i] == 1) msu.cnt1[i] = 1;
		else if (flag[i] == 2) msu.cnt2[i] = 1;
		else msu.cnt3[i] = 1;
	}
	getsa();
	for (int i = 1; i <= n; i++) a[i] = i;
	sort(a + 1, a + n + 1, cmph);
	for (int i = 1; i <= n; i++) ans[hgt[a[i]]] = (ans[hgt[a[i]]] + msu.merge(sa[a[i]], sa[a[i] - 1])) % MOD;
	for (int i = n; i >= 1; i--) ans[i] = (ans[i] + ans[i + 1]) % MOD;
	for (int i = 1; i <= l; i++) printf("%d ", (ans[i] + MOD) % MOD);
	return 0;
}