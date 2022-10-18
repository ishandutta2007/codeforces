#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=1e5;
const int LOG_N=17;
int n,qu;
namespace graph{
	int to[MAXN*2+5],nxt[MAXN*2+5],hd[MAXN+5],ec=0;
	void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
	int fa[MAXN+5][LOG_N+2],dep[MAXN+5],dfn[MAXN+5],tim=0;
	void dfs(int x,int f){
		fa[x][0]=f;dfn[x]=++tim;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==f) continue;
			dep[y]=dep[x]+1;dfs(y,x);
		}
	}
	void prework(){
		dfs(1,0);
		for(int i=1;i<=LOG_N;i++) for(int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
	}
	int getlca(int x,int y){
		if(dep[x]<dep[y]) swap(x,y);
		for(int i=LOG_N;~i;i--) if(dep[x]-(1<<i)>=dep[y]) x=fa[x][i];
		if(x==y) return x;
		for(int i=LOG_N;~i;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
		return fa[x][0];
	}
}
using graph::getlca;
using graph::dep;
namespace virt{
	bool cmp(int x,int y){return graph::dfn[x]<graph::dfn[y];}
	int pt[MAXN+5],len=0;bool vis[MAXN+5];
	int hd[MAXN+5],to[MAXN*2],nxt[MAXN*2],ec=0;
	void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
	int stk[MAXN+5],tp=0;
	void insert(int x){
		if(!tp){stk[++tp]=x;return;}
		int lc=getlca(x,stk[tp]);
		while(tp>=2&&dep[lc]<dep[stk[tp-1]]) adde(stk[tp-1],stk[tp]),tp--;
		if(tp&&dep[lc]<dep[stk[tp]]) adde(lc,stk[tp--]);
		if(!tp||stk[tp]!=lc) stk[++tp]=lc;
		stk[++tp]=x;
	}
	void fin(){while(tp>=2) adde(stk[tp-1],stk[tp]),tp--;stk[tp--]=0;}
	void build(){
		sort(pt+1,pt+len+1,cmp);if(!vis[1]) insert(1);
		for(int i=1;i<=len;i++) insert(pt[i]);fin();
//		puts("-1");
	}
	int dp[MAXN+5];bool hav[MAXN+5];
	void dfs(int x){
		int need=0;
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];dfs(y);dp[x]+=dp[y];need+=hav[y];
		}
		if(vis[x]) hav[x]=1,dp[x]+=need;
		else if(need>1) dp[x]++;
		else if(need==1) hav[x]=1;
	}
	void clear(int x){
		dp[x]=hav[x]=0;
		for(int e=hd[x];e;e=nxt[e]) clear(to[e]),ec--;
		hd[x]=0;
	}
	void query(){
		scanf("%d",&len);
		for(int i=1;i<=len;i++) scanf("%d",&pt[i]),vis[pt[i]]=1;
		for(int i=1;i<=len;i++) if(vis[graph::fa[pt[i]][0]]){
			puts("-1");for(int j=1;j<=len;j++) vis[pt[j]]=0;
			return;
		} build();dfs(1);printf("%d\n",dp[1]);clear(1);
		for(int i=1;i<=len;i++) vis[pt[i]]=0;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		graph::adde(u,v);graph::adde(v,u);
	} graph::prework();
	scanf("%d",&qu);while(qu--) virt::query();
	return 0;
}