#include<bits/stdc++.h>
using namespace std; 
const int N=1e5+5;
int he[N],to[N<<1],ne[N<<1],p[N],d[N],tp[N],fa[N],sz[N],sn[N],id;
bool cmp(int x,int y){return p[x]<p[y];}
void dfs1(int x,int y){
	d[x]=d[y]+1,fa[x]=y,sz[x]=1;
	for(int i=he[x],j;i;i=ne[i])if(j=to[i],j!=y){
		dfs1(j,x),sz[x]+=sz[j];
		if(sz[j]>sz[sn[x]])sn[x]=j;
	}
}
void dfs2(int x,int y){
	tp[x]=y,p[x]=++id;
	if(!sn[x])return;
	dfs2(sn[x],y);
	for(int i=he[x],j;i;i=ne[i])if(j=to[i],j!=fa[x]&&j!=sn[x])dfs2(j,j);
}
int lca(int x,int y){
	while(tp[x]!=tp[y])if(d[tp[x]]<d[tp[y]])y=fa[tp[y]];else x=fa[tp[x]];
	return d[x]<d[y]?x:y;
}
int a[N],He[N],To[N],Ne[N],tt,st[N];
bool f[N],g[N];
void add(int x,int y){Ne[++tt]=He[x],To[tt]=y,He[x]=tt;}
int dfs(int x){
	int w=0,r=0,i=He[x];
	for(;i;i=Ne[i])r+=dfs(To[i]),w+=g[To[i]];
	if(f[x])r+=w,g[x]=1;
	else if(w>1)++r,g[x]=0;
	else g[x]=w;
	return He[x]=f[x]=0,r;
}
int main(){
	int n,m,q,i,j,k,t=0;
	scanf("%d",&n);
	for(i=1;i<n;++i){
		scanf("%d%d",&j,&k);
		ne[++t]=he[j],to[t]=k,he[j]=t;
		ne[++t]=he[k],to[t]=j,he[k]=t; 
	}
	dfs1(1,0),dfs2(1,1);
	scanf("%d",&q);
	while(q--){
		scanf("%d",&m);
		for(i=1;i<=m;++i)scanf("%d",a+i),f[a[i]]=1;
		for(i=1;i<=m;++i)if(f[fa[a[i]]]){
			puts("-1");
			for(i=1;i<=m;++i)f[a[i]]=0;
			goto _;
		}
		sort(a+1,a+m+1,cmp),tt=0,st[t=1]=a[1];
		for(i=2;i<=m;++i){
			j=lca(st[t],a[i]);
			while(d[j]<d[st[t-1]])add(st[t-1],st[t]),--t;
			if(j!=st[t]){
				add(j,st[t]);
				if(st[t-1]==j)--t;else st[t]=j;
			}
			st[++t]=a[i];
		}
		while(--t)add(st[t],st[t+1]);
		printf("%d\n",dfs(st[1]));
		_:;
	}
	return 0;
}