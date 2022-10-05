#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=6e6+5;
int n,he[N],to[N<<1],ne[N<<1],fa[N],sn[N],sz[N],d[N],tp[N],ps[N],ct;
void dfs1(int x,int y){
	fa[x]=y,d[x]=d[y]+1,sz[x]=1;
	for(int i=he[x],j;i;i=ne[i])if(j=to[i],j!=y){
		dfs1(j,x),sz[x]+=sz[j];
		if(sz[j]>sz[sn[x]])sn[x]=j;
	}
}
void dfs2(int x,int y){
	tp[x]=y,ps[x]=++ct;
	if(!sn[x])return;
	dfs2(sn[x],y);
	for(int i=he[x],j;i;i=ne[i])if(j=to[i],j!=fa[x]&&j!=sn[x])dfs2(j,j);
}
vector<int>vc[N<<2],e[M];
int u,v,w,id,cl[M],dfn[M],low[M],c,z,st[M],t;
inline void add(int x,int y){e[x].push_back(y),e[y^1].push_back(x^1);}
void upd(int k,int l,int r){
	if(u<=l&&r<=v)return vc[k].push_back(w);
	int m=l+r>>1;
	if(u<=m)upd(k<<1,l,m);
	if(m<v)upd(k<<1|1,m+1,r);
}
void mdf(int x,int y){
	while(tp[x]!=tp[y]){
		if(d[tp[x]]<d[tp[y]])swap(x,y);
		u=ps[tp[x]],v=ps[x],upd(1,2,n),x=fa[tp[x]];
	}
	if(x!=y){
		if(d[x]<d[y])swap(x,y);
		u=ps[y]+1,v=ps[x],upd(1,2,n);
	}
}
void build(int k,int l,int r,int p){
	int o=vc[k].size(),i,j,u=++id,v=(id+=o);
	if(o)add(v-1<<1,v<<1);
	else if(p)add(p<<1,v<<1);
	for(i=0;i<o;++i){
		j=vc[k][i],add(j,u+i<<1);
		if(i>0)add(u+i-1<<1,u+i<<1),add(u+i-1<<1,j^1);
		else if(p)add(p<<1,u<<1),add(p<<1,j^1);
	}
	if(l==r)return;
	int m=l+r>>1;
	build(k<<1,l,m,v),build(k<<1|1,m+1,r,v);
}
void tarjan(int x){
	dfn[x]=low[x]=++z,st[++t]=x;
	for(auto j:e[x])
	if(!dfn[j])tarjan(j),low[x]=min(low[x],low[j]);
	else if(!cl[j])low[x]=min(low[x],dfn[j]);
	if(low[x]==dfn[x]){
		cl[x]=++c;
		while(st[t]!=x)cl[st[t--]]=c;
		--t;
	}
}
int main(){
	int m,i,j,k,t=0;
	scanf("%d",&n);
	for(i=1;i<n;++i){
		scanf("%d%d",&j,&k);
		ne[++t]=he[j],to[t]=k,he[j]=t;
		ne[++t]=he[k],to[t]=j,he[k]=t;
	}
	dfs1(1,0),dfs2(1,1),scanf("%d",&m);
	for(i=1;i<=m;++i){
		scanf("%d%d",&j,&k),w=i<<1,mdf(j,k);
		scanf("%d%d",&j,&k),w|=1,mdf(j,k);
	}
	id=m,build(1,2,n,0);
	for(i=id<<1;i;--i)if(!cl[i])tarjan(i);
	for(i=1;i<=m;++i)if(cl[i<<1]==cl[i<<1|1])return puts("NO"),0;
	puts("YES");
	for(i=1;i<=m;++i)puts(cl[i<<1]<cl[i<<1|1]?"1":"2");
	return 0;
}