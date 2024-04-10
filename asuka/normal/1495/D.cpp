#include<bits/stdc++.h>
#define ll long long
#define N 405
#define mod 998244353
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
int n,m,dis[N][N],Ans[N][N];
VI e[N];
queue<int> q;
void bfs(int s,int d[]){
	rep(i,1,n) d[i] = inf;
	q.push(s); d[s] = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(auto v:e[u]){
			if(d[v] > d[u]+1){
				d[v] = d[u]+1;
				q.push(v);
			}
		}
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		int u,v; scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	rep(i,1,n) bfs(i,dis[i]);
	rep(u,1,n) rep(v,1,n){
		int cnt = 0;
		ll ans = 1;
		rep(i,1,n) if(dis[i][u]+dis[i][v] == dis[u][v]) cnt++;
		// printf("%d %d %d %d\n",u,v,dis[u][v],cnt);
		if(cnt - 1 != dis[u][v]) ans = 0;
		rep(i,1,n){
			if(dis[i][u]+dis[i][v] == dis[u][v]) continue;
			int cur = 0;
			// printf("other %d\n",i);
			for(auto x:e[i]){
				if(dis[x][u] == dis[i][u]-1 && dis[x][v] == dis[i][v]-1) cur++;
			}
			// printf("%d\n",cur);
			ans = (ans*cur)%mod;
		}
		Ans[u][v] = ans;
	}
	rep(i,1,n){
		rep(j,1,n){
			printf("%d ",Ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}