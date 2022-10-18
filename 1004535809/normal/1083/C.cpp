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
const int MAXN=2e5;
const int LOG_N=19;
int n,qu,p[MAXN+5],pos[MAXN+5];
int hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dep[MAXN+5],dfn[MAXN+5],tim=0;
pii st[MAXN*2+5][LOG_N+2];
void dfs(int x){
	st[dfn[x]=++tim][0]=mp(dep[x],x);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];dep[y]=dep[x]+1;dfs(y);
		st[dfn[x]=++tim][0]=mp(dep[x],x);
	}
}
pii query_st(int l,int r){
	int k=31-__builtin_clz(r-l+1);
	return min(st[l][k],st[r-(1<<k)+1][k]);
}
int getlca(int u,int v){
	u=dfn[u];v=dfn[v];if(u>v) swap(u,v);
	return query_st(u,v).se;
}
bool onchain(int u,int v,int w){
	int l=getlca(u,v);
	if(getlca(w,l)==l){
		if(getlca(u,w)==w) return 1;
		if(getlca(v,w)==w) return 1;
	} return 0;
}
struct chain{
	int u,v;
	chain(int _u=-1,int _v=-1):u(_u),v(_v){}
	chain operator +(const chain &rhs){
		if(!u) return rhs;
		if(!rhs.u) return *this;
		if(!~u) return chain(-1,-1);
		if(!~rhs.u) return chain(-1,-1);
		#define make(u,v,x,y) if(onchain(u,v,x)&&onchain(u,v,y))\
			return chain(u,v);
		make(u,v,rhs.u,rhs.v);make(u,rhs.u,v,rhs.v);make(u,rhs.v,v,rhs.u);
		make(v,rhs.u,u,rhs.v);make(v,rhs.v,u,rhs.u);make(rhs.u,rhs.v,u,v);
		return chain(-1,-1);
	}
};
struct node{int l,r;chain v;} s[MAXN*4+5];
void pushup(int k){s[k].v=s[k<<1].v+s[k<<1|1].v;}
void build(int k,int l,int r){
	s[k].l=l;s[k].r=r;if(l==r) return s[k].v=chain(pos[l],pos[l]),void();
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);pushup(k);
}
void modify(int k,int p,int x){
	if(s[k].l==s[k].r) return s[k].v=chain(x,x),void();
	int mid=s[k].l+s[k].r>>1;
	(p<=mid)?modify(k<<1,p,x):modify(k<<1|1,p,x);
	pushup(k);
}
chain cur;
int walk(int k){
	if(s[k].l==s[k].r) return s[k].l;
	chain nxt=cur+s[k<<1].v;
	if(!~nxt.u) return walk(k<<1);
	else return cur=nxt,walk(k<<1|1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]),pos[p[i]]=i;
	for(int i=2,f;i<=n;i++) scanf("%d",&f),adde(f,i);dfs(1);
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=n*2;j++)
		st[j][i]=min(st[j][i-1],st[j+(1<<i-1)][i-1]);
	build(1,0,n-1);scanf("%d",&qu);
	while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==1){
			int u,v;scanf("%d%d",&u,&v);swap(p[u],p[v]);
			modify(1,p[u],u);modify(1,p[v],v);
		} else {
			cur=chain(0,0);
			if(~s[1].v.u) printf("%d\n",n);
			else printf("%d\n",walk(1));
		}
	}
	return 0;
}