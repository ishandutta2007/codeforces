/*
	Powered by C++11.
	Author : Alex_Wei.
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize(3)
//#define int long long

#define ll long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb emplace_back
#define all(x) x.begin(),x.end()
#define sor(x) sort(all(x))
#define rev(x) reverse(all(x))
#define mem(x,v) memset(x,v,sizeof(x))

// Templates start.

namespace IO{
	char buf[1<<21],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
	#ifdef __WIN64
		#define gc getchar()
	#else
		#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
	#endif
	#define pc(x) (*O++=x)
	#define flush() fwrite(obuf,O-obuf,1,stdout)

	inline int read(){
		int x=0,sign=0; char s=getchar();
		while(!isdigit(s))sign|=s=='-',s=getchar();
		while(isdigit(s))x=(x<<1)+(x<<3)+(s-'0'),s=getchar();
		return sign?-x:x;
	}
	void print(int x) {if(x>9)print(x/10); pc(x%10+'0');}
}

namespace math{
	const int mod=1e9+7;
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

// Templates end. Please give me more points.

using namespace IO;
//using namespace math;

const int N=(1<<20)+5;

struct edge {int u,v,to,d;}vv[N];
int c,hd[N],nxt[N];
void add(int u,edge t){nxt[++c]=hd[u],hd[u]=c,vv[c]=t;}

int n,a[N],b[N],v[N];
vector <int> ans;

void cir(int id){
	for(int i=hd[id];i;i=hd[id]){
		hd[id]=nxt[i]; edge it=vv[i];
		if(!v[it.d])v[it.d]=1,cir(it.to),ans.pb(it.v),ans.pb(it.u);
	}
}

void end(int k){
	int bs=(1<<k)-1; mem(v,0);
	for(int i=1;i<=n;i++){
		int c=a[i]&bs,d=b[i]&bs;
		add(c,(edge){i*2-1,i*2,d,i}),add(d,(edge){i*2,i*2-1,c,i});
	} cir(a[1]&bs);
	cout<<k<<endl; for(int it:ans)cout<<it<<" ";
	exit(0);
}

vector <int> e[N];

void dfs(int id){v[id]=1; for(int it:e[id])if(!v[it])dfs(it);}
int block(int k){int c=0; for(int i=0;i<1<<k;i++)if(e[i].size()&&!v[i]){c++,dfs(i);} return c;}

int main(){
	n=read(); for(int i=1;i<=n;i++)a[i]=read(),b[i]=read();
	for(int i=1,bs=1;i<=20;i++,bs=(bs<<1)+1,mem(v,0)){
		for(int j=0;j<1<<i;j++)e[j].clear();
		for(int j=1;j<=n;j++){int c=a[j]&bs,d=b[j]&bs; e[c].pb(d),e[d].pb(c);}
		int od=0; for(int j=0;j<(1<<i);j++)od|=e[j].size()&1;
		if(od||block(i)!=1)end(i-1);
	} end(20);
	return 0;
}