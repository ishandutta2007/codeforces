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
const int MAXN=5e5;
int n;
struct graph{
	int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
	void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
} g1,g2;
int fa[2][MAXN+5];
void dfs0(graph &g,int *f,int x,int fa){
	f[x]=fa;
	for(int e=g.hd[x];e;e=g.nxt[e])
		if(g.to[e]!=fa) dfs0(g,f,g.to[e],x);
}
int f[MAXN+5];
int find(int x){return (!f[x])?x:f[x]=find(f[x]);}
vector<tuple<int,int,int,int> > res;
void dfs(int x){
	for(int e=g1.hd[x];e;e=g1.nxt[e]){
		int y=g1.to[e];if(y==fa[0][x]) continue;dfs(y);
		if(find(x)!=find(y)){
			res.pb(mt(y,x,find(y),fa[1][find(y)]));
			f[find(y)]=fa[1][find(y)];
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),g1.adde(u,v),g1.adde(v,u);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),g2.adde(u,v),g2.adde(v,u);
	dfs0(g1,fa[0],1,0);dfs0(g2,fa[1],1,0);
	for(int i=2;i<=n;i++) if(fa[0][i]==fa[1][i]||fa[0][fa[1][i]]==i) f[i]=fa[1][i];
	dfs(1);printf("%d\n",res.size());
	for(int i=0;i<res.size();i++) printf("%d %d %d %d\n",get<0>(res[i]),get<1>(res[i]),get<2>(res[i]),get<3>(res[i]));
	return 0;
}