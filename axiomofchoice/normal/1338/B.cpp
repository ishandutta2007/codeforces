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
const int N=200010; const double err=1e-11; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<int,int> pii; template<typename A,typename B> ostream &operator<<(ostream &o,const pair<A,B> &x){return o<<'('<<x.fi<<','<<x.se<<')';}
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
vector<int> a[N];
int rt,ans;
int deg[N],cnt[N],depth[N];
int flag=true;
void dfs(int x,int fa){
	for(auto p:a[x])
	if(p!=fa){
		depth[p]=depth[x]+1;
		dfs(p,x);
		cnt[x]+=deg[p]==1;
	}
	if(deg[x]==1 && depth[x]%2==1)flag=false;
	if(depth[x]==1)ans-=cnt[x];
	else ans-=max(cnt[x]-1,0);
}
signed main(){
	int n=read();
	repeat(i,0,n-1){
		int x=read()-1,y=read()-1;
		a[x]+=y; a[y]+=x;
		deg[x]++,deg[y]++;
	}
	repeat(i,0,n){
		if(deg[i]==1){rt=i; break;}
	}
	dfs(rt,-1);
	//orzarr(cnt,n);
	ans+=n-1;
	cout<<(flag?1:3)<<' '<<ans<<endl;
	return 0;
}