/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

//#pragma GCC optimize(3)
//#define int long long

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
using pii = pair <int,int>;
using pll = pair <ll,ll>;
using pdd = pair <double,double>;
using vint = vector <int>;
using vpii = vector <pii>;

#define fi first
#define se second
#define pb emplace_back
#define mpi make_pair
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))
#define mcpy(x,y) memcpy(x,y,sizeof(y))

namespace IO{
	char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
	#ifdef __WIN32
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)

	inline int read(){
		int x=0,sign=0; char s=gc;
		while(!isdigit(s))sign|=s=='-',s=gc;
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=gc;
		return sign?-x:x;
	}
	void print(int x){
		if(x<0)return pc('-'),print(-x),void();
		if(x>9)print(x/10);
		pc(x%10+'0');
	}
}

namespace math{
	const int mod=99824353;
	const int maxn=2e6+5;

	ll ksm(ll a,ll b,ll p){
		ll s=1,m=a%p;
		while(b){
			if(b&1)s=s*m%p;
			m=m*m%p,b>>=1;
		} return s;
	} ll ksm(ll a,ll b){
		ll s=1,m=a%mod;
		while(b){
			if(b&1)s=s*m%mod;
			m=m*m%mod,b>>=1;
		} return s;
	} ll inv(ll x){return ksm(x,mod-2);}

	ll fc[maxn],ifc[maxn];
	void init_m(int n){
		fc[0]=1;
		for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
		ifc[n]=inv(fc[n]);
		for(int i=n-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	} ll C(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

using namespace IO;
//using namespace math;

const int N=4e5+5;

int n,m,ans[N];
int cnt,dn,son[N][26],ed[N],fa[N],sz[N],dfn[N];
vector <int> e[N],f[N],ft[N];
char ad[N];
void ins(int id,string s){
	int p=0;
	for(char it:s){
		if(!son[p][it-'a'])son[p][it-'a']=++cnt;
		p=son[p][it-'a'];
	} ed[id]=p;
} void build(){
	queue <int> q;
	for(int i=0;i<26;i++)if(son[0][i])q.push(son[0][i]);
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int i=0;i<26;i++)
			if(son[t][i])q.push(son[t][i]),fa[son[t][i]]=son[fa[t]][i];
			else son[t][i]=son[fa[t]][i];
		ft[fa[t]].pb(t);
	}
} void dfs(int id){
	dfn[id]=++dn,sz[id]=1;
	for(int it:ft[id])dfs(it),sz[id]+=sz[it];
}

int c[N];
void add(int x,int v){while(x<=dn)c[x]+=v,x+=x&-x;}
int query(int x){int ans=0; while(x)ans+=c[x],x-=x&-x; return ans;}
int query(int l,int r){return query(r)-query(l-1);}
void cal(int id,int p){
	if(id)p=son[p][ad[id]-'a'],add(dfn[p],1);
	for(int it:e[id])ans[it]=query(dfn[ed[it]],dfn[ed[it]]+sz[ed[it]]-1);
	for(int it:f[id])cal(it,p);
	add(dfn[p],-1);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int tp,p=0; cin>>tp;
		if(tp==2)cin>>p;
		f[p].pb(i),cin>>ad[i];
	} cin>>m;
	string q;
	for(int i=1,id;i<=m;i++)
		cin>>id>>q,e[id].pb(i),ins(i,q);
	build(),dfs(0),cal(0,0);
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return flush(),0;
}