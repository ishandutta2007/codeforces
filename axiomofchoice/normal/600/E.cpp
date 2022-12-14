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
const int N=200010; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} typedef pair<ll,ll> pii; template<typename T> void operator<<(vector<T> &a,T b){a.push_back(b);}
const ll mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;}
//#define int ll
vector<int> e[N]; int n;
int sz[N],son[N],dep[N]; bool vis[N];
ll ans[N],sum[N]; int num[N],top,c[N];
void initdfs(int x,int fa){
	dep[x]=dep[fa]+1; sz[x]=1;
	for(auto p:e[x])if(p!=fa){
		initdfs(p,x); sz[x]+=sz[p];
		if(sz[p]>sz[son[x]])son[x]=p;
	}
}
void update(int x,int fa,int op){
	sum[num[c[x]]]-=c[x]; num[c[x]]+=op; sum[num[c[x]]]+=c[x];
	if(sum[top+1])++top; if(!sum[top])--top;
	for(auto p:e[x])if(p!=fa && !vis[p])
		update(p,x,op);
}
void dfs(int x,int fa,int hs){
	for(auto p:e[x])if(p!=fa && p!=son[x])
		dfs(p,x,0);
	if(son[x])dfs(son[x],x,1),vis[son[x]]=1;
	update(x,fa,1);
	vis[son[x]]=0; ans[x]=sum[top];
	if(!hs)update(x,fa,-1);
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i)c[i]=read();
	for(int i=1;i<n;++i){
		int x=read(),y=read();
		e[x]<<y; e[y]<<x;
	}
	initdfs(1,0); dfs(1,0,1);
	for(int i=1;i<=n;++i)
		printf("%lld ",ans[i]);
	puts("");
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}