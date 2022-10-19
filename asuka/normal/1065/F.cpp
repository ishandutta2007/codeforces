#include<bits/stdc++.h>
#define ll long long
#define N 1000015
#define rep(i,a,n) for (int i=(a);i<=(n);i++)
#define per(i,a,n) for (int i=(n);i>=(a);i--)
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n, k;
VI e[N];
int f[N][2], dep[N], Min[N];
void dfs(int u, int fa) {
	dep[u] = dep[fa] + 1;
	Min[u] = inf;
	bool isleaf = 1;
	for(auto v : e[u]) {
		if(v == fa) continue;
		dfs(v, u);
		isleaf = 0;
		Min[u] = min(Min[u], Min[v]);
	}
	if(isleaf) {
		Min[u] = dep[u];
		f[u][0] = f[u][1] = 1;
		return;
	}
	int Max = -inf;
	for(auto v : e[u]) {
		if(v == fa) continue;
		int val = Min[v] - k <= dep[u] ? f[v][1] : 0;
		f[u][1] += val;
		f[u][0] += val;
		Max = max(Max, - val + f[v][0]);
	}
	f[u][0] += Max;
	// printf("U: %d [%d %d]\n", u, f[u][0], f[u][1]);
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d", &n, &k);
	rep(i, 2, n) {
		int u = i, v;
		scanf("%d", &v);
		e[u].pb(v);
		e[v].pb(u);
		// printf("%d %d\n", u, v);
	}
	dfs(1, 0);
	printf("%d\n", max(f[1][0], f[1][1]));
	
	return 0;
}