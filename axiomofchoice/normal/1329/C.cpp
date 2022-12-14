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
const int N=2100010; const double err=1e-11; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<int,int> pii; template<typename A,typename B> ostream &operator<<(ostream &o,const pair<A,B> &x){return o<<'('<<x.fi<<','<<x.se<<')';}
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
int a[N],h,g;
#define lc (x*2)
#define rc (x*2+1)
#define bigch (a[lc]>a[rc]?lc:rc)
int height(int x){
	if(a[x]==0)return 0;
	return height(bigch)+1;
}
void del(int x){
	if(a[x]==0)return;
	a[x]=a[bigch];
	del(bigch);
}
vector<int> ans;
void dfs(int x,int dep){
	if(a[x]==0)return;
	while(height(x)+dep>g)del(x),ans+=x;
	dfs(lc,dep+1); dfs(rc,dep+1);
}
signed main(){
	int T=read();
	while(T--){
		h=read(),g=read();
		fill(a,a+(1<<h)*2+2,0);
		repeat(i,1,(1<<h))a[i]=read();
		ans.clear();
		dfs(1,0);
		ll s=0;
		repeat(i,1,(1<<g))s+=a[i];
		cout<<s<<endl;
		for(auto i:ans)cout<<i<<' '; cout<<endl;
	}
	return 0;
}