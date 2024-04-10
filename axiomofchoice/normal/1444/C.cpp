//#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
const int N=500010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
#define int ll
namespace DSU{
	int a[N],r[N],sz[N];
	vector<pair<int *,int>> rec;
	void init(int n){
		repeat(i,0,n+1)a[i]=i,r[i]=0,sz[i]=1;
	}
	int plus(int a,int b){
		return a^b;
	}
	int inv(int a){
		return a;
	}
	int fa(int x){
		return a[x]==x?x:fa(a[x]);
	}
	int R(int x){
		return a[x]==x?r[x]:plus(r[x],R(a[x]));
	}
	int R(int x,int y){
		return plus(R(x),inv(R(y)));
	}
	void join(int x,int y,int r2){
		r2=plus(R(y,x),r2);
		x=fa(x),y=fa(y);
		if(sz[x]>sz[y])swap(x,y),r2=inv(r2);
		rec.push_back({&a[x],a[x]});
		rec.push_back({&r[x],r[x]});
		rec.push_back({&sz[y],sz[y]});
		a[x]=y; r[x]=r2; sz[y]+=sz[x];
	}
	void undo(){
		repeat_back(i,0,rec.size())*rec[i].fi=rec[i].se;
		rec.clear();
	}
}using namespace DSU;
int co[N],kill[N];
map<pii,vector<pii>> e;
void Solve(){
	int n=read(),m=read(),k=read(); init(n);
	repeat(i,1,n+1)co[i]=read();
	repeat(i,0,m){
		int x=read(),y=read(); if(co[x]>co[y])swap(x,y);
		if(co[x]==co[y]){
			if(fa(x)!=fa(y))join(x,y,1);
			else if(R(x,y)==0)kill[co[x]]=1;
		}
		else e[{co[x],co[y]}].push_back({x,y});
	}
	ll ans=0;
	repeat(i,1,k+1)if(!kill[i])ans++;
	ans=ans*(ans-1)/2;
	rec.clear();
//	orzarr(a+1,n);
//	orzarr(r+1,n);
//	orzarr(sz+1,n);
	for(auto &i:e){ //qwq;
		int co1=i.fi.fi,co2=i.fi.se;
		if(kill[co1] || kill[co2])continue;
		int f=true;
		for(auto j:i.se){ //orz(j);
			int x=j.fi,y=j.se;
			if(fa(x)!=fa(y))join(x,y,1);
			else if(R(x,y)==0)f=false;
//	orzarr(a+1,n);
//	orzarr(r+1,n);
//	orzarr(sz+1,n);
		}
		if(f==false)ans--;
		undo();
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