#include<cstdio>
#include<algorithm>
using std::swap;
const int maxn=2e5+10;
struct dsu{
	int fa[maxn],siz[maxn];
	inline void init(int k){for(int i=1;i<=k;++i)fa[i]=i,siz[i]=1;}
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
	inline bool merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){
			if(siz[x]>siz[y])swap(x,y);
			fa[x]=y,siz[y]+=siz[x];
			return true;
		}
		return false;
	}
}d;
int to[maxn][2],m,n,t_case;
bool mst[maxn];
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int dep[maxn],dfn,fa[maxn],rev[maxn],seg[maxn],siz[maxn],son[maxn],top[maxn];
void dfs1(int p,int f){
	dep[p]=dep[f]+1;
	fa[p]=f;
	siz[p]=1;
	for(int i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f){
			dfs1(e[i].to,p);
			siz[p]+=siz[e[i].to];
			if(siz[e[i].to]>siz[son[p]])son[p]=e[i].to;
		}
}
void dfs2(int p,int k){
	seg[p]=++dfn;
	rev[dfn]=p;
	top[p]=k;
	if(son[p]){
		dfs2(son[p],k);
		for(int i=hd[p];i;i=e[i].nxt)
			if(!top[e[i].to])
				dfs2(e[i].to,e[i].to);
	}
}
inline int lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
inline int kth(int x,int k){
	while(dep[x]-dep[top[x]]<k)k-=dep[x]-dep[fa[top[x]]],x=fa[top[x]];
	return rev[seg[x]-k];
}
long long c1[maxn],c2[maxn];
#define lowbit(k) (k&-k)
inline void add(int l,int r,int k){
	for(int i=l;i<=n;i+=lowbit(i))c1[i]+=k,c2[i]+=1ll*(l-1)*k;
	for(int i=r+1;i<=n;i+=lowbit(i))c1[i]-=k,c2[i]-=1ll*r*k;
}
inline long long query(int l,int r){
	long long ret=0;
	for(int i=r;i;i^=lowbit(i))ret+=r*c1[i]-c2[i];
	for(int i=l-1;i;i^=lowbit(i))ret-=(l-1)*c1[i]-c2[i];
	return ret;
}
int main(){
	scanf("%d%d",&n,&m);
	d.init(n);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&to[i][0],&to[i][1]);
		if(d.merge(to[i][0],to[i][1]))mst[i]=true,addedge(to[i][0],to[i][1]),addedge(to[i][1],to[i][0]);
	}
	dfs1(1,0);
	dfs2(1,1);
	for(int i=1;i<=m;++i)
		if(!mst[i]){
			int x=to[i][0],y=to[i][1],l=lca(x,y);
			if(l==x||l==y){
				if(l==y)swap(x,y);
				int p=kth(y,dep[y]-dep[x]-1);
				add(seg[p],seg[p]+siz[p]-1,1);
				add(seg[y],seg[y]+siz[y]-1,-1);
			}
			else{
				add(1,n,1);
				add(seg[x],seg[x]+siz[x]-1,-1);
				add(seg[y],seg[y]+siz[y]-1,-1);
			}
		}
	for(int i=1;i<=n;++i)putchar(!query(seg[i],seg[i])|48);
	return 0;
}