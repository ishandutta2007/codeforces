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
#define y1 y11111111111
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
const int MAXN=1500;
int n,c,a[MAXN+5][MAXN+5],cnt[MAXN+5],vis[MAXN*MAXN+5];
struct dat{
	short int x,y;
	dat(short int _x=0,short int _y=0):x(_x),y(_y){}
	int col(){return a[x][y];}
};
int getdis(int x1,int y1,int x2,int y2){return max(x1-x2,y1-y2);}
dat L[MAXN+5][MAXN+5][12],U[MAXN+5][MAXN+5][12],LU[MAXN+5][MAXN+5][12];
int sL[MAXN+5][MAXN+5],sU[MAXN+5][MAXN+5],sLU[MAXN+5][MAXN+5];
int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		L[i][j][++sL[i][j]]=dat(i,j);
		for(int k=1;k<=sL[i][j-1];k++){
			if(L[i][j-1][k].col()==a[i][j]) continue;
			if(sL[i][j]<=c) L[i][j][++sL[i][j]]=L[i][j-1][k];
		}
		U[i][j][++sU[i][j]]=dat(i,j);
		for(int k=1;k<=sU[i-1][j];k++){
			if(U[i-1][j][k].col()==a[i][j]) continue;
			if(sU[i][j]<=c) U[i][j][++sU[i][j]]=U[i-1][j][k];
		}
		for(int p1=1,p2=1,p3=1;(p1<=sL[i][j]||p2<=sU[i-1][j]||p3<=sLU[i-1][j-1])&&sLU[i][j]<=c;){
			int mn1=INF,mn2=INF,mn3=INF;
			while(p1<=sL[i][j]&&vis[L[i][j][p1].col()]) ++p1;
			while(p2<=sU[i-1][j]&&vis[U[i-1][j][p2].col()]) ++p2;
			while(p3<=sLU[i-1][j-1]&&vis[LU[i-1][j-1][p3].col()]) ++p3;
			if(p1<=sL[i][j]) mn1=getdis(i,j,L[i][j][p1].x,L[i][j][p1].y);
			if(p2<=sU[i-1][j]) mn2=getdis(i,j,U[i-1][j][p2].x,U[i-1][j][p2].y);
			if(p3<=sLU[i-1][j-1]) mn3=getdis(i,j,LU[i-1][j-1][p3].x,LU[i-1][j-1][p3].y);
			int mn=min(mn1,min(mn2,mn3));
			if(mn==INF) break;
			if(mn==mn1) LU[i][j][++sLU[i][j]]=L[i][j][p1],vis[L[i][j][p1++].col()]=1;
			else if(mn==mn2) LU[i][j][++sLU[i][j]]=U[i-1][j][p2],vis[U[i-1][j][p2++].col()]=1;
			else LU[i][j][++sLU[i][j]]=LU[i-1][j-1][p3],vis[LU[i-1][j-1][p3++].col()]=1;
		}
		for(int k=1;k<=sLU[i][j];k++) vis[LU[i][j][k].col()]=0;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		int d=(sLU[i][j]==c+1)?getdis(i,j,LU[i][j][c+1].x,LU[i][j][c+1].y):INF;
		chkmin(d,min(i,j));
//		printf("%d %d %d\n",i,j,d);
		cnt[d]++;
	}
	for(int i=n;i;i--) cnt[i]+=cnt[i+1];
	for(int i=1;i<=n;i++) printf("%d\n",cnt[i]);
	return 0;
}