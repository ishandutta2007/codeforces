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
const int MAXN=2e5;
int n,qu,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0,deg[MAXN+5];
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int t[MAXN*2+5],col_cnt=0;
void add(int x,int v){for(int i=x;i<=MAXN*2;i+=(i&(-i))) t[i]+=v;}
int query(int x){int ret=0;for(int i=x;i;i&=(i-1)) ret+=t[i];return ret;}
struct node{int ch[2],f,siz,rev_lz,col,col_lz;} s[MAXN+5];
void pushup(int k){s[k].siz=s[s[k].ch[0]].siz+s[s[k].ch[1]].siz+1;}
int ident(int k){return ((s[s[k].f].ch[0]==k)?0:((s[s[k].f].ch[1]==k)?1:-1));}
void connect(int k,int f,int op){s[k].f=f;if(~op) s[f].ch[op]=k;}
void rotate(int x){
	int y=s[x].f,z=s[y].f,dx=ident(x),dy=ident(y);
	connect(s[x].ch[dx^1],y,dx);connect(y,x,dx^1);connect(x,z,dy);
	pushup(y);pushup(x);
}
void tag_rev(int k){swap(s[k].ch[0],s[k].ch[1]);s[k].rev_lz^=1;}
void tag_col(int k,int v){s[k].col_lz=v;s[k].col=v;}
void pushdown(int k){
	if(s[k].rev_lz){
		if(s[k].ch[0]) tag_rev(s[k].ch[0]);
		if(s[k].ch[1]) tag_rev(s[k].ch[1]);
		s[k].rev_lz=0;
	} if(s[k].col_lz){
		if(s[k].ch[0]) tag_col(s[k].ch[0],s[k].col_lz);
		if(s[k].ch[1]) tag_col(s[k].ch[1],s[k].col_lz);
		s[k].col_lz=0;
	}
}
void pushall(int k){if(~ident(k)) pushall(s[k].f);pushdown(k);}
void splay(int k){
	pushall(k);
	while(~ident(k)){
		if(ident(s[k].f)==-1) rotate(k);
		else if(ident(s[k].f)==ident(k)) rotate(s[k].f),rotate(k);
		else rotate(k),rotate(k);
	}
}
void access(int k){
	int pre=0;
	for(;k;pre=k,k=s[k].f){
		splay(k);
		add(s[k].col,-s[k].siz+s[s[k].ch[1]].siz);
		add(col_cnt,s[k].siz-s[s[k].ch[1]].siz);
		s[k].ch[1]=pre;pushup(k);
	}
}
void makeroot(int k){
	col_cnt++;access(k);splay(k);
	tag_rev(k);tag_col(k,col_cnt);
}
int ask(int k){splay(k);return query(s[k].col)-s[s[k].ch[0]].siz;}
void dfs0(int x,int f){
	s[x].f=f;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dfs0(y,x);
	}
}
void calc(){
	priority_queue<int,vector<int>,greater<int> > q;
	for(int i=1;i<=n;i++) if(deg[i]==1) q.push(i);
	while(!q.empty()){
		int x=q.top();q.pop();col_cnt++;
		add(col_cnt,1);s[x].col=col_cnt;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];
			if((--deg[y])==1) q.push(y);
		}
	}
}
int main(){
	scanf("%d%d",&n,&qu);for(int i=1;i<=n;i++) s[i].siz=1;
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),deg[u]++,deg[v]++,adde(u,v),adde(v,u);
	dfs0(n,0);calc();
	while(qu--){
		static char opt[13];scanf("%s",opt+1);
		if(opt[1]=='u'){int x;scanf("%d",&x);makeroot(x);}
		else if(opt[1]=='w'){int x;scanf("%d",&x);printf("%d\n",ask(x));}
		else{
			int u,v;scanf("%d%d",&u,&v);
			printf("%d\n",(ask(u)<ask(v))?u:v);
		}
//		for(int i=1;i<=n;i++) printf("%d%c",ask(i)," \n"[i==n]);
	}
	return 0;
}