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
const int MAXN=3e5;
const int LOG_N=19;
int n,m,qu,k;
struct graph{
	int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=1;
	graph(){memset(hd,0,sizeof(hd));memset(to,0,sizeof(to));memset(nxt,0,sizeof(nxt));ec=1;}
	void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
} g0,t,im;
namespace ecc{
	int dfn[MAXN+5],low[MAXN+5],tim=0;stack<int> stk;
	int from[MAXN+5];bitset<MAXN*2+5> bri;
	void tarjan(int x,int f){
		dfn[x]=low[x]=++tim;stk.push(x);
		for(int e=g0.hd[x];e;e=g0.nxt[e]){
			int y=g0.to[e];
			if(!dfn[y]){
				tarjan(y,x);low[x]=min(low[x],low[y]);
				if(low[y]>dfn[x]) bri[e]=bri[e^1]=1;
			} else if(y!=f) low[x]=min(low[x],dfn[y]);
		}
	}
	void dfs(int x){
		if(from[x]) return;from[x]=k;
		for(int e=g0.hd[x];e;e=g0.nxt[e]){
			int y=g0.to[e];if(!bri[e]) dfs(y);
		}
	}
	void work(){
		for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i,0);
		for(int i=1;i<=n;i++) if(!from[i]) k++,dfs(i);
//		for(int i=1;i<=n;i++) printf("%d\n",from[i]);
		for(int x=1;x<=n;x++) for(int e=g0.hd[x];e;e=g0.nxt[e]){
			int y=g0.to[e];if(from[x]!=from[y]) t.adde(from[x],from[y]);
		}
	}
}
int fa[MAXN+5][LOG_N+2],dfn[MAXN+5],tim=0,dep[MAXN+5];
void dfs(int x,int f){
	fa[x][0]=f;dfn[x]=++tim;
	for(int e=t.hd[x];e;e=t.nxt[e]){
		int y=t.to[e];if(y==f) continue;
//		printf("%d %d\n",x,y);
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
ll R=0;
int rotate(int element){
	element=(element+R)%n;
	if(element==0) element=n;
	return element;
}
namespace virt{
	bool cmp(int x,int y){return dfn[x]<dfn[y];}
	int vn,en,pt[MAXN*3+5],pn,comp=0;
	int eu[MAXN+5],ev[MAXN+5],ex[MAXN+5];
	int stk[MAXN+5],tp=0;
	bool used[MAXN+5];vector<int> vs;
	void adde(int u,int v){im.adde(u,v);im.adde(v,u);}
	void addnode(int x){if(!used[x]) used[x]=1,vs.pb(x);}
	void insert(int x){
		addnode(x);
		if(!tp){stk[++tp]=x;return;}
		int lc=getlca(stk[tp],x);
//		printf("ins %d %d\n",x,lc);
		if(!lc){while(tp>=2) adde(stk[tp],stk[tp-1]),tp--;stk[tp--]=0;stk[++tp]=x;return;}
		addnode(lc);
		while(tp>=2&&dep[stk[tp-1]]>dep[lc]) adde(stk[tp],stk[tp-1]),tp--;
		if(tp&&dep[stk[tp]]>dep[lc]) adde(stk[tp],lc),tp--;
		if(!tp||lc!=stk[tp]) stk[++tp]=lc;stk[++tp]=x;
	}
	void fin(){while(tp>=2) im.adde(stk[tp-1],stk[tp]),im.adde(stk[tp],stk[tp-1]),tp--;stk[tp--]=0;}
	void build(){
		sort(pt+1,pt+pn+1,cmp);pn=unique(pt+1,pt+pn+1)-pt-1;
//		for(int i=1;i<=pn;i++) used[pt[i]]=1,vs.pb(pt[i]);
//		for(int i=1;i<=pn;i++) printf("insert %d\n",pt[i]);
		for(int i=1;i<=pn;i++) insert(pt[i]);fin();
	}
	int _dfn[MAXN+5],_low[MAXN+5],_tim=0;stack<int> _stk;
	int _from[MAXN+5];bitset<MAXN*2+5> _bri;
	void tarjan(int x,int f){
		_dfn[x]=_low[x]=++tim;_stk.push(x);
		for(int e=im.hd[x];e;e=im.nxt[e]){
			int y=im.to[e];
			if(!_dfn[y]){
				tarjan(y,x);_low[x]=min(_low[x],_low[y]);
				if(_low[y]>_dfn[x]) _bri[e]=_bri[e^1]=1;
			} else if(y!=f) _low[x]=min(_low[x],_dfn[y]);
		}
	}
	void dfs(int x){
		if(_from[x]) return;_from[x]=comp;
		for(int e=im.hd[x];e;e=im.nxt[e]){
			int y=im.to[e];if(!_bri[e]) dfs(y);
		}
	}
	void findecc(){
		ffe(it,vs) if(!_dfn[*it]) tarjan(*it,0);
		ffe(it,vs) if(!_from[*it]) comp++,dfs(*it);
	}
	void clear(){
//		fill0(ex);fill0(eu);fill0(ev);_bri.reset();fill0(_dfn);fill0(_low);fill0(_from);fill0(used);fill0(im.hd);
//		fill0(im.nxt);fill0(im.to);fill0(pt);while(_stk.size()) _stk.pop();fill0(stk);tp=0;
		for(int i=1;i<=vn;i++) ex[i]=0;
		for(int i=1;i<=en;i++) eu[i]=ev[i]=0;
		for(int i=1;i<=im.ec;i++) _bri[i]=0;
//		ffe(it,vs) printf("%d\n",*it);
		ffe(it,vs) _dfn[*it]=_low[*it]=_from[*it]=used[*it]=im.hd[*it]=0;
		vs.clear();im.ec=1;_tim=comp=0;
		int cur=1;while(pt[cur]) pt[cur++]=0;pn=0;
	}
	void work(int id){
		scanf("%d%d",&vn,&en);
		for(int i=1;i<=vn;i++){
			scanf("%d",&ex[i]);ex[i]=rotate(ex[i]);
//			printf("real %d\n",ex[i]);
			ex[i]=ecc::from[ex[i]];pt[++pn]=ex[i];
		}
//		for(int i=1;i<=vn;i++) printf("%d\n",ex[i]);
		for(int i=1;i<=en;i++){
			scanf("%d%d",&eu[i],&ev[i]);
			eu[i]=rotate(eu[i]);ev[i]=rotate(ev[i]);
//			printf("real %d %d\n",eu[i],ev[i]);
			eu[i]=ecc::from[eu[i]];ev[i]=ecc::from[ev[i]];
			pt[++pn]=eu[i],pt[++pn]=ev[i];
		} build();
//		for(int i=1;i<=en;i++) printf("%d %d\n",eu[i],ev[i]);
		for(int i=1;i<=en;i++) im.adde(eu[i],ev[i]),im.adde(ev[i],eu[i]);
		findecc();bool flg=1;for(int i=1;i<=vn;i++) flg&=(_from[ex[i]]==_from[ex[1]]);
		if(flg) R+=id,puts("YES");else puts("NO");
		clear();
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&qu);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g0.adde(u,v);g0.adde(v,u);
	} ecc::work();
	for(int i=1;i<=k;i++) if(!fa[i][0]) dfs(i,0);
	for(int i=1;i<=LOG_N;i++) for(int j=1;j<=k;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
	for(int _=1;_<=qu;_++) virt::work(_);
	return 0;
}
/*
15 14 1
1 2
2 3
2 4
4 5
4 6
6 7
6 8
8 9
8 10
10 11
11 12
12 13
13 14
13 15
4 7
1 15 14 3
1 3
2 5
4 7
6 9
8 11
10 13
14 15
*/