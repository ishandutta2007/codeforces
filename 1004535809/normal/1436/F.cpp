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
const int MAXN=1e5;
const int MOD=998244353;
const int INV2=499122177;
const int PHI=MOD-1;
int qpow(int x,ll e){
	e=e%PHI;if(e<0) e+=PHI;int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,cnt[MAXN+5],mu[MAXN+5],pr[MAXN/5+5],prcnt=0;
bool vis[MAXN+5];
void sieve(int n){
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]) mu[i]=-1,pr[++prcnt]=i;
		for(int j=1;j<=prcnt&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;if(i%pr[j]==0) break;
			mu[i*pr[j]]=-mu[i];
		}
	}
}
int main(){
	scanf("%d",&n);sieve(MAXN);
	for(int i=1,x,y;i<=n;i++) scanf("%d%d",&x,&y),cnt[x]+=y;
	int res0=0,res1=0;
	for(int i=1;i<=MAXN;i++){
		int sum=0,c0=0,c1=0,ss=0,sqr_ss=0,sum_dif=0;ll tot=0;
		for(int j=i;j<=MAXN;j+=i){
			tot+=cnt[j];ss=(ss+1ll*cnt[j]*j)%MOD;
			sqr_ss=(sqr_ss+1ll*j*j%MOD*cnt[j])%MOD;
		}
		int pw1=qpow(2,tot-1),pw2=qpow(2,tot-2),pw3=qpow(2,tot-3);
		for(int j=i;j<=MAXN;j+=i) if(cnt[j]){
			c0=(c0+1ll*j*j%MOD*cnt[j]%MOD*pw1)%MOD;
			c0=(c0+1ll*j*sum%MOD*cnt[j]%MOD*pw2*2)%MOD;
			c0=(c0+1ll*j*j%MOD*cnt[j]%MOD*(cnt[j]-1)%MOD*pw2)%MOD;
			sum_dif=(sum_dif+1ll*j*sum%MOD*cnt[j]%MOD*2)%MOD;
			sum_dif=(sum_dif+1ll*j*j%MOD*cnt[j]%MOD*(cnt[j]-1))%MOD;
			sum=(sum+1ll*j*cnt[j])%MOD;
		}
		for(int j=i;j<=MAXN;j+=i) if(cnt[j]){
			c1=(c1+1ll*j*j%MOD*cnt[j]%MOD*pw1)%MOD;
			c1=(c1+2ll*j*(ss-j+MOD)%MOD*cnt[j]%MOD*pw2)%MOD;
			c1=(c1+1ll*cnt[j]*(sqr_ss-1ll*j*j%MOD+MOD)%MOD*pw2)%MOD;
			int rst=(sum_dif-2ll*j*(ss-j+MOD)%MOD+MOD)%MOD;
			c1=(c1+1ll*cnt[j]*rst%MOD*pw3)%MOD;
		}
		res0=(res0+1ll*(mu[i]+MOD)*c0)%MOD;
		res1=(res1+1ll*(mu[i]+MOD)*c1)%MOD;
	} eprintf("%d\n",res0);
	printf("%d\n",(res1-res0+MOD)%MOD);
	return 0;
}