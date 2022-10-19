#include<bits/stdc++.h>
#define ll long long
#define N 1015
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
int a,b,m,g[N][N],ans[100015],Min[2][N],to[2][N][N],deg[2][N];
void dfs(int typ,int cur,int lst,int c1,int c2){
	int nxt = to[typ^1][cur][c1];
	to[typ][lst][c1] = cur; to[typ^1][cur][c1] = lst;
	if(nxt) dfs(typ^1,nxt,cur,c2,c1);
	else to[typ^1][cur][c2] = 0;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d%d",&a,&b,&m);
 	rep(i,1,m){
 		int u,v; scanf("%d%d",&u,&v);
 		g[u][v] = i;
 		int mu = 1,mv = 1;
 		deg[0][u]++; deg[1][v]++;
 		while(to[0][u][mu]) mu++;
 		while(to[1][v][mv]) mv++;
 		if(mu == mv) to[0][u][mu] = v,to[1][v][mv] = u;
 		else{
 			if(mu < mv) dfs(0,v,u,mu,mv);
 			else dfs(1,u,v,mv,mu);
 		}
 	}
 	int mx = 0;
 	rep(i,1,a) mx = max(mx,deg[0][i]);
 	rep(i,1,b) mx = max(mx,deg[1][i]);
 	printf("%d\n",mx);
 	rep(i,1,a) rep(j,1,mx) if(to[0][i][j]) ans[g[i][to[0][i][j]]] = j;
 	rep(i,1,m) printf("%d ",ans[i]);
	return 0;
}