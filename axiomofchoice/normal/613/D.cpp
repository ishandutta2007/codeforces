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
int cnt;
vector<int> e[N],v;
int pos[N];
int dep[N],son[N],sz[N],top[N],fa[N];
void dfs1(int x){
	pos[x]=++cnt;
	sz[x]=1;
	son[x]=-1;
	dep[x]=dep[fa[x]]+1;
	for(auto p:e[x]){
		if(p==fa[x])continue;
		fa[p]=x; dfs1(p);
		sz[x]+=sz[p];
		if(son[x]==-1 || sz[son[x]]<sz[p])
			son[x]=p;
	}
}
void dfs2(int x,int tv){
	top[x]=tv;
	if(son[x]==-1)return;
	dfs2(son[x],tv);
	for(auto p:e[x]){
		if(p==fa[x] || p==son[x])continue;
		dfs2(p,p);
	}
}
void init(int s){
	fa[s]=s;
	dfs1(s);
	dfs2(s,s);
}
int lca(int x,int y){
	while(top[x]!=top[y])
		if(dep[top[x]]>=dep[top[y]])x=fa[top[x]];
		else y=fa[top[y]];
	return dep[x]<dep[y]?x:y;
}
int length(int x,int y){
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
vector<int> stk,rec;
vector<pii> tr[N];
bool lab[N];
#define r stk.rbegin()
void add(){
	tr[r[1]].push_back({r[0],dep[r[0]]-dep[r[1]]});
	rec.push_back(r[0]);
	stk.pop_back();
}
int cost[N],up[N],flag;
void lastdfs(int x,int fa){
	if(lab[x]==0){
		int cnt=0;
		for(auto i:tr[x]){
			int p=i.fi; if(p==fa)continue;
			lastdfs(p,x);
			cnt+=up[p]; cost[x]+=cost[p];
		}
		if(cnt>=2){
			up[x]=0;
			cost[x]++;
		}
		else if(cnt==1)up[x]=1;
		else up[x]=0;
	}
	else{
		for(auto i:tr[x]){
			int p=i.fi; if(p==fa)continue;
			lastdfs(p,x);
			cost[x]+=cost[p];
			if(lab[p] && i.se==1)
				flag=false;
			if(up[p])cost[x]++;
		}
		up[x]=1;
	}
	//orz(x); orz(cost[x]); orz(up[x]);
}
void vtree(){
	sort(v.begin(),v.end(),[](int x,int y){
		return pos[x]<pos[y];
	});
	stk.assign(1,1); rec.assign(1,1);
	for(auto i:v)lab[i]=1;
	for(auto i:v)if(i!=1){
		int l=lca(i,r[0]);
		while(pos[l]<pos[r[0]]){
			if(pos[l]>pos[r[1]])
				stk.insert(stk.end()-1,l);
			add();
		}
		stk.push_back(i);
	}
	while(stk.size()>1)add();
	flag=true;
	lastdfs(1,-1);
	if(flag)printf("%d\n",cost[1]);
	else puts("-1");
	for(auto i:rec){
		tr[i].clear();
		lab[i]=0;
		cost[i]=0;
		up[i]=0;
	}
}
void Solve(){
	int n=read();
	repeat(i,0,n-1){
		int x=read(),y=read();
		e[x]<<y; e[y]<<x;
	}
	cnt=0; init(1);
	int m=read();
	while(m--){
		int t=read(); v.clear();
		while(t--)v<<(int)read();
		vtree();
	}
}
signed main(){
	//freopen("data.txt","r",stdin);
	int T=1; //T=read();
	repeat(ca,1,T+1){
		Solve();
	}
	return 0;
}