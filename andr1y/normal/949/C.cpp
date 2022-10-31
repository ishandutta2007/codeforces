#include<bits/stdc++.h>
int n,m,h,u[100010];
struct edge{int to;edge*next;}E[200010],*ne=E,*first[100010];
void link(int u,int v){*ne=(edge){v,first[u]};first[u]=ne++;}
int dfn[100010],low[100010],now,stk[100010],top,scc[100010],siz[100010],scnt,deg[100010];
bool ins[100010];
void dfs(int i){
	dfn[i]=low[i]=++now;
	stk[top++]=i;
	ins[i]=1;
	for(edge*e=first[i];e;e=e->next){
		if(!dfn[e->to]){
			dfs(e->to);
			if(low[e->to]<low[i])low[i]=low[e->to];
		}
		else if(ins[e->to]){
			if(dfn[e->to]<low[i])low[i]=dfn[e->to];
		}
	}
	if(dfn[i]==low[i]){
		scnt++;
		do scc[stk[--top]]=scnt,ins[stk[top]]=0,siz[scnt]++;
		while(stk[top]!=i);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&h);
	for(int i=1;i<=n;i++)scanf("%d",u+i);
	for(int i=0,c1,c2;i<m;i++){
		scanf("%d%d",&c1,&c2);
		if(u[c2]==(u[c1]+1)%h)link(c1,c2);
		if(u[c1]==(u[c2]+1)%h)link(c2,c1);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);
	for(int i=1;i<=n;i++)
		for(edge*e=first[i];e;e=e->next)
			if(scc[i]!=scc[e->to])deg[scc[i]]++;
	int mk=1<<30,mi;
	for(int i=1;i<=scnt;i++)if(!deg[i]&&siz[i]<mk)mk=siz[i],mi=i;
	printf("%d\n",mk);
	for(int i=1;i<=n;i++)if(scc[i]==mi)printf("%d ",i);
}