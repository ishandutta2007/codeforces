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
const int MAXN=2000;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n,k;ll dp[MAXN+5][2];
struct dat{int l,r,c;} a[MAXN+5];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].c);
	memset(dp,63,sizeof(dp));dp[n+1][0]=0;
	for(int i=n;i;i--) for(int _=0;_<2;_++){
		int cur=k;ll sum=0;
		for(int j=i+1;j<=n+1;j++){
			int lst=0;
			if(a[j-1].c<=cur){
				if(a[j-1].l+(j==i+1&&_)>a[j-1].r) sum=INF;
				else sum+=a[j-1].c,lst=a[j-1].l+(j==i+1&&_);
				cur-=a[j-1].c;
			} else {
				int lft=a[j-1].c-cur;
				int nd=(lft+k-1)/k;
				if(a[j-1].l+(j==i+1&&_)+nd>a[j-1].r) sum=INF;
				else sum+=a[j-1].c,lst=a[j-1].l+(j==i+1&&_)+nd;
				cur=(lft%k==0)?0:(k-lft%k);
			} //printf("lst %d %d %d %lld %d\n",i,j,lst,sum,cur);
			if(sum<INF) chkmin(dp[i][_],dp[j][(j!=n+1)&&(lst==a[j].l)]+sum+((j==n+1)?0:cur));
		}
//		printf("%d %d %lld\n",i,_,dp[i][_]);
	} printf("%lld\n",(dp[1][0]==INF)?-1:dp[1][0]);
	return 0;
}