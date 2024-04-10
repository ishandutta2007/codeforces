#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define vector basic_string
#define fi first
#define se second
#ifndef qwq
int cansel_sync=(ios::sync_with_stdio(0),cin.tie(0),0);
#endif
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=300010; const double err=1e-11; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<int,int> pii; template<typename A,typename B> ostream &operator<<(ostream &o,const pair<A,B> &x){return o<<'('<<x.fi<<','<<x.se<<')';}
const int mod=(0?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
ll col[N],uncol[N],del[N],vis[N];
vector<int> a[N];
#define M(x) ((x)%mod)
void dfs(int x){
	ll muldel=1;
	vis[x]=1;
	col[x]=uncol[x]=del[x]=1;
	for(auto p:a[x])
	if(!vis[p]){
		dfs(p);
		col[x]=col[x]*M(col[p]+2*uncol[p]+2*del[p])%mod;
		uncol[x]=uncol[x]*M(2*col[p]+2*uncol[p]+3*del[p])%mod;
		del[x]=del[x]*M(col[p]+uncol[p]+del[p])%mod;
		muldel=(muldel*del[p])%mod;
	}
	col[x]=(col[x]-del[x])%mod;
	uncol[x]=(uncol[x]-del[x])%mod;
}
signed main(){
	int n=read();
	repeat(i,0,n-1){
		int x=read()-1,y=read()-1;
		a[x]+=y;
		a[y]+=x;
	}
	dfs(0);
	//orzarr((col),n);
	//orzarr(uncol,n);
	//orzarr((del),n);
	cout<<((col[0]+uncol[0]+del[0]-1)%mod+mod)%mod<<endl;
	return 0;
}