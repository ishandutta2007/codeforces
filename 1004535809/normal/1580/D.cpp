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
const int MOD=1e9+7;
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
const int MAXN=4000;
int n,k,a[MAXN+5],ncnt,val[MAXN+5];
link_list<pii,MAXN,MAXN> g;
int build(int l,int r){
	if(l>r) return 0;int id=++ncnt;pii mn=mp(INT_MAX,n+1);
	for(int i=l;i<=r;i++) chkmin(mn,mp(a[i],i));
	val[id]=mn.fi;int ls=build(l,mn.se-1),rs=build(mn.se+1,r);
	if(ls) g.ins(id,mp(ls,val[ls]-val[id]))/*,printf("%d %d %d\n",id,ls,val[ls]-val[id])*/;
	if(rs) g.ins(id,mp(rs,val[rs]-val[id]))/*,printf("%d %d %d\n",id,rs,val[rs]-val[id])*/;
	return id;
}
ll dp[MAXN+5][MAXN+5];int siz[MAXN+5];
void dfs(int x){
	dp[x][0]=dp[x][1]=0;siz[x]=1;
	for(int e=g.hd[x];e;e=g.nxt[e]){
		int y=g.val[e].fi,z=g.val[e].se;dfs(y);
//		printf("edge %d %d %d\n",x,y,z);
		static ll tmp[MAXN+5];memset(tmp,192,sizeof(tmp));
		for(int i=0;i<=siz[x];i++) for(int j=0;j<=siz[y];j++){
			chkmax(tmp[i+j],dp[x][i]+dp[y][j]+((!j)?0:(1ll*z*j*(k-j))));
//			printf("%d %d %d %lld\n",y,i,j,1ll*z*(k-j));
		}
		for(int i=0;i<=siz[x]+siz[y];i++) dp[x][i]=tmp[i];
		siz[x]+=siz[y];
	}
//	for(int i=0;i<=siz[x];i++) printf("%d %d %lld\n",x,i,dp[x][i]);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,n);memset(dp,192,sizeof(dp));dfs(1);
	printf("%lld\n",dp[1][k]);
	return 0;
}//