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
const int MAXN=2e5;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int m,n;pii a[MAXN+5],b[MAXN+5];
int va[MAXN+5],vb[MAXN+5],res[MAXN+5];
ll d[MAXN+5];
void add(int l,int r,int v){d[l]+=v;d[r+1]-=v;}
void add1(int l,int r,int x,int v){
//	for(int i=l;i<=r;i++) d[(i-x+n)%n]+=v;
	if(l>r) return;
	if(l<x&&x<=r) add((l-x+n)%n,n-1,v),add(0,r-x,v);
	else add((l-x+n)%n,(r-x+n)%n,v);
}
void add2(int l,int r,int x,int v){
//	for(int i=l;i<=r;i++) d[(x-i+n)%n]+=v;
	if(l>r) return;
	if(l<=x&&x<r) add((x-r+n)%n,n-1,v),add(0,x-l,v);
	else add((x-r+n)%n,(x-l+n)%n,v);
}
int getge_a(ll x){return upper_bound(va+1,va+n+1,x)-va;}
int getgeq_b(ll x){return lower_bound(vb+1,vb+n+1,x)-vb;}
int main(){
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].fi),a[i].se=i;
	for(int i=1;i<=n;i++) scanf("%d",&b[i].fi),b[i].se=i;
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	for(int i=1;i<=n;i++) va[i]=a[i].fi<<1,vb[i]=b[i].fi<<1;
	for(int i=1;i<=n;i++){
		int p1=getgeq_b(((ll)a[i].fi<<1)-m);
		int p2=getgeq_b((ll)a[i].fi<<1);
		int p3=getgeq_b(((ll)a[i].fi<<1)+m);
//		printf("%d %d %d\n",p1,p2,p3);
		add1(1,p1-1,i,m-a[i].fi);
		add1(p1,p2-1,i,a[i].fi);
		add1(p2,p3-1,i,-a[i].fi);
		add1(p3,n,i,a[i].fi);
	}
	for(int i=1;i<=n;i++){
		int p1=getge_a(((ll)b[i].fi<<1)-m);
		int p2=getge_a((ll)b[i].fi<<1);
		int p3=getge_a(((ll)b[i].fi<<1)+m);
//		printf("%d %d %d\n",p1,p2,p3);
		add2(1,p1-1,i,m-b[i].fi);
		add2(p1,p2-1,i,b[i].fi);
		add2(p2,p3-1,i,-b[i].fi);
		add2(p3,n,i,b[i].fi);
	}
	for(int i=0;i<n;i++) d[i]=((!i)?0:d[i-1])+d[i];
//	for(int i=0;i<n;i++) printf("%lld\n",d[i]);
	ll mn=INF;int p=-1;
	for(int i=0;i<n;i++) if(mn>d[i]) mn=d[i],p=i;
	for(int i=1;i<=n;i++) res[a[i].se]=b[(i+p+n-1)%n+1].se;
	printf("%lld\n",mn);
	for(int i=1;i<=n;i++) printf("%d%c",res[i]," \n"[i==n]);
	return 0;
}
/*
100 3
1 5 5
10 4 6
*/