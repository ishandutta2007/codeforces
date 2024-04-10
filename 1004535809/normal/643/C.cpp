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
const int MAXN=2e5;
const int MAXK=50;
const ld INF=1e18;
int n,k,t[MAXN+5];ll s[MAXN+5];
ld s1[MAXN+5],s2[MAXN+5],dp[MAXN+5][MAXK+5];
ld calc(int l,int r){return s2[r]-s2[l-1]-s[l-1]*(s1[r]-s1[l-1]);}
ld getx(int x,int k){return s[x];}
ld gety(int x,int k){return s[x]*s1[x]-s2[x]+dp[x][k-1];}
ld slope(int x,int y,int k){return 1.0*(gety(y,k)-gety(x,k))/(getx(y,k)-getx(x,k));}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&t[i]),s[i]=s[i-1]+t[i];
	for(int i=1;i<=n;i++) s1[i]=s1[i-1]+(1.0/t[i]),s2[i]=s2[i-1]+(1.0*s[i]/t[i]);
	for(int i=0;i<=n;i++) for(int j=0;j<=k;j++) dp[i][j]=INF;
	dp[0][0]=0;
	for(int i=1;i<=k;i++){
		static int q[MAXN+5];int hd=1,tl=0;
		q[++tl]=0;
		for(int j=1;j<=n;j++){
			while(hd<tl&&slope(q[hd],q[hd+1],i)<s1[j]) ++hd;
			int fr=q[hd];
			dp[j][i]=dp[fr][i-1]+calc(fr+1,j);
			while(hd<tl&&slope(q[tl],j,i)<slope(q[tl-1],q[tl],i)) --tl;
			q[++tl]=j;
		}
	} printf("%.10Lf\n",dp[n][k]);
	return 0;
}