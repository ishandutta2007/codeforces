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
const int MAXN=2e5;
const int LOG_N=18;
int n,qu,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int fa[MAXN+5][LOG_N+2],dfn[MAXN+5],tim=0,dep[MAXN+5];
void dfs(int x,int f){
	dfn[x]=++tim;fa[x][0]=f;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dep[y]=dep[x]+1;dfs(y,x);
	}
}
int getlca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=LOG_N;~i;i--) if(dep[x]-(1<<i)>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=LOG_N;~i;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
namespace virt{
	struct node{
		int tim,dis,id,x;
		node(){tim=dis=id=x=0;}
		node(int _tim,int _dis,int _id,int _x){tim=_tim;dis=_dis;id=_id;x=_x;}
		friend bool operator <(node lhs,node rhs){
			if(lhs.tim!=rhs.tim) return lhs.tim<rhs.tim;
			return lhs.id<rhs.id;
		}
		friend bool operator >(node lhs,node rhs){return rhs<lhs;}
	};
	int K,M,V[MAXN+5],S[MAXN+5],U[MAXN+5];
	vector<pii> g[MAXN+5];
	void adde(int u,int v){/*printf("adde %d %d\n",u,v);*/g[u].pb(mp(v,dep[v]-dep[u]));g[v].pb(mp(u,dep[v]-dep[u]));}
	int pt[MAXN*2+5],pn=0;
	int stk[MAXN+5],tp=0;
	void insert(int x){
		if(!tp){stk[++tp]=x;return;}
		int lc=getlca(x,stk[tp]);
		while(tp>=2&&dep[stk[tp-1]]>dep[lc]) adde(stk[tp-1],stk[tp]),tp--;
		if(tp&&dep[lc]<dep[stk[tp]]) adde(lc,stk[tp--]);
		if(!tp||stk[tp]!=lc) stk[++tp]=lc;stk[++tp]=x;
	}
	void fin(){
		while(tp>=2) adde(stk[tp-1],stk[tp]),tp--;stk[tp--]=0;
	}
	void build(){
		sort(pt+1,pt+pn+1,[](int x,int y){return dfn[x]<dfn[y];});
		pn=unique(pt+1,pt+pn+1)-pt-1;if(pt[1]!=1) insert(1);
		for(int i=1;i<=pn;i++) insert(pt[i]);fin();
	}
	int col[MAXN+5];node dist[MAXN+5];
	void clear(int x,int f){
//		printf("clear %d %d\n",x,f);
		col[x]=0;dist[x]=node(1e9,0,0,0);
		for(int i=0;i<g[x].size();i++) if(g[x][i].fi!=f) clear(g[x][i].fi,x);
		g[x].clear();
	}
	void work(){
		scanf("%d%d",&K,&M);
		for(int i=1;i<=K;i++) scanf("%d%d",&V[i],&S[i]),pt[++pn]=V[i];
		for(int i=1;i<=M;i++) scanf("%d",&U[i]),pt[++pn]=U[i];
		build();priority_queue<node,vector<node>,greater<node> > q;
		for(int i=1;i<=K;i++) q.push(node(0,0,i,V[i])),dist[V[i]]=node(0,0,i,V[i]);
		while(!q.empty()){
			node p=q.top();q.pop();
			int x=p.x,id=p.id,tim=p.tim,dis=p.dis;
			if(dist[p.x]<p) continue;
			if(col[x]) continue;col[x]=id;
//			printf("%d %d %d %d\n",x,id,tim,dis);
			for(int i=0;i<g[x].size();i++){
				int y=g[x][i].fi,z=g[x][i].se;node t;
				if(z<=dis) t=node(tim,dis-z,id,y);
				else{
					if((z-dis)%S[id]==0) t=node(tim+(z-dis)/S[id],0,id,y);
					else t=node(tim+(z-dis)/S[id]+1,S[id]-(z-dis)%S[id],id,y);
				}
				if(t<dist[y]) dist[y]=t,q.push(t);
			}
		}
		for(int i=1;i<=M;i++) printf("%d%c",col[U[i]],(i==M)?'\n':' ');
		clear(1,0);pn=0;
	}
}
int main(){
//	freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		::adde(u,v);::adde(v,u);
	} dfs(1,0);
	for(int i=1;i<=n;i++) virt::dist[i]=virt::node(1e9,0,0,0);
	for(int i=1;i<=LOG_N;i++) for(int j=1;j<=n;j++)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	scanf("%d",&qu);while(qu--) virt::work();
	return 0;
}