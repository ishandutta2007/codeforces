#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int l, fib[55];
int fid[200005];

int n;
vector<PII> G[200005];
bool del[200005];

int siz[200005];
void dfs(int v, int par)
{
	siz[v] = 1;
	rep(i, G[v].size()) {
		int u = G[v][i].first;
		if(del[G[v][i].second] || u == par) continue;
		dfs(u, v);
		siz[v] += siz[u];
	}
}
int dfs1(int v, int par, int pe, int sl, int sr)
{
	if(siz[v] == sl || siz[v] == sr) {
		del[pe] = true; return v;
	}
	rep(i, G[v].size()) {
		int u = G[v][i].first;
		if(del[G[v][i].second] || u == par) continue;
		int ca = dfs1(u, v, G[v][i].second, sl, sr);
		if(ca != -1) return ca;
	}
	return -1;
}
bool check(int v)
{
	dfs(v, -1);
	if(fid[siz[v]] == -1) return false;
	if(siz[v] == 1) return true;
	int sl = fib[fid[siz[v]] - 1], sr = siz[v] - sl;
	int u = dfs1(v, -1, -1, sl, sr);
	return u != -1 && check(v) && check(u);
}

int main()
{
	scanf("%d", &n);
	rep(i, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(MP(v, i));
		G[v].push_back(MP(u, i));
	}
	
	fib[0] = 1; fib[1] = 2;
	for(l = 2; (fib[l] = fib[l - 1] + fib[l - 2]) <= n; l ++) ;
	rep1(i, n) fid[i] = -1;
	rep(i, l) fid[fib[i]] = i;
	
	if(check(1)) printf("YES\n");
	else printf("NO\n");
	return 0;
}