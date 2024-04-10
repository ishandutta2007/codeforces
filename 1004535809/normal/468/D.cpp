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
const int MAXN=1e5;
const int INF=0x3f3f3f3f;
int n,hd[MAXN+5],to[MAXN*2+5],val[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v,int w){to[++ec]=v;val[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
int siz[MAXN+5],cent=0,cent_mx=INF;
void findcent(int x,int f){
	siz[x]=1;int mx=0;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		findcent(y,x);siz[x]+=siz[y];
		chkmax(mx,siz[y]);
	} chkmax(mx,n-siz[x]);
	if(mx<cent_mx) cent_mx=mx,cent=x;
}
ll dis[MAXN+5];int bel[MAXN+5],cnt[MAXN+5];
set<int> st[MAXN+5],mn;
set<pii> dset;
void dfs(int x,int f,int rt){
	st[rt].insert(x);bel[x]=rt;cnt[rt]+=2;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=val[e];if(y==f) continue;
		dis[y]=dis[x]+z;dfs(y,x,rt);
	}
}
void link(int x,int y){
	mn.erase(mn.find(y));
	if(bel[x]) dset.erase(dset.find(mp(cnt[bel[x]],bel[x]))),cnt[bel[x]]--,dset.insert(mp(cnt[bel[x]],bel[x]));
	if(bel[y]){
		dset.erase(dset.find(mp(cnt[bel[y]],bel[y])));cnt[bel[y]]--;dset.insert(mp(cnt[bel[y]],bel[y]));
		st[bel[y]].erase(st[bel[y]].find(y));if(!st[bel[y]].empty()) mn.insert(*st[bel[y]].begin());
	}
}
int calc(int x){
	int ret;
	if((*dset.rbegin()).fi==n-x+1&&(*dset.rbegin()).se!=bel[x]) ret=*st[(*dset.rbegin()).se].begin();
	else ret=((bel[*mn.begin()]!=bel[x])||(x==cent))?(*mn.begin()):(*++mn.begin());
	return link(x,ret),ret;
}
int main(){
	scanf("%d",&n);if(n==1) return puts("0\n1"),0;
	for(int i=1,u,v,w;i<n;i++) scanf("%d%d%d",&u,&v,&w),adde(u,v,w),adde(v,u,w);
	findcent(1,0);ll sum=0;
	for(int e=hd[cent];e;e=nxt[e]){
		int y=to[e],z=val[e];dis[y]=z;dfs(y,cent,y);
		mn.insert(*st[y].begin());dset.insert(mp(2*st[y].size(),y));
	} mn.insert(cent);
	for(int i=1;i<=n;i++) sum+=dis[i];printf("%lld\n",sum<<1);
	for(int i=1;i<=n;i++) printf("%d%c",calc(i)," \n"[i==n]);
	return 0;
}