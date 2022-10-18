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
const int MAXN=8e5;
int n,qu,ncnt;
struct node{int ch[2],f,vis,has,has_sub,has_ed,val,sum,rev_lz,xor_lz;} s[MAXN+5];
void pushup(int k){
	s[k].sum=s[k].val^s[s[k].ch[0]].sum^s[s[k].ch[1]].sum;
	s[k].has_ed=s[s[k].ch[0]].has_ed|s[s[k].ch[1]].has_ed|(k>n);
	if(k>n) s[k].has_sub=s[k].has;else s[k].has_sub=0;
	s[k].has_sub|=s[s[k].ch[0]].has_sub;
	s[k].has_sub|=s[s[k].ch[1]].has_sub;
}
void tag_rev(int k){swap(s[k].ch[0],s[k].ch[1]);s[k].rev_lz^=1;}
void tag_xor(int k,int v){s[k].val^=v;s[k].sum^=v;s[k].xor_lz^=v;}
void tag_vis(int k){s[k].vis=s[k].has=1;if(s[k].has_ed) s[k].has_sub=1;}
void pushdown(int k){
	if(s[k].rev_lz){
		if(s[k].ch[0]) tag_rev(s[k].ch[0]);
		if(s[k].ch[1]) tag_rev(s[k].ch[1]);
		s[k].rev_lz=0;
	} if(s[k].xor_lz){
		if(s[k].ch[0]) tag_xor(s[k].ch[0],s[k].xor_lz);
		if(s[k].ch[1]) tag_xor(s[k].ch[1],s[k].xor_lz);
		s[k].xor_lz=0;
	} if(s[k].vis){
		if(s[k].ch[0]) tag_vis(s[k].ch[0]);
		if(s[k].ch[1]) tag_vis(s[k].ch[1]);
		s[k].vis=0;
	}
}
int ident(int k){return ((s[s[k].f].ch[0]==k)?0:((s[s[k].f].ch[1]==k)?1:-1));}
void connect(int k,int f,int op){s[k].f=f;if(~op) s[f].ch[op]=k;}
void rotate(int x){
	int y=s[x].f,z=s[y].f,dx=ident(x),dy=ident(y);
	connect(s[x].ch[dx^1],y,dx);connect(y,x,dx^1);connect(x,z,dy);
	pushup(y);pushup(x);
}
void pushall(int k){if(~ident(k)) pushall(s[k].f);pushdown(k);}
void splay(int k){
	pushall(k);
	while(~ident(k)){
		if(ident(s[k].f)==-1) rotate(k);
		else if(ident(k)==ident(s[k].f)) rotate(s[k].f),rotate(k);
		else rotate(k),rotate(k);
	}
}
void access(int k){
	int pre=0;
	for(;k;pre=k,k=s[k].f) splay(k),s[k].ch[1]=pre,pushup(k);
}
void makeroot(int k){access(k);splay(k);tag_rev(k);}
int findroot(int k){
	access(k);splay(k);
	while(s[k].ch[0]) pushdown(k),k=s[k].ch[0];
	splay(k);return k;
}
void link(int x,int y){makeroot(x);s[x].f=y;}
int main(){
	scanf("%d%d",&n,&qu);ncnt=n;
	while(qu--){
		int u,v,x;scanf("%d%d%d",&u,&v,&x);
		makeroot(u);//printf("%d\n",findroot(v));
		if(findroot(v)==u){
			access(v);
			if(s[v].has_sub||(x==s[v].sum)) puts("NO");
			else tag_vis(v),puts("YES");
		} else {
			++ncnt;s[ncnt].sum=s[ncnt].val=x;
			link(u,ncnt);link(v,ncnt);s[ncnt].has_ed=1;
			puts("YES");
		}
	}
	return 0;
}