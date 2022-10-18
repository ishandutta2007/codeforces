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
const int MAXN=3e5;
int n,p[MAXN+5];
struct dat{
	int mn,cnt;
	dat(int _mn=0,int _cnt=0):mn(_mn),cnt(_cnt){}
	dat operator +(const dat &rhs){
		dat res;res.mn=min(mn,rhs.mn);
		if(res.mn==mn) res.cnt+=cnt;
		if(res.mn==rhs.mn) res.cnt+=rhs.cnt;
		return res;
	}
};
struct node{int l,r,lz;dat v;} s[MAXN*4+5];
void pushup(int k){s[k].v=s[k<<1].v+s[k<<1|1].v;}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return s[k].v=dat(0,1),void();
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);pushup(k);
}
void tag(int k,int v){s[k].lz+=v;s[k].v.mn+=v;}
void pushdown(int k){if(s[k].lz) tag(k<<1,s[k].lz),tag(k<<1|1,s[k].lz),s[k].lz=0;}
void modify(int k,int l,int r,int v){
	if(l>r) return;
	if(l<=s[k].l&&s[k].r<=r) return tag(k,v),void();
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,v);
	else if(l>mid) modify(k<<1|1,l,r,v);
	else modify(k<<1,l,mid,v),modify(k<<1|1,mid+1,r,v);
	pushup(k);
}
dat query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].v;
	pushdown(k);int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
}
int main(){
	scanf("%d",&n);ll res=0;
	for(int i=1,x,y;i<=n;i++) scanf("%d%d",&x,&y),p[x]=y;
	stack<int> stk_mn,stk_mx;stk_mn.push(0);stk_mx.push(0);
	build(1,1,n);
	for(int i=1;i<=n;i++){
		modify(1,1,i-1,-1);
		while(stk_mn.size()>1&&p[stk_mn.top()]>p[i]){
			int pos=stk_mn.top();stk_mn.pop();
			modify(1,stk_mn.top()+1,pos,p[pos]-p[i]);
		} stk_mn.push(i);
		while(stk_mx.size()>1&&p[stk_mx.top()]<p[i]){
			int pos=stk_mx.top();stk_mx.pop();
			modify(1,stk_mx.top()+1,pos,p[i]-p[pos]);
		} stk_mx.push(i);
		res+=query(1,1,i).cnt;
	} printf("%lld\n",res);
	return 0;
}