#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=1010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
struct node{
	int to; ll dis;
	bool operator<(const node &b)const{
		return dis>b.dis;
	}
};
int n;
bool vis[N];
vector<node> a[N];
int g[N][N];
void dij(int s,int dis[]){
	fill(vis,vis+n+1,0);
	fill(dis,dis+n+1,inf); dis[s]=0; //last[s]=-1;
	static priority_queue<node> q; q.push({s,0});
	while(!q.empty()){
		int x=q.top().to; q.pop();
		if(vis[x])continue; vis[x]=1;
		for(auto i:a[x]){
			int p=i.to;
			if(dis[p]>dis[x]+i.dis){
				dis[p]=dis[x]+i.dis;
				q.push({p,dis[p]});
				//last[p]=x; //last???????(??)
			}
		}
	}
}
typedef array<int,3> edge;
vector<pii> e;
vector<pii> q;
void Solve(){
	n=read(); int m=read(),k=read();
	while(m--){
		int x=read(),y=read(),w=read();
		e<<pii(x,y);
		a[x]<<(node){y,w};
		a[y]<<(node){x,w};
	}
	repeat(i,0,k)q<<pii(read(),read());
	repeat(i,1,n+1)
		dij(i,g[i]);
	int ans=inf;
	for(auto i:e){
		int now=0;
		for(auto k:q){
			now+=min({g[k.fi][k.se],
				g[k.fi][i.fi]+g[k.se][i.se],
				g[k.fi][i.se]+g[k.se][i.fi]});
		}
		ans=min(ans,now);
	}
	cout<<ans<<endl;
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}