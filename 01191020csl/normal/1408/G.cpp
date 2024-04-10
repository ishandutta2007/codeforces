#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int read() {
	char c=getchar();while(!isdigit(c)) c=getchar();
	int num=0;while(isdigit(c)) num=num*10+c-'0',c=getchar();
	return num;
}
struct edge {
	int u, v, w;
	edge(int a, int b, int c):u(a), v(b), w(c){}
};
bool operator<(const edge &a, const edge &b) {
	return a.w < b.w;
}
int cnt;
int fa[1501], size[1501], tot[1501], id[1501];
int getfa(int x) {
	if (!fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
vector<edge> e;
int ls[3001], rs[3001], vis[3001];
int res[3001][1501], n;
void dfs(int x) {
	if (!ls[x] && !rs[x]) {
		for (int i = 0; i <= n; i++) res[x][i] = i;
		return;
	}
	dfs(ls[x]), dfs(rs[x]);
	for (int i = 0; i <= n; i++) res[x][i] = 1ll*res[ls[x]][i]*res[rs[x]][i]%mod;
	if (vis[x])
		for (int i = 0; i <= n; i++) res[x][i] = (res[x][i]+i)%mod;
}
int tmp[1501], t0[1501], ans[1501];
int inv[1501];
int main() {
	n = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int a = read();
			if (i < j) e.push_back(edge(i, j, a));
		}
	for (int i = 1; i <= n; i++) size[i] = 1, id[i] = i, vis[i] = 1;
	sort(e.begin(), e.end()), cnt = n;
	for (int i = 0; i < e.size(); i++) {
		int u = e[i].u, v = e[i].v;
		int p = getfa(u), q = getfa(v);
		if (p == q) {
			++tot[p];
			if (tot[p] == size[p]*(size[p]-1)/2) vis[id[p]] = 1;
			continue;
		}
		if (size[p] > size[q]) swap(p, q);
		size[q] += size[p], tot[q] += tot[p] + 1, fa[p] = q;
		++cnt, ls[cnt] = id[p], rs[cnt] = id[q], id[q] = cnt;
		if (tot[q] == size[q]*(size[q]-1)/2) vis[id[q]] = 1;
	}
	dfs(cnt);
	tmp[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = i - 1; j >= 0; j--) {
			tmp[j+1] = (tmp[j+1]+tmp[j])%mod;
			tmp[j] = 1ll*tmp[j]*(mod-i)%mod;
		}
	inv[1] = 1;
	for (int i = 2; i <= n; i++) inv[i] = 1ll*(mod-mod/i)*inv[mod%i]%mod;
	for (int i = 1; i <= n; i++) {
		int k = res[cnt][i];
		for (int j = i + 1; j <= n; j++) k = 1ll*k*(mod-inv[j-i])%mod;
		for (int j = i - 1; j >= 0; j--) k = 1ll*k*inv[i-j]%mod;
		int x = tmp[n];
		for (int j = n; j > 0; j--) t0[j-1] = x, x = (tmp[j-1]+1ll*x*i)%mod;
		for (int j = 0; j < n; j++) ans[j+1] = (ans[j+1]+1ll*k*t0[j])%mod;
	}
	int k = res[cnt][0];
	for (int i = 1; i <= n; i++) k = 1ll*k*inv[i]%mod;
	for (int j = 0; j <= n; j++) ans[j] = (ans[j]+1ll*k*tmp[j])%mod;
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << endl;
}