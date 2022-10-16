/*
	Powered by C++11.
	Author : Alex_Wei.
*/


//#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;

//#define int long long
#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define mpi make_pair
#define vint vector <int>
#define vpii vector <pii>
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

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
	void print(ll x) {if(x>9)print(x/10); pc(x%10+'0');}
}

namespace math{
	const int mod=99824353;
	const int maxn=1e6+5;

	ll ksm(ll a,ll b){ll s=1,m=a; while(b){if(b&1)s=s*m%mod; m=m*m%mod,b>>=1;} return s;}
	ll inv(ll x){return ksm(x,mod-2);}

	ll fc[maxn],ifc[maxn];
	void init_m(int n){
		fc[0]=1; for(int i=1;i<=n;i++)fc[i]=fc[i-1]*i%mod;
		ifc[n]=inv(fc[n]); for(int i=n-1;i>=0;i--)ifc[i]=ifc[i+1]*(i+1)%mod;
	}
	ll C(ll n,ll m){return fc[n]*ifc[m]%mod*ifc[n-m]%mod;}
}

using namespace IO;
//using namespace math;

const int N=2e5+5;

int ccnt,hd[N],nxt[N],vv[N];
void adde(int u,int v){
	nxt[++ccnt]=hd[u],hd[u]=ccnt,vv[ccnt]=v;
}

int n,m,cnt,son[N][26],f[N],edp[N];
string s[N];
vector <int> e[N];
 
void ins(int id){
	int p=0;
	for(char it:s[id]){
		if(!son[p][it-'a'])son[p][it-'a']=++cnt;
		p=son[p][it-'a'];
	} edp[id]=p;
}
void build(){
	queue <int> q;
	for(int i=0;i<26;i++)if(son[0][i])q.push(son[0][i]);
	while(!q.empty()){
		int t=q.front(); q.pop();
		for(int i=0;i<26;i++)
			if(son[t][i])f[son[t][i]]=son[f[t]][i],q.push(son[t][i]);
			else son[t][i]=son[f[t]][i];
		adde(f[t],t);
	}
}

int dn,sz[N],dfn[N];
ll c[N];
void add(int x,int v){
	while(x<=cnt+1)c[x]+=v,x+=x&-x;
}
ll query(int x){
	ll ans=0;
	while(x)ans+=c[x],x-=x&-x;
	return ans; 
}
void dfs(int id){
	sz[id]=1,dfn[id]=++dn;
	for(int i=hd[id];i;i=nxt[i])dfs(vv[i]),sz[id]+=sz[vv[i]];
}
struct qq{
	int id,qid,ans;
}; vector <qq> q[N];
ll ans[N<<2];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i],ins(i);
	build(),dfs(0);
	for(int i=1;i<=m;i++){
		int l=read(),r=read(),k=read();
		q[l-1].pb((qq){k,i,-1});
		q[r].pb((qq){k,i,1});
	} for(int i=1;i<=n;i++){
		int p=0;
		for(char it:s[i]){
			p=son[p][it-'a'];
			add(dfn[p],1);
		}
		for(qq it:q[i]){
			p=edp[it.id];
			ans[it.qid]+=it.ans*(query(dfn[p]+sz[p]-1)-query(dfn[p]-1));
		}
	} for(int i=1;i<=m;i++)print(ans[i]),pc('\n');
	return flush(),0;
}