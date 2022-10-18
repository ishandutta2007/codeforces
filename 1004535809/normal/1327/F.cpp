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
const int LOG_N=30;
const int MAXN=5e5;
const int MOD=998244353;
int n,m,k,mx[LOG_N+2][MAXN+5],d[LOG_N+2][MAXN+5];
int dp[MAXN+5],sum[MAXN+5];
int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1,l,r,x;i<=m;i++){
		scanf("%d%d%d",&l,&r,&x);
		for(int j=0;j<k;j++){
			if(x>>j&1) d[j][l]++,d[j][r+1]--;
			else chkmax(mx[j][r],l);
		}
	} int res=1;
	for(int i=0;i<k;i++){
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		dp[0]=sum[0]=1;int cnt=0,lim=0;
		for(int j=1;j<=n;j++){
			cnt+=d[i][j];
			if(cnt>0) dp[j]=0,sum[j]=sum[j-1];
			else{
				dp[j]=(sum[j-1]-((!lim)?0:sum[lim-1])+MOD)%MOD;
				sum[j]=(sum[j-1]+dp[j])%MOD;
			} chkmax(lim,mx[i][j]);
		} res=1ll*res*(sum[n]-((!lim)?0:sum[lim-1])+MOD)%MOD;
//		for(int j=1;j<=n;j++) printf("%d%c",dp[j]," \n"[j==n]);
	} printf("%d\n",res);
	return 0;
}