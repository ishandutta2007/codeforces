#include<bits/stdc++.h>
#define ll long long
#define N 500015
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
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int dep[N],pa[N],vis[N];
int n,m;
VI e[N],t[N];
vector<pii> ans;
void dfs(int u,int fa){
	pa[u] = fa; vis[u] = 1;
	dep[u] = dep[fa]+1;
	t[dep[u]].pb(u);
	for(auto v:e[u]) if(!vis[v]){
		dfs(v,u);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		ans.clear();
		rep(i,1,n) e[i].clear(),t[i].clear();
		rep(i,1,n) vis[i] = dep[i] = pa[i] = 0;
		rep(i,1,m){
			int u,v; scanf("%d%d",&u,&v);
			e[u].pb(v); e[v].pb(u);
		}
		dfs(1,0);
		rep(i,1,n){
			if(dep[i] >= (n+1)/2){
				printf("PATH\n");
				printf("%d\n",dep[i]);
				int u = i;
				do{
					printf("%d ",u);
					u = pa[u];
				}while(u);
				printf("\n"); goto flag;
			}
		}
		rep(i,1,n){
			for(int j = 0;j+1 < SZ(t[i]);j += 2){
				ans.pb(mp(t[i][j],t[i][j+1]));
			}
		}
		printf("PAIRING\n");
		printf("%d\n",SZ(ans));
		for(auto u:ans) printf("%d %d\n",u.fi,u.se);
		flag:continue;
	}
	return 0;
}