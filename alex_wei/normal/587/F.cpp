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

const int N=1e5+5;

int n,m,M,len,cnt,son[N][26],f[N],edp[N];
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
		e[f[t]].pb(t);
	}
}

int dn,dfn[N],sz[N],ch[N],top[N],tag[N],c[N],d[N];
void add(int x,int v){ll t=x; while(x<=cnt+1)c[x]+=v,d[x]+=v*t,x+=x&-x;}
ll query(int x){ll ans=0,t=x+1; while(x)ans+=c[x]*t-d[x],x-=x&-x; return ans;}
void adds(int l,int r){add(l,1),add(r+1,-1);}
ll querys(int l,int r){return query(r)-query(l-1);}
void dfs(int id){
	sz[id]=1,dfn[id]=++dn;
	for(int it:e[id])dfs(it),sz[id]+=sz[it];
}

struct quer{int id,qid,ans;};
vector <quer> q[N],q2[N];
ll ans[N],pre[N];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i],ins(i),len+=s[i].size(); M=1.0*len/sqrt(m*log2(len));
	for(int i=1;i<=m;i++){
		int l=read(),r=read(),k=read();
		if(s[k].size()<M)q[r].pb((quer){k,i,1}),q[l-1].pb((quer){k,i,-1});
		else q2[k].pb((quer){l,r,i});
	} build(),dfs(0);
	for(int i=1;i<=n;i++)
		if(s[i].size()>=M){
			int p=0; mem(pre,0),mem(c,0),mem(d,0); 
			for(char it:s[i])p=son[p][it-'a'],adds(dfn[p],dfn[p]);
			for(int j=1;j<=n;j++)pre[j]=pre[j-1]+querys(dfn[edp[j]],dfn[edp[j]]+sz[edp[j]]-1);
			for(quer it:q2[i])ans[it.ans]=pre[it.qid]-pre[it.id-1];
		} mem(c,0),mem(d,0);
	for(int i=1;i<=n;i++){
		adds(dfn[edp[i]],dfn[edp[i]]+sz[edp[i]]-1);
		for(quer it:q[i]){
			ll p=0,cnt=0;
			for(char t:s[it.id]){
				p=son[p][t-'a'];
				cnt+=querys(dfn[p],dfn[p]);
			} ans[it.qid]+=it.ans*cnt;
		}
	} for(int i=1;i<=m;i++)print(ans[i]),pc('\n');
	return flush(),0;
}