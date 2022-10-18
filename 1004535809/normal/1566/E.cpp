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
const int MAXN=2e5;
int n,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0,deg[MAXN+5],dep[MAXN+5];
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int fa[MAXN+5],is[MAXN+5],cntl[MAXN+5],cntnl[MAXN+5];
void clear(){for(int i=1;i<=n;i++) hd[i]=deg[i]=0;ec=0;}
void dfs(int x,int f){
	fa[x]=f;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dep[y]=dep[x]+1;dfs(y,x);
	}
}
void solve(){
	scanf("%d",&n);clear();
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u),deg[u]++,deg[v]++;
	for(int i=2;i<=n;i++) is[i]=(deg[i]==1);
	dfs(1,0);int sm=1;set<pii> st;
	for(int i=1;i<=n;i++){
		cntl[i]=cntnl[i]=0;
		for(int e=hd[i];e;e=nxt[e]){
			int y=to[e];if(y==fa[i]) continue;
			if(is[y]) cntl[i]++;else cntnl[i]++;
		} if(!is[i]&&i!=1) st.insert(mp(cntnl[i],i));
	} while(!st.empty()){
		pii p=*st.begin();st.erase(st.find(p));
		sm+=cntl[p.se];sm--;int pt=fa[p.se];
//		printf("%d %d\n",p.se,cntl[p.se]);
		if(pt^1){
			st.erase(st.find(mp(cntnl[pt],pt)));
			deg[pt]--;cntnl[pt]--;
			if(deg[pt]==1){
				if(fa[pt]!=1){
					st.erase(st.find(mp(cntnl[fa[pt]],fa[pt])));
					cntnl[fa[pt]]--,cntl[fa[pt]]++;
					st.insert(mp(cntnl[fa[pt]],fa[pt]));
				} else cntnl[fa[pt]]--,cntl[fa[pt]]++;
			} else st.insert(mp(cntnl[pt],pt));
		}
	} if(cntl[1]>0) sm+=cntl[1]-1;
	printf("%d\n",sm);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}