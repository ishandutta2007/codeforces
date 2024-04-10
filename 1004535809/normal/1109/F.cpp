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
const int MAXN=2000;
const int MAXM=2e5;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
int n,m,a[MAXN+5][MAXN+5];pii pos[MAXM+5];
int getid(int x,int y){return (x-1)*m+y;}
struct node{int ch[2],f,rev_lz;} s[MAXM+5];
int ident(int k){return (s[s[k].f].ch[0]==k)?0:((s[s[k].f].ch[1]==k)?1:-1);}
void connect(int k,int f,int op){s[k].f=f;if(~op) s[f].ch[op]=k;}
void rotate(int x){
	int y=s[x].f,z=s[y].f,dx=ident(x),dy=ident(y);
	connect(s[x].ch[dx^1],y,dx);connect(y,x,dx^1);connect(x,z,dy);
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
		else if(ident(k)==ident(s[k].f)) rotate(s[k].f),rotate(k);
		else rotate(k),rotate(k);
	}
}
void access(int k){
	int pre=0;
	for(;k;pre=k,k=s[k].f) splay(k),s[k].ch[1]=pre;
}
void makeroot(int k){access(k);splay(k);tag(k);}
int findroot(int k){
	access(k);splay(k);
	while(s[k].ch[0]) pushdown(k),k=s[k].ch[0];
	splay(k);return k;
}
bool link(int x,int y){
	makeroot(x);
	if(findroot(y)==x) return 0;
//	printf("link %d %d\n",x,y);
	s[x].f=y;return 1;
}
void split(int x,int y){makeroot(x);access(y);splay(y);}
void cut(int x,int y){
	makeroot(x);
	if(findroot(y)!=x) return;
	if(s[y].f!=x||s[y].ch[0]) return;
//	printf("cut %d %d\n",x,y);
	s[y].f=s[x].ch[1]=0;
}
bool chkcon(int x,int y){makeroot(x);return (findroot(y)==x);}
bool vis[MAXM+5];
int cnt[MAXM+5];
void calc_ini(){//calculate how many edges are there in the induces subgraph of 1~i
	for(int i=1;i<=n*m;i++){
		cnt[i]=cnt[i-1];int x=pos[i].fi,y=pos[i].se;
		for(int d=0;d<4;d++){
			int nx=x+dx[d],ny=y+dy[d];
			if(nx<1||nx>n||ny<1||ny>m) continue;
			if(vis[a[nx][ny]]) cnt[i]++;
		} vis[i]=1;
	}
}
struct dat{
	int mn,cnt;
	dat(int _mn=0,int _cnt=0):mn(_mn),cnt(_cnt){}
	dat operator +(const dat &rhs){
		dat res;res.mn=min(mn,rhs.mn);
		if(res.mn==mn) res.cnt+=cnt;
		if(res.mn==rhs.mn) res.cnt+=rhs.cnt;
		return res;
	}
};
namespace segtree{
	struct node{int l,r,lz;dat v;} s[MAXM*4+5];
	void pushup(int k){s[k].v=s[k<<1].v+s[k<<1|1].v;}
	void build(int k,int l,int r){
		s[k].l=l;s[k].r=r;if(l==r) return s[k].v=dat(l-::cnt[l],1),void();
		int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);pushup(k);
	}
	void tag(int k,int v){s[k].v.mn+=v;s[k].lz+=v;}
	void pushdown(int k){if(s[k].lz) tag(k<<1,s[k].lz),tag(k<<1|1,s[k].lz),s[k].lz=0;}
	void modify(int k,int l,int r,int v){
		if(l<=s[k].l&&s[k].r<=r) return tag(k,v),void();
		pushdown(k);int mid=s[k].l+s[k].r>>1;
		if(r<=mid) modify(k<<1,l,r,v);
		else if(l>mid) modify(k<<1|1,l,r,v);
		else modify(k<<1,l,mid,v),modify(k<<1|1,mid+1,r,v);
		pushup(k);
	}
	dat query(int k,int l,int r){
		if(l<=s[k].l&&s[k].r<=r) return s[k].v;
		pushdown(k);int mid=s[k].l+s[k].r>>1;
		if(r<=mid) return query(k<<1,l,r);
		else if(l>mid) return query(k<<1|1,l,r);
		else return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		scanf("%d",&a[i][j]);
		pos[a[i][j]]=mp(i,j);
	} calc_ini();memset(vis,0,sizeof(vis));
	segtree::build(1,1,n*m);ll res=0;
	for(int l=1,r=1;l<=n*m;l++){
		while(r<=n*m){
			bool flg=1;int x=pos[r].fi,y=pos[r].se;
			for(int d=0;d<4;d++){
				int nx=x+dx[d],ny=y+dy[d];
				if(nx<1||nx>n||ny<1||ny>m) continue;
				if(vis[a[nx][ny]]) flg&=link(getid(x,y),getid(nx,ny));
			} if(!flg){
				for(int d=0;d<4;d++){
					int nx=x+dx[d],ny=y+dy[d];
					if(nx<1||nx>n||ny<1||ny>m) continue;
					cut(getid(x,y),getid(nx,ny));
				} break;
			} vis[r]=1;r++;
		} //printf("%d %d\n",l,r);
		dat d=segtree::query(1,l,r-1);
		if(d.mn==1) res+=d.cnt;
		vis[l]=0;int x=pos[l].fi,y=pos[l].se;
		for(int d=0;d<4;d++){
			int nx=x+dx[d],ny=y+dy[d];
			if(nx<1||nx>n||ny<1||ny>m) continue;
			if(a[nx][ny]>l) segtree::modify(1,a[nx][ny],n*m,1);
			cut(getid(x,y),getid(nx,ny));
		} segtree::modify(1,l,n*m,-1);
	} printf("%lld\n",res);
	return 0;
}
/*
2 3
1 2 3
4 5 6
*/