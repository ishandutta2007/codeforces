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
using namespace fastio;
const int MAXN=1e6;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n,a[MAXN+5],b[MAXN+5];ll dp[MAXN+5][2];
void solve(){
	read(n);ll sum=0,res=INF;
	for(int i=1;i<=n;i++) read(a[i]),sum+=a[i];
	for(int i=1;i<=n;i++) read(b[i]);
	for(int _=0;_<2;_++){
		for(int i=0;i<=n;i++) dp[i][0]=dp[i][1]=INF;
		dp[0][_]=0;
		for(int i=1;i<=n;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++)
			chkmin(dp[i][j],dp[i-1][k]+j*b[i]+(!(j&k))*a[i]);
		chkmin(res,dp[n][_]);
	} //printf("%lld\n",res);
	printf("%s\n",(res==sum)?"YES":"NO");
}
int main(){int qu;read(qu);while(qu--) solve();return 0;}