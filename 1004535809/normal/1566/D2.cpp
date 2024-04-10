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
const int MAXN=300;
int n,m,ps[MAXN+5][MAXN+5];pii a[MAXN*MAXN+5];
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i].fi),a[i].se=i;
	sort(a+1,a+n*m+1);memset(ps,0,sizeof(ps));
	for(int l=1,r;l<=n*m;l=r+1){
		r=l;while(a[r].fi==a[l].fi) ++r;--r;
//		printf("%d %d\n",l,r);
		if((l-1)/m==(r-1)/m){
			int lps=(l-1)%m+1,rps=(r-1)%m+1;
			for(int i=lps;i<=rps;i++) ps[(l-1)/m+1][i]=a[r-(i-lps)].se;
		} else {
			int ndl=m-(l-1)%m,ndr=(r-1)%m+1;
			for(int i=1;i<=ndr;i++) ps[(r-1)/m+1][(r-1)%m+2-i]=a[r-ndr+i].se;
			for(int i=1;i<=ndl;i++) ps[(l-1)/m+1][(l-1)%m+i]=a[l+ndl-i].se;
		}
	} int res=0;
//	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d%c",ps[i][j]," \n"[j==m]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=1;k<j;k++) res+=(ps[i][j]>ps[i][k]);
	printf("%d\n",res);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}