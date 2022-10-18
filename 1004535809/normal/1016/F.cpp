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
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
const int MOD=998244353;
const int INF=0x3f3f3f3f;
const ll INFll=0x3f3f3f3f3f3f3f3fll;
const double EPS=1e-6;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=(c=='-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=-x;
	}
	template<typename T> void recursive_print(T x){
		if(!x) return;
		recursive_print(x/10);putc(x%10+'0');
	}
	template<typename T> void print(T x){
		if(!x) putc('0');if(x<0) putc('-'),x=-x;
		recursive_print(x);
	}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
template<typename Tv,int limN,int limM> struct link_list{
	int hd[limN+5],nxt[limM+5],item_n=0;Tv val[limM+5];
	void clear(){memset(hd,0,sizeof(hd));item_n=0;}//be aware of the TC of memset
	void ins(int x,Tv y){val[++item_n]=y;nxt[item_n]=hd[x];hd[x]=item_n;}
};
const int MAXN=3e5;
int n,qu,fa[MAXN+5],siz[MAXN+5];
ll dis[MAXN+5],mxd[MAXN+5];
link_list<pii,MAXN,MAXN*2> g;
void dfs(int x,int f){
	fa[x]=f;siz[x]=1;mxd[x]=dis[x];
	for(int e=g.hd[x];e;e=g.nxt[e]){
		int y=g.val[e].fi,z=g.val[e].se;if(y==f) continue;
		dis[y]=dis[x]+z;dfs(y,x);chkmax(mxd[x],mxd[y]);siz[x]+=siz[y];
	}
}
int pt[MAXN+5],ptcnt=0,on[MAXN+5],sz[MAXN+5];ll f[MAXN+5];
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=1,u,v,w;i<n;i++) scanf("%d%d%d",&u,&v,&w),g.ins(u,mp(v,w)),g.ins(v,mp(u,w));
	dfs(1,0);for(int i=n;i;i=fa[i]) pt[++ptcnt]=i,on[i]=1;
	reverse(pt+1,pt+ptcnt+1);
	for(int i=1;i<=ptcnt;i++){
		int x=pt[i];sz[i]=1;
		for(int e=g.hd[x];e;e=g.nxt[e]){
			int y=g.val[e].fi,z=g.val[e].se;
			if(!on[y]) sz[i]+=siz[y],chkmax(f[i],mxd[y]-dis[x]);
		}
		if(sz[i]>=3){
			for(int j=1;j<=qu;j++) printf("%lld\n",dis[n]);
			return 0;
		}
	}
	ll mx=-INFll,res=0;
	for(int i=2;i<=ptcnt;i++){
		chkmax(res,dis[n]-dis[pt[i]]+f[i]+mx);
		if((sz[i]-1)|(sz[i-1]-1)) chkmax(res,dis[n]-dis[pt[i]]+dis[pt[i-1]]+f[i]+f[i-1]);
		chkmax(mx,dis[pt[i-1]]+f[i-1]);
	}
	while(qu--){int x;scanf("%d",&x);printf("%lld\n",min(res+x,dis[n]));}
	return 0;
}