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
#define y1 y111111111
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
const int MAXN=1e6+2;
const int MOD=1e9+7;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,k,fac[MAXN+5],ifac[MAXN+5],pre[MAXN+5],suf[MAXN+5];
int pr[MAXN/6+5],prcnt=0,idk[MAXN+5],vis[MAXN+5];
void sieve(int n){
	idk[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]) idk[i]=qpow(i,k),pr[++prcnt]=i;
		for(int j=1;j<=prcnt&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;idk[pr[j]*i]=1ll*idk[pr[j]]*idk[i]%MOD;
			if(i%pr[j]==0) break;
		}
	}
}
void init_fac(int n){
	for(int i=(fac[0]=ifac[0]=ifac[1]=1)+1;i<=n;i++) ifac[i]=1ll*ifac[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD,ifac[i]=1ll*ifac[i-1]*ifac[i]%MOD;
}
int sum[MAXN+5];
int main(){
	scanf("%d%d",&n,&k);sieve(k+2);init_fac(MAXN);int res=0;
	for(int i=1;i<=k+2;i++) sum[i]=(sum[i-1]+idk[i])%MOD;
	pre[0]=1;for(int i=1;i<=k+2;i++) pre[i]=1ll*pre[i-1]*(n-i+MOD)%MOD;
	suf[k+3]=1;for(int i=k+2;i;i--) suf[i]=1ll*suf[i+1]*(n-i+MOD)%MOD;
	for(int i=1;i<=k+2;i++){
		int mul=1ll*pre[i-1]*suf[i+1]%MOD*ifac[i-1]%MOD*ifac[k+2-i]%MOD;
		if((k+2-i)&1) mul=MOD-mul;res=(res+1ll*mul*sum[i])%MOD;
	} printf("%d\n",res);
	return 0;
}