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
vector<int> a[N]; 
namespace center{
vector<int> rec;
int sz[N],maxx[N];
void dfs(int x,int fa=-1){
	rec<<x;
	sz[x]=1; maxx[x]=0;
	for(auto i:a[x]){
		int p=i;
		if(p!=fa){
			dfs(p,x);
			sz[x]+=sz[p];
			maxx[x]=max(maxx[x],sz[p]);
		}
	}
}
int get(int x){ //get center
	rec.clear(); dfs(x); int n=sz[x],ans=x;
	for(auto x:rec){
		maxx[x]=max(maxx[x],n-sz[x]);
		if(maxx[x]<maxx[ans])ans=x;
	}
	return ans;
}
}using namespace center;
void Solve(){
	int n=read(); repeat(i,1,n+1)a[i].clear();
	repeat(i,0,n-1){
		int x=read(),y=read();
		a[x]<<y; a[y]<<x;
	}
	int c=get(1);
	get(c);
	if(maxx[c]==1){
		cout<<c<<' '<<a[c][0]<<endl;
		cout<<c<<' '<<a[c][0]<<endl;
		return;
	}
	int p1,p2;
	for(auto i:a[c])if(maxx[c]==sz[i])p1=i;
	for(auto i:a[p1])if(c!=i)p2=i;
	cout<<p1<<' '<<p2<<endl;
	cout<<p2<<' '<<c<<endl;
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}