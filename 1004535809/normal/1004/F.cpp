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
int n,qu,x,a[MAXN+5];
struct dat{
	vector<pii> suf,pre;ll cnt;
	dat(){cnt=0;}
	dat(int v){suf.pb(mp(v,1));pre.pb(mp(v,1));cnt=(v<=x);}
	void print(){
		printf("%lld\n",cnt);
		for(pii p:pre) printf("{%d,%d} ",p.fi,p.se);printf("\n");
		for(pii p:suf) printf("{%d,%d} ",p.fi,p.se);printf("\n");
	}
	dat operator +(const dat &rhs){
		dat res;res.cnt=cnt+rhs.cnt;
		for(int i=(int)(suf.size())-1,j=0,sum=0;~i;i--){
			while(j<rhs.pre.size()&&(suf[i].fi|rhs.pre[j].fi)<=x) sum+=rhs.pre[j].se,j++;
			res.cnt+=1ll*suf[i].se*sum;
		}
		for(int i=0;i<pre.size();i++) res.pre.pb(pre[i]);
		int cur=res.pre.back().fi;
		for(int i=0;i<rhs.pre.size();i++){
			if((cur|rhs.pre[i].fi)==cur) res.pre[res.pre.size()-1].se+=rhs.pre[i].se;
			else res.pre.pb(mp(rhs.pre[i].fi|cur,rhs.pre[i].se)),cur|=rhs.pre[i].fi;
		}
		for(int i=0;i<rhs.suf.size();i++) res.suf.pb(rhs.suf[i]);
		cur=res.suf.back().fi;
		for(int i=0;i<suf.size();i++){
			if((cur|suf[i].fi)==cur) res.suf[res.suf.size()-1].se+=suf[i].se;
			else res.suf.pb(mp(suf[i].fi|cur,suf[i].se)),cur|=suf[i].fi;
		} return res;
	}
};
struct node{int l,r;dat v;} s[MAXN*4+5];
void pushup(int k){s[k].v=s[k<<1].v+s[k<<1|1].v;}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return s[k].v=dat(a[l]),void();
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);pushup(k);
//	printf("node [%d,%d]\n",l,r);s[k].v.print();
}
void modify(int k,int p,int v){
	if(s[k].l==s[k].r) return s[k].v=dat(v),void();int mid=s[k].l+s[k].r>>1;
	(p<=mid)?modify(k<<1,p,v):modify(k<<1|1,p,v);pushup(k);
}
dat query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].v;
	int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
}
int main(){
	scanf("%d%d%d",&n,&qu,&x);--x;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build(1,1,n);while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int p,x;scanf("%d%d",&p,&x);
			modify(1,p,x);
		} else {
			int l,r;scanf("%d%d",&l,&r);
			printf("%lld\n",1ll*(r-l+1)*(r-l+2)/2-query(1,l,r).cnt);
		}
	}
	return 0;
}
/*
5 1 7
6 0 3 4 2
2 1 5
*/