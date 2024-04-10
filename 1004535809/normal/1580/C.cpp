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
const int MAXN=2e5;
const int B=444;
int n,qu;
int x[MAXN+5],y[MAXN+5],tim[MAXN+5],d[MAXN+5];
void add_range(int l,int r,int v){
	if(l>qu) return;chkmin(r,qu);
	d[l]+=v;d[r+1]-=v;
}
int t[B+5][MAXN+5];
void add_log(int x,int period,int v){if(x>qu) return;t[period][x]+=v;}
void add(int id,int st,int v){
//	printf("add %d %d %d\n",id,st,v);
	if(st>qu) return;
	if(x[id]+y[id]>B){
		for(int i=st;i<=qu;i+=x[id]+y[id]) add_range(i,i+x[id]-1,v);
	} else {
		add_log(st,x[id]+y[id],v);add_log(st+x[id],x[id]+y[id],-v);
	}
}
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=qu;i++){
		int opt,k;scanf("%d%d",&opt,&k);
		if(opt==1){
			tim[k]=i;add(k,i,1);
			d[i]--;
		} else {
			int stage=(i-tim[k])%(x[k]+y[k]);
			if(stage<x[k]) add_range(i,i-stage+x[k]-1,-1),add(k,i-stage+x[k]+y[k],-1);
			else add(k,i-stage+x[k]+y[k],-1);
			d[i]++;
		}
	}
	for(int i=1;i<=B;i++) for(int j=1;j<=i;j++){
		for(int k=j+i;k<=qu;k+=i) t[i][k]+=t[i][k-i];
		for(int k=j;k<=qu;k+=i) d[k]+=t[i][k];
	}
	for(int i=1;i<=qu;i++) d[i]+=d[i-1];
	for(int i=1;i<=qu;i++) printf("%d\n",-d[i]);
	return 0;
}