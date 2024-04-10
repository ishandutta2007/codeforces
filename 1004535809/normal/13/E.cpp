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
int n,qu,a[MAXN+5];
struct node{int ch[2],f,siz;} s[MAXN+5];
void pushup(int k){s[k].siz=s[s[k].ch[0]].siz+s[s[k].ch[1]].siz+1;}
int ident(int k){return ((s[s[k].f].ch[0]==k)?0:((s[s[k].f].ch[1]==k)?1:-1));}
void connect(int k,int f,int op){s[k].f=f;if(~op) s[f].ch[op]=k;}
void rotate(int x){
	int y=s[x].f,z=s[y].f,dx=ident(x),dy=ident(y);
	connect(s[x].ch[dx^1],y,dx);connect(y,x,dx^1);connect(x,z,dy);
	pushup(y);pushup(x);
}
void splay(int k){
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
void link(int x,int y){access(x);splay(x);s[x].f=y;}
void cut(int x){access(x);splay(x);int son=s[x].ch[0];s[son].f=s[x].ch[0]=0;}
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n+1;i++) s[i].siz=1;
	for(int i=1;i<=n;i++) link(i,min(i+a[i],n+1));
	while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==0){
			int x,y;scanf("%d%d",&x,&y);
			cut(x);a[x]=y;link(x,min(x+a[x],n+1));
		} else {
			int x;scanf("%d",&x);access(x);splay(n+1);
			int cur=s[n+1].ch[1];
			while(s[cur].ch[0]) cur=s[cur].ch[0];
			printf("%d %d\n",cur,s[s[n+1].ch[1]].siz);
		}
	}
	return 0;
}//