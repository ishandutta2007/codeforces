#include<bits/stdc++.h>
#define ll long long
#define N 200015
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
using namespace std;
int n,m;
pii edge[N];
namespace dij1{
	const int T = 20;
	int dis[N*T],vis[N*T];
	vector<pii> e[N*T];
	void add(int u,int v,int w){/*printf("%d %d %d\n",u,v,w); */e[u].pb(mp(v,w));}
	priority_queue<pii,vector<pii>,greater<pii> > q;
	void dij(){
		q.push(mp(0,1));
		memset(dis,0x3f,sizeof dis);
		dis[1] = 0;
		while(!q.empty()){
			int u = q.top().se; q.pop();
			if(vis[u]) continue;
			vis[u] = 1;
			for(auto V:e[u]){
				int v = V.fi,w = V.se;
				if(dis[v] > dis[u]+w){
					dis[v] = dis[u]+w;
					q.push(mp(dis[v],v));
				}
			}
		}
	}
	int solve(){
		rep(_,0,T-1){
			if(_ != T-1)
				rep(i,1,n) add(_*n+i,(_+1)*n+i,(1<<_));
			rep(i,1,m){
				int u = edge[i].fi,v = edge[i].se;
				if(_&1) add(_*n+v,_*n+u,1);
				else add(_*n+u,_*n+v,1);
			}
		}
		dij();
		int res = inf;
		rep(_,0,T-1) res = min(res,dis[_*n+n]);//,printf("fuck: %d %d\n",_*n+n,dis[_*n+n]);
		if(res == inf) return 0;
		printf("%d\n",res%mod);
		return 1;
	}
}
namespace dij2{
	vector<pair<int,pii> > e[N<<2];
	priority_queue<pair<pii,int>,vector<pair<pii,int> >,greater<pair<pii,int> > > q;
	pii dis[N<<2];
	int vis[N<<2];
	void add(int u,int v,pii w){e[u].pb(mp(v,w));}
	int qpow(int a,int b){
		int res = 1;
		while(b){
			if(b&1) res = (1ll*res*a)%mod;
			a = (1ll*a*a)%mod;
			b >>= 1;
		}
		return res;
	}
	void dij(){
		q.push(mp(mp(0,0),1));
		rep(i,1,n*2) dis[i] = mp(inf,inf);
		dis[1] = mp(0,0);
		while(!q.empty()){
			int u = q.top().se; q.pop();
			if(vis[u]) continue;
			vis[u] = 1;
			for(pair<int,pii> V:e[u]){
				int v = V.fi,w1 = V.se.fi,w2 = V.se.se;
				pii nxt = mp(dis[u].fi+w1,dis[u].se+w2);
				if(dis[v] > nxt){
					dis[v] = nxt;
					q.push(mp(dis[v],v));
				}
			}
		}
	}
	void solve(){
		rep(i,1,m){
			int u = edge[i].fi,v = edge[i].se;
			add(u,v,mp(0,1));
			add(v+n,u+n,mp(0,1));
		}
		rep(i,1,n) add(i,i+n,mp(1,0)),add(i+n,i,mp(1,0));
		dij();
		pii ans = min(dis[n],dis[n*2]);
		printf("%d\n",((qpow(2,ans.fi)+ans.se)%mod+mod-1)%mod);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%d%d",&n,&m);
 	rep(i,1,m)
 		scanf("%d%d",&edge[i].fi,&edge[i].se);
 	if(dij1::solve()) return 0;
 	dij2::solve();
	return 0;
}