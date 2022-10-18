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
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
template<typename Tv,int limN,int limM> struct link_list{
	int hd[limN+5],nxt[limM+5],item_n=0;Tv val[limM+5];
	void clear(){memset(hd,0,sizeof(hd));item_n=0;}//be aware of the TC of memset
	void ins(int x,Tv y){val[++item_n]=y;nxt[item_n]=hd[x];hd[x]=item_n;}
};
const int MAXN=300;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,deg[MAXN+5],d[MAXN+5];ll a[MAXN+5];
link_list<int,MAXN,MAXN*MAXN> g,rev;
int b[MAXN+5][MAXN+5],tmpb[MAXN+5][MAXN+5];
int v[MAXN+5][MAXN+5],sv[MAXN+5][MAXN+5];
int c[MAXN+5][MAXN*2+5];
struct fenwick_tree{
	int t[MAXN+5];
	void clear(){memset(t,0,sizeof(t));}
	void add(int x,int v){x++;for(int i=x;i<=n+1;i+=(i&(-i))) t[i]=(t[i]+v)%MOD;}
	int query(int x){x++;int ret=0;for(int i=x;i;i&=(i-1)) ret=(ret+t[i])%MOD;return ret;}
} tr[MAXN+5];
int pw[MAXN+5][1005],pw1000[MAXN+5][1005];
int ipw[MAXN+5][1005],ipw1000[MAXN+5][1005];
void init(){
	for(int i=0;i<=n;i++){
		int iv=qpow(i,MOD-2);
		for(int j=(pw[i][0]=1);j<=1000;j++) pw[i][j]=1ll*pw[i][j-1]*i%MOD;
		for(int j=(pw1000[i][0]=1);j<=1000;j++) pw1000[i][j]=1ll*pw1000[i][j-1]*pw[i][1000]%MOD;
		for(int j=(ipw[i][0]=1);j<=1000;j++) ipw[i][j]=1ll*ipw[i][j-1]*iv%MOD;
		for(int j=(ipw1000[i][0]=1);j<=1000;j++) ipw1000[i][j]=1ll*ipw1000[i][j-1]*ipw[i][1000]%MOD;
	}
}
int getpow(int x,int e){return 1ll*pw[x][e%1000]*pw1000[x][e/1000]%MOD;}
int getipow(int x,int e){return 1ll*ipw[x][e%1000]*ipw1000[x][e/1000]%MOD;}
void calc_d(){
	static int tmpd[MAXN+5]={0};
	for(int i=1;i<=n;i++) tmpd[i]=deg[i];
	queue<int> q;memset(d,63,sizeof(d));
	for(int i=1;i<=n;i++) if(a[i]>0) d[i]=0;
	for(int i=1;i<=n;i++) if(!tmpd[i]) q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int e=rev.hd[x];e;e=rev.nxt[e]){
			int y=rev.val[e];chkmin(d[y],d[x]+1);
			if(!--tmpd[y]) q.push(y);
		}
	}
	for(int i=1;i<=n;i++) tr[i].clear();
	for(int i=1;i<=n;i++) if(d[i]!=INF)
		for(int j=1;j<=n;j++) tr[j].add(d[i],1ll*getipow(j,d[i])*(a[i]%MOD+MOD)%MOD*c[j][i]%MOD);
}
void calc_v(int x){
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) tmpb[i][j]=b[i][j];
	for(int i=1;i<=n;i++) tmpb[i][i]=(tmpb[i][i]-x+MOD)%MOD;
	v[x][x]=1;
	for(int i=x-1;i;i--){
		for(int j=i+1;j<=x;j++)
			v[i][x]=(v[i][x]-1ll*v[j][x]*tmpb[i][j]%MOD+MOD)%MOD;
		v[i][x]=1ll*v[i][x]*qpow(tmpb[i][i],MOD-2)%MOD;
	}
}
void calc_c(){
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) c[i][j]=v[i][j];
	for(int i=1;i<=n;i++) c[i][i+n]=1;
	for(int i=n;i;i--) for(int j=i+1;j<=n;j++){
		for(int k=n+1;k<=2*n;k++) c[i][k]=(c[i][k]-1ll*c[i][j]*c[j][k]%MOD+MOD)%MOD;
		c[i][j]=0;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		swap(c[i][j],c[i][j+n]);
}
int main(){
//	freopen("dag.in","r",stdin);
//	freopen("dag.out","w",stdout);
	scanf("%d",&n);init();
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		int len;scanf("%d",&len);deg[i]=len;
		while(len--){
			int y;scanf("%d",&y);
			g.ins(i,y);rev.ins(y,i);
			b[i][y]=y;
		}
	}
	for(int i=1;i<=n;i++) b[i][i]=i;
	for(int i=1;i<=n;i++) calc_v(i);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		sv[i][j]=(sv[i-1][j]+v[i][j])%MOD;
	calc_c();calc_d();
	int qu;scanf("%d",&qu);
	while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int l,r,k,res=0;scanf("%d%d%d",&k,&l,&r);
			for(int j=1;j<=n;j++){
				int sum=(sv[r][j]-sv[l-1][j]+MOD)%MOD;
				res=(res+1ll*getpow(j,k)*sum%MOD*tr[j].query(min(k,n)))%MOD;
			}
			for(int i=l;i<=r;i++) if(d[i]>k) res=(0ll+res+a[i]%MOD+MOD)%MOD;
			printf("%d\n",res);
		} else {
			int x,v;scanf("%d%d",&x,&v);
			if(a[x]<=0&&a[x]+v>0) a[x]+=v,calc_d();
			else{
				for(int j=1;j<=n;j++)
					tr[j].add(d[x],MOD-1ll*getipow(j,d[x])*(a[x]%MOD+MOD)%MOD*c[j][x]%MOD);
				a[x]+=v;
				for(int j=1;j<=n;j++)
					tr[j].add(d[x],1ll*getipow(j,d[x])*(a[x]%MOD+MOD)%MOD*c[j][x]%MOD);
			}
		}
	}
	return 0;
}