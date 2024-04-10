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
int n,m,ont[MAXN+5];pii e[MAXN+5];
int ff[MAXN+5],hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],id[MAXN*2+5],ec=0;
void adde(int u,int v,int w){to[++ec]=v;id[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
int find(int x){return (!ff[x])?x:ff[x]=find(ff[x]);}
bool merge(int x,int y){x=find(x);y=find(y);if(x^y) return ff[x]=y,1;else return 0;}
int dep[MAXN+5],fa[MAXN+5],fw[MAXN+5];
void dfs(int x,int f){
	fa[x]=f;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=id[e];if(y==f) continue;
		dep[y]=dep[x]+1;fw[y]=z;dfs(y,x);
	}
}
int f[MAXN+5],dp[MAXN+5];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&e[i].fi,&e[i].se);
	for(int i=m;i;i--){
		if(merge(e[i].fi,e[i].se)) adde(e[i].fi,e[i].se,i),adde(e[i].se,e[i].fi,i);
		else ont[i]=1;
	} dfs(1,0);
	for(int i=1;i<=n;i++) f[i]=1;
	for(int i=m;i;i--){
		if(!ont[i]) f[e[i].fi]=f[e[i].se]=dp[i]=f[e[i].fi]+f[e[i].se];
		else{
			vector<int> A,B,AB;
			int u=e[i].fi,v=e[i].se;
			while(dep[u]>dep[v]) A.pb(fw[u]),u=fa[u];
			while(dep[v]>dep[u]) B.pb(fw[v]),v=fa[v];
			while(u^v) A.pb(fw[u]),u=fa[u],B.pb(fw[v]),v=fa[v];
			for(int j=0;j<A.size();j++) AB.pb(A[j]);
			for(int j=(int)(B.size())-1;~j;j--) AB.pb(B[j]);
			int L=0,R=(int)(AB.size())-1;
			while(L+1<AB.size()&&AB[L]<AB[L+1]) ++L;
			while(R-1>=0&&AB[R]<AB[R-1]) --R;
			if(L==R) f[e[i].fi]=f[e[i].se]=dp[i]=f[e[i].fi]+f[e[i].se]-dp[AB[L]];
			else f[e[i].fi]=f[e[i].se]=dp[i]=f[e[i].fi]+f[e[i].se];
		}
	}
	for(int i=1;i<=n;i++) printf("%d%c",f[i]-1," \n"[i==n]);
	return 0;
}