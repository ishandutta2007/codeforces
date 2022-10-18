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
const int MOD=998244353;
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
const int DLT=MAXN+3;
int n,a[MAXN+5],cnt[MAXN+5],fst[DLT<<1],cnt_cnt[MAXN+5],res=0;
int main(){
	scanf("%d",&n);int G=0,mxcnt=0,lim=(int)sqrt(n),mx=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
	for(int i=1;i<=n;i++) chkmax(mx,cnt[i]);
	for(int i=1;i<=n;i++) if(cnt[i]==mx) mxcnt++,G=i;
	if(mxcnt>=2) return printf("%d\n",n),0;
//	printf("%d\n",G);
	for(int i=1;i<=n;i++) if(cnt[i]>lim&&i!=G){
		memset(fst,-1,sizeof(fst));fst[DLT]=0;
		for(int j=1,s=0;j<=n;j++){
			if(a[j]==G) s++;if(a[j]==i) s--;
			if(~fst[s+DLT]) chkmax(res,j-fst[s+DLT]);
			else fst[s+DLT]=j;
		}
	} //printf("%d\n",res);
	for(int i=1;i<=lim+3;i++){
		memset(cnt,0,sizeof(cnt));int mx=0;
		memset(cnt_cnt,0,sizeof(cnt_cnt));
		for(int l=1,r=1;l<=n;l++){
			while(r<=n&&max(mx,cnt[a[r]]+1)<=i){
				cnt_cnt[cnt[a[r]]]--;cnt[a[r]]++;cnt_cnt[cnt[a[r]]]++;
				chkmax(mx,cnt[a[r]]);++r;
			} //printf("%d %d %d\n",i,l,r);
			if(cnt_cnt[mx]>=2) chkmax(res,r-l);
			cnt_cnt[cnt[a[l]]]--;cnt[a[l]]--;cnt_cnt[cnt[a[l]]]++;
			if(!cnt_cnt[mx]) mx--;
		}
	} printf("%d\n",res);
	return 0;
}