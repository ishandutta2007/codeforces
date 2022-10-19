#include<bits/stdc++.h>
#define ll long long
#define N 300015
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int t,n,m,vis[N],col[N];
VI e[N],g;
void dfs(int u){
	vis[u] = 1;
	g.pb(u);
	for(auto v:e[u]){
		if(vis[v]) continue;
		dfs(v);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		g.clear();
		rep(i,1,n) e[i].clear(),vis[i] = 0,col[i] = 0;
		rep(i,1,m){
			int u,v; scanf("%d%d",&u,&v);
			e[u].pb(v); e[v].pb(u);
		}
		dfs(1);
		if(g.size() != n){
			printf("NO\n");
		}else{
			printf("YES\n");
			for(auto u:g){
				bool flag = 0;
				for(auto v:e[u]){
					flag |= col[v];
				}
				if(!flag) col[u] = 1;
			}
			int res = 0;
			rep(i,1,n) res += col[i];
			printf("%d\n",res);
			rep(i,1,n) if(col[i]) printf("%d ",i);
			printf("\n");
		}
	}
	return 0;
}