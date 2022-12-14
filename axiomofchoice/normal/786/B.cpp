#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=2000010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
//#define int ll
typedef vector<pii> node;
node a[N]; int top;
struct seg{
	int n;
	void init(int inn){
		for(n=1;n<inn;n<<=1); top=n*4;
		repeat(i,0,n*4)a[i].clear();
		repeat(i,1,n){
			a[i]<<pii(i*2,0);
			a[i]<<pii(i*2+1,0);
			a[i*2+n*2]<<pii(i+n*2,0);
			a[i*2+1+n*2]<<pii(i+n*2,0);
		}
		repeat(i,0,inn){
			a[i+n]<<pii(i+n*3,0);
			a[i+n*3]<<pii(i+n,0);
		}
	}
	void b_add(int l,int r,int x,int w){
		for(l+=n-1,r+=n+1;l^r^1;l>>=1,r>>=1){
			if(~l & 1)a[(l^1)+n*2]<<pii(x,w);
			if(r & 1)a[(r^1)+n*2]<<pii(x,w);
		}
	}
	void a_add(int l,int r,int x,int w){
		for(l+=n-1,r+=n+1;l^r^1;l>>=1,r>>=1){
			if(~l & 1)a[x]<<pii(l^1,w);
			if(r & 1)a[x]<<pii(r^1,w);
		}
	}
}tr;
void add(int x1,int y1,int x2,int y2,int w){
	int s=top++;
	tr.b_add(x1,y1,s,w);
	tr.a_add(x2,y2,s,0);
}
#define inf INF
namespace dij{
struct op{
	bool operator()(pii a,pii b){
		return a.se>b.se;
	}
};
int n;
bool vis[N];
ll dis[N];
void dij(int s){
	fill(vis,vis+n+1,0);
	fill(dis,dis+n+1,inf); dis[s]=0;
	static priority_queue<pii,vector<pii>,op> q; q.push({s,0});
	while(!q.empty()){
		int x=q.top().fi; q.pop();
		if(vis[x])continue; vis[x]=1;
		for(auto i:a[x]){
			int p=i.fi;
			if(dis[p]>dis[x]+i.se){
				dis[p]=dis[x]+i.se;
				q.push({p,dis[p]});
			}
		}
	}
}
}
void Solve(){
	int n=read(),q=read(),s=read()-1;
	tr.init(n);
	while(q--){
		int t=read();
		if(t==1){
			int x=read()-1,y=read()-1,w=read();
			add(x,x,y,y,w);
		}
		else if(t==2){
			int x=read()-1,l=read()-1,r=read()-1,w=read();
			add(x,x,l,r,w);
		}
		else{
			int x=read()-1,l=read()-1,r=read()-1,w=read();
			add(l,r,x,x,w);
		}
	}
//	cout<<"build end"<<endl;
//	orz(tr.n);
//	repeat(i,0,tr.n*6){
//		cout<<i<<": ";
//		for(auto j:a[i])cout<<j.fi<<' ';
//		cout<<endl;
//	}
	dij::n=top; dij::dij(s+tr.n);
	//cout<<"dij end"<<endl;
	repeat(i,0,n)printf("%lld ",(dij::dis[i+tr.n]!=inf?dij::dis[i+tr.n]:-1));
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}