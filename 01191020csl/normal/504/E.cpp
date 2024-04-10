#include<bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int P = 993244853;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
void write(int num) {
	if (num >= 10) write(num / 10);
	putchar(num % 10 + '0');
}
int power(int a, int n) {
	int ans = 1;
	while (n) {
		if (n & 1) ans = 1ll * ans * a % mod;
		a = 1ll * a * a % mod;
		n >>= 1;
	}
	return ans;
}
char s[300010];
int head[300001], dep[600001], ver[600001], nxt[600001], sz;
void addedge(int u, int v) {
	ver[++sz] = v, nxt[sz] = head[u], head[u] = sz;
	ver[++sz] = u, nxt[sz] = head[v], head[v] = sz;
}
int fa[300001], len[300001], son[300001];
int hash1[300001], hash2[300001];
int powerP[300001], invP[300001];
void dfs1(int x) {
	hash1[x] = (hash1[fa[x]] + 1ll*powerP[dep[x]-1]*s[x]) % mod;
	hash2[x] = (1ll*hash2[fa[x]]*P+s[x]) % mod;
	for (int i = head[x]; i; i = nxt[i])
		if (fa[x] != ver[i]) {
			fa[ver[i]] = x;
			dep[ver[i]] = dep[x] + 1;
			dfs1(ver[i]);
			if (len[ver[i]] > len[son[x]]) son[x] = ver[i];
			len[x] = max(len[x], len[ver[i]]);
		}
	++len[x];
}
int f[300001][20], top[300001];
vector<int> seq[300001];
vector<int>::iterator pt[300001];
void dfs2(int x, int t) {
	top[x] = t;
	f[x][0] = fa[x];
	if (x == t) {
		seq[x].reserve(2 * len[x] - 1);
		int p = x;
		for (int i = 1; i < len[x]; i++) p = fa[p], seq[x].push_back(p);
		reverse(seq[x].begin(), seq[x].end());
		pt[x] = seq[x].end();
	}
	seq[t].push_back(x);
	if (son[x]) dfs2(son[x], t);
	for (int i = head[x]; i; i = nxt[i])
		if (fa[x] != ver[i] && son[x] != ver[i])
			dfs2(ver[i], ver[i]);
	if (x == t) reverse(seq[x].begin(), seq[x].end());
}
int lg2[300001];
void init(int n) {
	for (int j = 1; j < 19; j++)
		for (int i = 1; i <= n; i++)
			f[i][j] = f[f[i][j-1]][j-1];
	for (int j = 0; j < 19; j++)
		for (int i = 1 << j; i < (1 << j+1) && i <= n; i++)
			lg2[i] = j;
}
int up(int u, int k) {
	if (k == 0) return u;
	u = f[u][lg2[k]];
	int v = top[u];
	k -= 1 << lg2[k];
	return *(pt[v]-(len[v]-len[u])+k);
}
int lca(int u, int v) {
	if (dep[u] < dep[v]) swap(u, v);
	u = up(u, dep[u] - dep[v]);
	if (u == v) return u;
	for (int i = 19; i >= 0; i--)
		if (f[u][i] != f[v][i])
			u = f[u][i], v = f[v][i];
	return f[u][0];
}
int hashup(int u, int v) {
	return (mod+hash2[u]-1ll*hash2[fa[v]]*powerP[dep[u]-dep[v]+1]%mod)%mod;
}
int hashdown(int u, int v) {
	return 1ll*(mod+hash1[v]-hash1[fa[u]])*invP[dep[fa[u]]]%mod;
}
int main() {
	int n = read();
	cin >> s + 1;
	for (int i = 1; i <= n; i++) s[i] -= 'a';
	for (int i = 1; i < n; i++) {
		int u, v;
		u = read(), v = read();
		addedge(u, v);
	}
	powerP[0] = 1;
	for (int i = 1; i <= n; i++) powerP[i] = 1ll * powerP[i-1] * P % mod;
	invP[0] = 1, invP[1] = power(P, mod - 2);
	for (int i = 2; i <= n; i++) invP[i] = 1ll * invP[i-1] * invP[1] % mod;
	dep[1] = 1;
	dfs1(1), dfs2(1, 1);
	init(n);
	int m = read();
	for (int i = 1; i <= m; i++) {
		int a, b, c, d;
		a = read(), b = read(), c = read(), d = read();
		if (s[a] != s[c]) {
			write(0);
			putchar('\n');
			continue;
		}
		int u = lca(a, b), v = lca(c, d);
		int len1 = dep[a]+dep[b]-2*dep[u], len2 = dep[c]+dep[d]-2*dep[v];
		if (len1 < len2) swap(a, c), swap(b, d), swap(u, v), swap(len1, len2);
		if (dep[a]-dep[u] > len2) u = b = up(a, len2);
		else b = up(b, len1 - len2);
		if (dep[a] - dep[u] < dep[c] - dep[v]) swap(a, c), swap(b, d), swap(u, v);
		int x = up(a, dep[c] - dep[v]), y = up(d, dep[b] - dep[u]);
		if (hashup(a, x) != hashup(c, v)) {
			int l = 1, r = dep[c] - dep[v];
			while (l < r) {
				int mid = (l + r + 1) / 2;
				if (hashup(a, up(a, mid-1)) != hashup(c, up(c, mid-1))) r = mid - 1;
				else l = mid;
			}
			write(l);
		}
		else if (hashup(x, u) != hashdown(v, y)) {
			int l = 1, r = dep[x] - dep[u];
			while (l < r) {
				int mid = (l + r + 1) / 2;
				if (hashup(x, up(x, mid-1)) != hashdown(v, up(y, dep[y]-dep[v]-mid+1))) r = mid - 1;
				else l = mid;
			}
			write(l + dep[c] - dep[v]);
		}
		else {
			int l = 1, r = dep[b] - dep[u] + 1;
			while (l < r) {
				int mid = (l + r + 1) / 2;
				if (hashdown(u, up(b, dep[b]-dep[u]-mid+1)) != hashdown(y, up(d, dep[d]-dep[y]-mid+1))) r = mid - 1;
				else l = mid;
			}
			write(l + dep[a] - dep[u]);
		}
		putchar('\n');
	}
}