#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
using namespace std;
int n,m,dis[N*55];
vector<pii> e[N*55];
priority_queue<pii,vector<pii>,greater<pii>> q;
void add(int u,int v,int w){
	e[u].pb(mp(v,w));
}
void dij(){
	rep(i,1,n*51) dis[i] = inf;
	dis[1] = 0;
	q.push(mp(0,1));
	while(!q.empty()){
		int u = q.top().se; q.pop();
		for(auto I:e[u]){
			int v = I.fi,w = I.se;
			if(dis[u]+w < dis[v]) dis[v] = dis[u]+w,q.push(mp(dis[v],v));
		}
	}
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d",&n,&m);
 	rep(i,1,m){
 		int u,v,w; scanf("%d%d%d",&u,&v,&w);
 		add(u,v+w*n,0);
 		rep(_,1,50) add(u+_*n,v,(_+w)*(_+w)); swap(u,v);
 		add(u,v+w*n,0);
 		rep(_,1,50) add(u+_*n,v,(_+w)*(_+w)); swap(u,v);
 	}
 	dij();
 	rep(i,1,n) printf("%d ",(dis[i]==inf)?-1:dis[i]);
	return 0;
}