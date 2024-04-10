#include<bits/stdc++.h>
#define N 200100
using namespace std;
typedef long long ll;
vector<int> g[N];
bool cross[N];
struct edge{
	int u,v,c,id;
	bool operator<(edge rhs)const{return c<rhs.c;}
}e[N];
int f[N],sz[N],ans[N],dep[N];
int par[N][20];//binary lifting parent
int mx[N][20];//max edge weight
int mn[N][20];//min lazy mark weight
bool vis[N];
int find(int x){
	if(f[x]==x) return x;
	else{
		return f[x]=find(f[x]);
	}
}
bool uni(int id){
	int fu=find(e[id].u),fv=find(e[id].v);
	if(fu==fv) return false;
	if(sz[fu]>sz[fv]) swap(fu,fv);
	sz[fv]+=sz[fu];
	f[fu]=fv;
	return true;
}
void init(int n){
	for(int i=1;i<=n;i++){
		f[i]=i;
		sz[i]=1;
		memset(mn[i],-1,sizeof(mn[i]));
	}
}
inline int to(int u,int id){
	return u^e[id].u^e[id].v;
}
void dfs(int u,int p,int d){
	par[u][0]=p;
	dep[u]=d;
	for(int i=0;i<g[u].size();i++){
		int v=to(u,g[u][i]);
		if(v!=p){
			dfs(v,u,d+1);
			mx[v][0]=e[g[u][i]].c;
		}
	}
}
void calc_max(int n){
	for(int j=1;j<20;j++){
		for(int i=1;i<=n;i++){
			int p=par[i][j-1];
			par[i][j]=par[p][j-1];
			mx[i][j]=max(mx[i][j-1],mx[p][j-1]);
		}
	}
}
inline int inf_min(int x,int y){
	if(x<0) return y;
	if(y<0) return x;
	return min(x,y);
}
void calc_min(int n){
	for(int j=19;j>0;j--){
		for(int i=1;i<=n;i++){
			if(dep[i]>=(1<<j)){
				int p=par[i][j-1];
				mn[i][j-1]=inf_min(mn[i][j-1],mn[i][j]);
				mn[p][j-1]=inf_min(mn[p][j-1],mn[i][j]);
			}
		}
	}
}
inline void upd(int &u,int i,int &max_path,int min_mark){
	max_path=max(max_path,mx[u][i]);
	mn[u][i]=inf_min(mn[u][i],min_mark);
	u=par[u][i];
}
void path_upd(int u,int v,int &max_path,int min_mark){
	if(dep[u]<dep[v]) swap(u,v);
	for(int i=19;i>=0;i--){
		if(dep[u]-dep[v]>=(1<<i)){
			upd(u,i,max_path,min_mark);
		}
	}
	if(u==v) return;
	for(int i=19;i>=0;i--){
		if(par[u][i]!=par[v][i]){
			upd(u,i,max_path,min_mark);
			upd(v,i,max_path,min_mark);
		}
	}
	upd(u,0,max_path,min_mark);
	upd(v,0,max_path,min_mark);
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	init(n);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
		e[i].id=i;
	}
	sort(e,e+m);
	for(int i=0;i<m;i++){
		if(uni(i)){
			g[e[i].u].push_back(i);
			g[e[i].v].push_back(i);
		}
		else{
			cross[i]=true;
		}
	}
	dfs(1,0,0);
	calc_max(n);
	for(int i=0;i<m;i++){
		if(cross[i]){
			path_upd(e[i].u,e[i].v,ans[e[i].id],e[i].c-1);
			ans[e[i].id]--;
		}
	}
	calc_min(n);
	for(int i=0;i<m;i++){
		if(!cross[i]){
			if(dep[e[i].u]<dep[e[i].v]) swap(e[i].u,e[i].v);
			ans[e[i].id]=mn[e[i].u][0];
		}
	}
	for(int i=0;i<m;i++) printf("%d%c",ans[i],i==m-1?'\n':' ');
	return 0;
}