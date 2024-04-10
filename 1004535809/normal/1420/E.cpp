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
const int MAXN=80;
int n,pre[MAXN+5][2],a[MAXN+5],res[MAXN*MAXN+5];
int dp[MAXN+5][MAXN+5][MAXN*MAXN+5];
int main(){
	scanf("%d",&n);int cnt[2]={0};
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) pre[++cnt[a[i]]][a[i]]=cnt[a[i]^1];
//	for(int i=1;i<=cnt[0];i++) printf("%d%c",pre[i][0]," \n"[i==cnt[0]]);
//	for(int i=1;i<=cnt[1];i++) printf("%d%c",pre[i][1]," \n"[i==cnt[1]]);
	memset(dp,192,sizeof(dp));dp[0][0][0]=0;
	for(int i=1;i<=cnt[1];i++) for(int j=0;j<=cnt[0];j++)
		for(int k=0;k<=n*(n-1)/2;k++){
			int pre_inv=k-max(pre[i][1]-j,0);
			for(int l=0;l<=j;l++){
				if(pre_inv>=0) chkmax(dp[i][j][k],dp[i-1][j-l][pre_inv]+(j-l)*l);
				else break;pre_inv-=max(pre[j-l][0]-(i-1),0);
			}
		}
	for(int i=0;i<=n*(n-1)/2;i++) for(int j=0;j<=cnt[0];j++)
		chkmax(res[i],dp[cnt[1]][j][i]+(cnt[0]-j)*j);
	for(int i=1;i<=n*(n-1)/2;i++) chkmax(res[i],res[i-1]);
	for(int i=0;i<=n*(n-1)/2;i++) printf("%d%c",res[i]," \n"[i==n*(n-1)/2]);
	return 0;
}