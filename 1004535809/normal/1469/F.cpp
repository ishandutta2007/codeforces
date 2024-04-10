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
const int MAXV=5e5;
const int INF=0x3f3f3f3f;
int n,k,l[MAXN+5];
struct node{int l,r,lz;ll sum;} s[MAXV*4+5];
void pushup(int k){s[k].sum=s[k<<1].sum+s[k<<1|1].sum;}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;int mid=l+r>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void tag(int k,int v){s[k].lz+=v;s[k].sum+=1ll*(s[k].r-s[k].l+1)*v;}
void pushdown(int k){if(s[k].lz) tag(k<<1,s[k].lz),tag(k<<1|1,s[k].lz),s[k].lz=0;}
void modify(int k,int l,int r,int v){
	if(l<=s[k].l&&s[k].r<=r) return tag(k,v);
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,v);
	else if(l>mid) modify(k<<1|1,l,r,v);
	else modify(k<<1,l,mid,v),modify(k<<1|1,mid+1,r,v);
	pushup(k);
}
int walk(int k,int v){
	if(s[k].l==s[k].r) return s[k].l;pushdown(k);
	if(s[k<<1].sum<v) return walk(k<<1|1,v-s[k<<1].sum);
	else return walk(k<<1,v);
}
int main(){
	scanf("%d%d",&n,&k);int res=INF;
	for(int i=1;i<=n;i++) scanf("%d",&l[i]);
	sort(l+1,l+n+1);reverse(l+1,l+n+1);
	build(1,0,MAXV);modify(1,0,0,1);
	for(int i=1;i<=n;i++){
		int pos=walk(1,1);modify(1,pos,pos,-1);
//		printf("%d\n",pos);
		modify(1,pos+2,pos+(l[i]+1>>1),1);
		modify(1,pos+2,pos+1+(l[i]>>1),1);
		if(s[1].sum>=k) chkmin(res,walk(1,k));
	} printf("%d\n",(res==INF)?-1:res);
	return 0;
}