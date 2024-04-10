#include <bits/stdc++.h>
using namespace std;
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
template<typename T>
void read(T &x){
	char c=getchar();T neg=1;
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=3e5;
int n,k;vector<int> g[MAXN+5],vv[MAXN+5];
int p[MAXN+5],indeg[MAXN+5],outdeg[MAXN+5];
int comp=0,bel[MAXN+5],dep[MAXN+5];
void dfs(int x){
	if(bel[x]){puts("0");exit(0);}
	bel[x]=comp;vv[comp].pb(x);ffe(it,g[x]) dep[*it]=dep[x]+1,dfs(*it);
}
int deg[MAXN+5],hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
bool vis[MAXN+5];
signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&p[i]);
	for(int i=1;i<=k;i++){
		int x,y;scanf("%d%d",&x,&y);
		outdeg[x]++;indeg[y]++;g[x].pb(y);
	}
	for(int i=1;i<=n;i++) if(indeg[i]>=2||outdeg[i]>=2) return puts("0"),0;
	for(int i=1;i<=n;i++) if(!indeg[i]) comp++,dfs(i);
	for(int i=1;i<=n;i++){
		if(!p[i]) continue;
		if(bel[p[i]]==bel[i]){
			if(dep[p[i]]>dep[i]) return puts("0"),0;
		}
		else adde(bel[p[i]],bel[i]),deg[bel[i]]++;
	}
	queue<int> q;vector<int> ans;
	for(int i=1;i<=comp;i++) if(!deg[i]) q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		ffe(it,vv[x]) ans.pb(*it);
		for(int e=hd[x];e;e=nxt[e]){
			deg[to[e]]--;
			if(!deg[to[e]]) q.push(to[e]);
		}
	}
	if(ans.size()!=n) puts("0");
	else ffe(it,ans) printf("%d ",*it);
	return 0;
}