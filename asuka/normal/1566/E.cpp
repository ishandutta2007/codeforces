#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
int T, n, cnt[N];
VI e[N];
void dfs(int u, int fa) {
	for(auto v : e[u]) {
		if(v != fa) dfs(v, u);
	}
	if(cnt[u] == 0) cnt[fa]++;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		rep(i, 1, n) e[i].clear(), cnt[i] = 0;
		rep(i, 2, n) {
			int u, v;
			scanf("%d%d", &u, &v);
			e[u].pb(v);
			e[v].pb(u);
		}
		dfs(1, 0);
		int sum = 0, tot = 0;
		rep(i, 1, n) sum += cnt[i];
		rep(i, 1, n) if(cnt[i] > 0) tot++;
		int ans = sum - tot + 1;
		printf("%d\n", ans);
	}
	return 0;
}