//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
//#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
//#pragma GCC optimize("move-loop-invariants")
//#pragma GCC optimize("unswitch-loops")
//#pragma GCC optimize("branch-target-load-optimize")
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=5e5;
const int MOD=1e9+7;
const int INV2=MOD+1>>1;
const int INV4=MOD+1>>2;
const int INV8=MOD+1>>3;
const int INV16=((MOD+9>>4)-INV2+MOD)%MOD;
int n,m,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dfn[MAXN+5],fa[MAXN+5],tim=0,ipw2[MAXN+5];
vector<int> cyc[MAXN+5],bel[MAXN+5];
int cycnt=0,P[MAXN+5],deg[MAXN+5];
void dfs(int x){
	dfn[x]=++tim;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];
		if(!dfn[y]) fa[y]=x,dfs(y);
		else if(dfn[y]<dfn[x]&&y!=fa[x]){
			cycnt++;
			for(int i=x;i^y;i=fa[i]) cyc[cycnt].pb(i),bel[i].pb(cycnt);
			cyc[cycnt].pb(y);bel[y].pb(cycnt);
		}
	}
}
int Ea(){return 1ll*n*INV2%MOD;}
int Eb(){return 1ll*m*INV4%MOD;}
int Ec(){int sum=0;for(int i=1;i<=cycnt;i++) sum=(sum+P[i])%MOD;return sum;}
int Ex(){return (0ll+Ea()-Eb()+Ec()+MOD)%MOD;}
int Eaa(){return 1ll*n*(n+1)%MOD*INV4%MOD;}
int Ebb(){
	ll tot=1ll*m*(m-1);int res=1ll*m*INV4%MOD;
	for(int i=1;i<=n;i++){
		tot-=1ll*deg[i]*(deg[i]-1);
		res=(res+1ll*deg[i]*(deg[i]-1)%MOD*INV8)%MOD;
	} res=(res+1ll*tot%MOD*INV16)%MOD;
	return res;
}
int Ecc(){
	ll tot=1ll*cycnt*(cycnt-1);int res=Ec(),sum=0;
	for(int i=1;i<=cycnt;i++) res=(res+2ll*sum*P[i])%MOD,sum=(sum+P[i])%MOD;
	for(int i=1;i<=n;i++){
		int ssum=0;
		for(int j:bel[i]) res=(res+2ll*ssum*P[j])%MOD,ssum=(ssum+P[j])%MOD;
	} return res;
}
int Eab(){
	int res=0;
	for(int i=1;i<=n;i++) res=(res+1ll*INV4*deg[i]+1ll*INV8*(m-deg[i]))%MOD;
	return res;
}
int Eac(){
	int res=0,sm=Ec();
	for(int i=1;i<=n;i++){
		int ssum=0;
		for(int j:bel[i]) ssum=(ssum+P[j])%MOD;
		res=(0ll+res+ssum+1ll*INV2*(sm-ssum+MOD))%MOD;
	} return res;
}
int Ebc(){
	int res=0;
	for(int i=1;i<=cycnt;i++) res=(res+1ll*P[i]*cyc[i].size())%MOD;
	for(int i=1;i<=cycnt;i++){
		int sum_ed=0,rst;
		for(int j:cyc[i]) sum_ed+=deg[j]-2;
		rst=m-cyc[i].size()-sum_ed;
		res=(0ll+res+1ll*P[i]*INV2%MOD*sum_ed+1ll*P[i]*INV4%MOD*rst)%MOD;
	} return res;
}
int sqr(int x){return 1ll*x*x%MOD;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=(ipw2[0]=1);i<=n;i++) ipw2[i]=1ll*ipw2[i-1]*INV2%MOD;
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);adde(u,v);adde(v,u);
		deg[u]++;deg[v]++;
	} dfs(1);for(int i=1;i<=cycnt;i++) P[i]=ipw2[cyc[i].size()];
//	printf("%d\n",Ec());
	printf("%d\n",((0ll+Eaa()+Ebb()+Ecc()-2ll*Eab()-2ll*Ebc()+2ll*Eac()-sqr(Ex()))%MOD+MOD)%MOD);
	return 0;
}