#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
struct node{
	int x,y,id;
}s,t,a[N];
int ans;
int dis[N]; bool vis[N];
int dist(node a,node b){
	return min(abs(a.x-b.x),abs(a.y-b.y));
}
struct node2{
	int to; ll dis;
	bool operator<(const node2 &b)const{
		return dis>b.dis;
	}
};
vector<node2> e[N];
void Solve(){
	int n=(read(),read());
	s.x=read(),s.y=read(),t.x=read(),t.y=read();
	ans=abs(s.x-t.x)+abs(s.y-t.y);
	repeat(i,0,n)a[i].x=read(),a[i].y=read(),a[i].id=i;
	sort(a,a+n,[](node a,node b){return a.x<b.x;});
	repeat(i,0,n-1){
		e[a[i].id]<<(node2){a[i+1].id,dist(a[i],a[i+1])};
		e[a[i+1].id]<<(node2){a[i].id,dist(a[i],a[i+1])};
	}
	sort(a,a+n,[](node a,node b){return a.y<b.y;});
	repeat(i,0,n-1){
		e[a[i].id]<<(node2){a[i+1].id,dist(a[i],a[i+1])};
		e[a[i+1].id]<<(node2){a[i].id,dist(a[i],a[i+1])};
	}
	sort(a,a+n,[](node a,node b){return a.id<b.id;});
	static priority_queue<node2> q;
	repeat(i,0,n){
		dis[i]=dist(s,a[i]);
		q.push({i,dis[i]});
	}
	//orzarr(dis,n);
	while(!q.empty()){
		int x=q.top().to; q.pop();
		if(vis[x])continue; vis[x]=1;
		for(auto i:e[x]){
			int p=i.to;
			if(dis[p]>dis[x]+i.dis){
				dis[p]=dis[x]+i.dis;
				q.push({p,dis[p]});
			}
		}
	}
	//orzarr(dis,n);
	repeat(i,0,n){
		ans=min(ans,dis[i]+abs(a[i].x-t.x)+abs(a[i].y-t.y));
		//orz(abs(a[i].x-t.x)+abs(a[i].y-t.y));
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