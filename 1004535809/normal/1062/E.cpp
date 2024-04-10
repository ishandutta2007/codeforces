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
const int MAXN=1e5;
const int LOG_N=17;
int n,qu,dep[MAXN+5],dfn[MAXN+5],tim=0;
pii st[LOG_N+2][MAXN*2+5];
link_list<int,MAXN,MAXN> g;
void dfs(int x){
	st[0][dfn[x]=++tim]=mp(dep[x],x);
	for(int e=g.hd[x];e;e=g.nxt[e]){
		int y=g.val[e];dep[y]=dep[x]+1;
		dfs(y);st[0][dfn[x]=++tim]=mp(dep[x],x);
	}
}
pii query_st(int l,int r){
	int k=31-__builtin_clz(r-l+1);
	return min(st[k][l],st[k][r-(1<<k)+1]);
}
int getlca(int x,int y){
	if(!x) return y;if(!y) return x;
	x=dfn[x];y=dfn[y];if(x>y) swap(x,y);
	return query_st(x,y).se;
}
struct dat{
	int lc,a,la,b,lb;
	dat(int _lc=0,int _a=0,int _la=0,int _b=0,int _lb=0):
		lc(_lc),a(_a),la(_la),b(_b),lb(_lb){}
	dat operator +(const dat &rhs){
		vector<pair<int,pii> > p;
		if(a) p.pb(mp(dep[getlca(la,rhs.lc)],mp(a,getlca(la,rhs.lc))));
		if(b) p.pb(mp(dep[getlca(lb,rhs.lc)],mp(b,getlca(lb,rhs.lc))));
		if(rhs.a) p.pb(mp(dep[getlca(lc,rhs.la)],mp(rhs.a,getlca(lc,rhs.la))));
		if(rhs.b) p.pb(mp(dep[getlca(lc,rhs.lb)],mp(rhs.b,getlca(lc,rhs.lb))));
		sort(p.begin(),p.end());reverse(p.begin(),p.end());
		return dat(getlca(lc,rhs.lc),p[0].se.fi,p[0].se.se,p[1].se.fi,p[1].se.se);
	}
};
struct node{int l,r;dat d;} s[MAXN*4+5];
void pushup(int k){s[k].d=s[k<<1].d+s[k<<1|1].d;}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return s[k].d=dat(l,l,0,0,0),void();
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);pushup(k);
}
dat query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].d;
	int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
}
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=2,fa;i<=n;i++) scanf("%d",&fa),g.ins(fa,i);dfs(1);
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=n*2;j++)
		st[i][j]=min(st[i-1][j],st[i-1][j+(1<<i-1)]);
	build(1,1,n);while(qu--){
		int l,r;scanf("%d%d",&l,&r);dat res=query(1,l,r);
//		printf("%d %d %d %d %d\n",res.lc,res.a,res.la,res.b,res.lb);
		printf("%d %d\n",res.a,dep[res.la]);
	}
	return 0;
}