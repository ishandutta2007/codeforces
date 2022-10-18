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
const int MAXN=200;
const int MAXV=404;
const int MAXE=5000;
int n1,n2,m,r,b,deg[MAXV+5];char s1[MAXN+5],s2[MAXN+5];
int S1,S2,T1,T2,hd[MAXV+5],to[MAXE+5],nxt[MAXE+5],cst[MAXE+5],cap[MAXE+5],ec=1;
void adde(int u,int v,int f,int c){
	if(f<0) puts("-1"),exit(0);
//	printf("%d %d %d %d\n",u,v,f,c);
	to[++ec]=v;cap[ec]=f;cst[ec]=c;nxt[ec]=hd[u];hd[u]=ec;
	to[++ec]=u;cap[ec]=0;cst[ec]=-c;nxt[ec]=hd[v];hd[v]=ec;
}
int sum_has,sum_cst;
void _adde(int u,int v,int l,int r,int c){
	adde(u,v,r-l,c);adde(S2,v,l,0);adde(u,T2,l,0);
	sum_has+=l;sum_cst+=1ll*l*c;
}
int dis[MAXV+5],lste[MAXV+5],flw[MAXV+5],pre[MAXV+5];
bool inq[MAXV+5];
bool getdis(int S,int T){
	memset(dis,63,sizeof(dis));memset(flw,0,sizeof(flw));
	dis[S]=0;flw[S]=INF;inq[S]=1;queue<int> q;q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();inq[x]=0;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e],z=cap[e],w=cst[e];
			if(z&&dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;flw[y]=min(flw[x],z);
				pre[y]=x;lste[y]=e;
				if(!inq[y]) inq[y]=1,q.push(y);
			}
		}
	} return dis[T]<INF;
}
pair<int,int> mcmf(int S,int T){
	int mxfl=0,mncst=0;
	while(getdis(S,T)){
		mncst+=1ll*flw[T]*dis[T];mxfl+=flw[T];
		for(int i=T;i^S;i=pre[i]){
			cap[lste[i]]-=flw[T];cap[lste[i]^1]+=flw[T];
		}
	} return mp(mxfl,mncst);
}
int main(){
	scanf("%d%d%d%d%d%s%s",&n1,&n2,&m,&r,&b,s1+1,s2+1);
	T2=(S2=(T1=(S1=n1+n2+1)+1)+1)+1;
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);v+=n1;
		deg[u]++;deg[v]++;adde(v,u,1,b);
		adde(S2,v,1,0);adde(u,T2,1,0);
		sum_cst-=b;sum_has++;adde(u,v,1,r);
	}
	for(int i=1;i<=n1;i++){
		if(s1[i]=='R') _adde(S1,i,deg[i]+1,deg[i]*2,0);
		if(s1[i]=='B') adde(S1,i,deg[i]-1,0);
		if(s1[i]=='U') adde(S1,i,deg[i]*2,0);
	}
	for(int i=1;i<=n2;i++){
		if(s2[i]=='R') _adde(i+n1,T1,deg[i+n1]+1,deg[i+n1]*2,0);
		if(s2[i]=='B') adde(i+n1,T1,deg[i+n1]-1,0);
		if(s2[i]=='U') adde(i+n1,T1,deg[i+n1]*2,0);
	} adde(T1,S1,INF,0);
	pair<int,int> pr=mcmf(S2,T2);
	if(pr.fi!=sum_has) return puts("-1"),0;
	int res=sum_cst+pr.se+m*b;
	printf("%d\n",res);
	for(int i=3,j=1;j<=m;i+=8,j++){
		if(cap[i]==1) putchar('B');
		else if(cap[i+6]==1) putchar('R');
		else putchar('U');
	}
	return 0;
}