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
const int MAXM=3e5;
int n,m;
struct edge{int u,v,w;} e[MAXM+5];
struct node{int ch[2],f,rev_lz,sz,sz_img;pii mx,val;} s[MAXN+MAXM+5];
void pushup(int k){
	s[k].mx=max(max(s[s[k].ch[0]].mx,s[s[k].ch[1]].mx),s[k].val);
	s[k].sz=s[s[k].ch[0]].sz+s[s[k].ch[1]].sz+(k<=n)+s[k].sz_img;
}
int ident(int k){return (s[s[k].f].ch[0]==k)?0:((s[s[k].f].ch[1]==k)?1:-1);}
void connect(int k,int f,int op){s[k].f=f;if(~op) s[f].ch[op]=k;}
void rotate(int x){
	int y=s[x].f,z=s[y].f,dx=ident(x),dy=ident(y);
	connect(s[x].ch[dx^1],y,dx);connect(y,x,dx^1);connect(x,z,dy);
	pushup(y);pushup(x);
}
void tag(int k){swap(s[k].ch[0],s[k].ch[1]);s[k].rev_lz^=1;}
void pushdown(int k){
	if(s[k].rev_lz){
		if(s[k].ch[0]) tag(s[k].ch[0]);
		if(s[k].ch[1]) tag(s[k].ch[1]);
		s[k].rev_lz=0;
	}
}
void pushall(int k){if(~ident(k)) pushall(s[k].f);pushdown(k);}
void splay(int k){
	pushall(k);
	while(~ident(k)){
		if(ident(s[k].f)==-1) rotate(k);
		else if(ident(s[k].f)==ident(k)) ident(s[k].f),rotate(k);
		else rotate(k),rotate(k);
	}
}
void access(int k){
	int pre=0;
	for(;k;pre=k,k=s[k].f){
		splay(k);s[k].sz_img+=s[s[k].ch[1]].sz-s[pre].sz;
		s[k].ch[1]=pre;pushup(k);
	}
}
void makeroot(int k){access(k);splay(k);tag(k);}
int findroot(int k){
	access(k);splay(k);
	while(s[k].ch[0]) pushdown(k),k=s[k].ch[0];
	splay(k);return k;
}
void split(int x,int y){makeroot(x);access(y);splay(y);}
int odd_cnt;
void link(int x,int y){
	makeroot(x);makeroot(y);s[x].f=y;
	s[y].sz_img+=s[x].sz;pushup(y);
}
void cut(int x,int y){split(x,y);s[y].ch[0]=s[x].f=0;pushup(y);}
pii query(int x,int y){split(x,y);return s[y].mx;}
set<pii> st;
void ins(int id){
	makeroot(e[id].u);s[id+n].mx=s[id+n].val=mp(e[id].w,id);
	if(findroot(e[id].v)==e[id].u){
//		printf("edge %d\n",id);
		pii delp=query(e[id].u,e[id].v);
		if(delp.fi<=e[id].w) return;int cid=delp.se;
		cut(e[cid].u,cid+n);cut(e[cid].v,cid+n);
		st.erase(mp(e[cid].w,cid));
		link(e[id].u,id+n);link(e[id].v,id+n);
	} else {
		odd_cnt-=(s[e[id].u].sz&1);makeroot(e[id].v);
		odd_cnt-=(s[e[id].v].sz&1);
		link(e[id].u,id+n);link(e[id].v,id+n);
		makeroot(e[id].u);odd_cnt+=(s[e[id].u].sz&1);
	} st.insert(mp(e[id].w,id));
}
void work(){
	if(odd_cnt) return;
	while(!st.empty()){
		pii p=*st.rbegin();st.erase(st.find(p));
		int id=p.se;cut(e[id].u,id+n);cut(e[id].v,id+n);
		makeroot(e[id].u);makeroot(e[id].v);
		if((s[e[id].u].sz&1)||(s[e[id].v].sz&1)){
			link(e[id].u,id+n);link(e[id].v,id+n);
			st.insert(p);return;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	if(n&1){
		for(int i=1;i<=m;i++) puts("-1");
		return 0;
	} odd_cnt=n;
	for(int i=1;i<=n;i++) s[i].sz=1;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);ins(i);work();
		printf("%d\n",(odd_cnt)?-1:(st.rbegin())->fi);
	}
	return 0;
}