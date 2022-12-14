#include <bits/stdc++.h>
using namespace std;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define mst(a,x) memset(a,x,sizeof(a))
#define fi first
#define se second
#ifndef qwq
int cansel_sync=[]{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
#endif
const double err=1e-11; typedef long long ll; const int inf=~0u>>2; const ll INF=~0ull>>2; ll read(){ll x; if(scanf("%lld",&x)==-1)exit(0); return x;} typedef double lf; typedef long double llf; const lf pi=acos(-1.0); lf readf(){lf x; if(scanf("%lf",&x)==-1)exit(0); return x;} template<typename T> T sqr(const T &x){return x*x;} typedef pair<int,int> pii; template<typename A,typename B> ostream &operator<<(ostream &o,const pair<A,B> &x){return o<<'('<<x.fi<<','<<x.se<<')';}
//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int N=200010;
const int mod=(1?1000000007:998244353); ll mul(ll a,ll b,ll m=mod){return a*b%m;} ll qpow(ll a,ll b,ll m=mod){ll ans=1; for(;b;a=mul(a,a,m),b>>=1)if(b&1)ans=mul(ans,a,m); return ans;} ll getinv(ll v,ll m=mod){return qpow(v,m-2,m);}
//#define int ll
int n,m;
vector<int> eu;
vector<int> a[N];
bool vis[N];
int pos[N],dep[N],fa[N];
struct ST{
	#define logN 21
	#define U(x,y) (dep[x]<dep[y]?x:y)
	ll a[N*2][logN];
	void init(){
		int n=eu.size();
		repeat(i,0,n)
			a[i][0]=eu[i];
		repeat(k,1,logN)
		repeat(i,0,n-(1<<k)+1)
			a[i][k]=U(a[i][k-1],a[i+(1<<(k-1))][k-1]);
	}
	ll query(int l,int r){
		if(l>r)swap(l,r);
		int s=31-__builtin_clz(r-l+1);
		return U(a[l][s],a[r-(1<<s)+1][s]);
	}
}st;
void dfs(int x,int d){
	if(vis[x])return;
	vis[x]=1;
	dep[x]=d;
	eu.push_back(x);
	pos[x]=eu.size()-1; //
	repeat(i,0,a[x].size()){
		int p=a[x][i];
		if(vis[p])continue;
		fa[p]=x;
		dfs(p,d+1);
		eu.push_back(x);
	}
}
int lca(int x,int y){
	return st.query(pos[x],pos[y]);
}
int q[N];
signed main(){
	cin>>n>>m;
	repeat(i,0,n-1){
		int x,y; cin>>x>>y; x--,y--;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	fa[0]=-1; dfs(0,1); st.init();
	while(m--){
		int s; cin>>s;
		int deepest=0;
		repeat(i,0,s){
			cin>>q[i],q[i]--;
			if(dep[deepest]<dep[q[i]])
				deepest=q[i];
		}
		bool f=1;
		repeat(i,0,s){
			int ancestor=lca(q[i],deepest);
			if(ancestor==q[i] || ancestor==fa[q[i]]);
			else f=0;
		}
		cout<<(f?"YES":"NO")<<endl;
	}
	return 0;
}