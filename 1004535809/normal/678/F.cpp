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
const int MAXN=3e5;
const int INF=0x3f3f3f3f;
const ll INFll=0x3f3f3f3f3f3f3f3fll;
int qu,q[MAXN+5];
struct line{
	int k,b;
	line(int _k=0,int _b=0):k(_k),b(_b){}
	ll get(int x){return 1ll*k*x+b;}
} l[MAXN+5];
double inter(line x,line y){return 1.0*(y.b-x.b)/(x.k-y.k);}
struct hull_line{
	vector<line> lns,stk;
	vector<double> itr;
	void build(){
		sort(lns.begin(),lns.end(),[&](line x,line y){return x.k<y.k;});
		for(int i=0,j=0;i<lns.size();i=j){
			int mx=-INF;
			while(j<lns.size()&&lns[i].k==lns[j].k) chkmax(mx,lns[j++].b);
			line ins=line(lns[i].k,mx);
			while(stk.size()>1&&inter(stk.back(),ins)<itr.back()) stk.ppb(),itr.ppb();
			stk.pb(ins);
			if(stk.size()>1) itr.pb(inter(stk[(int)(stk.size())-1],stk[(int)(stk.size())-2]));
		}
//		printf("Hull:\n");
//		for(int i=0;i<stk.size();i++) printf("%d %d\n",stk[i].k,stk[i].b);
	}
	ll calc(int x){
		if(stk.empty()) return -INFll;
		int l=0,r=(int)(itr.size())-1,p=itr.size();
		while(l<=r){
			int mid=l+r>>1;
			if(x<=itr[mid]) p=mid,r=mid-1;
			else l=mid+1;
		} return stk[p].get(x);
	}
};
struct node{int l,r;hull_line val;} s[MAXN*4+5];
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return;int mid=l+r>>1;
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
}
void modify(int k,int l,int r,line v){
	if(l<=s[k].l&&s[k].r<=r) return s[k].val.lns.pb(v),void();
	int mid=s[k].l+s[k].r>>1;
	if(r<=mid) modify(k<<1,l,r,v);
	else if(l>mid) modify(k<<1|1,l,r,v);
	else modify(k<<1,l,mid,v),modify(k<<1|1,mid+1,r,v);
}
void build_hull(int k){
	s[k].val.build();if(s[k].l==s[k].r) return;
	build_hull(k<<1);build_hull(k<<1|1);
}
ll query(int k,int p,int x){
	if(s[k].l==s[k].r) return s[k].val.calc(x);
	int mid=s[k].l+s[k].r>>1;
	return max((p<=mid)?query(k<<1,p,x):query(k<<1|1,p,x),s[k].val.calc(x));
}
int main(){
	scanf("%d",&qu);set<int> opts;
	memset(q,63,sizeof(q));build(1,1,qu);
	for(int i=1;i<=qu;i++){
		int opt;scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&l[i].k,&l[i].b);
			opts.insert(i);
		} else if(opt==2){
			int k;scanf("%d",&k);
			modify(1,k,i-1,l[k]);
			opts.erase(opts.find(k));
		} else scanf("%d",&q[i]);
	} for(int id:opts) modify(1,id,qu,l[id]);
	build_hull(1);
	for(int i=1;i<=qu;i++) if(q[i]!=INF){
		ll res=query(1,i,q[i]);
		if(res==-INFll) puts("EMPTY SET");
		else printf("%lld\n",res);
	}
	return 0;
}