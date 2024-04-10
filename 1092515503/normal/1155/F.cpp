#include<bits/stdc++.h>
using namespace std;
int n,m,g[110][110],tot,mn;
pair<int,int>p[110];
bool on[110],res[110],ok;
int dfn[110],low[110],cnt;
void Tarjan(int x,int fa){
	dfn[x]=low[x]=++cnt;
	for(int i=1;i<=n;i++){
		if(i==fa||!g[x][i])continue;
		if(!dfn[i])Tarjan(i,x),low[x]=min(low[x],low[i]);
		else low[x]=min(low[x],dfn[i]);
	}
	if(x!=1&&low[x]>=dfn[x])ok=false;
}
bool che(){
	ok=true;
	for(int i=1;i<=n;i++)dfn[i]=low[i]=0;
	cnt=0;
	Tarjan(1,0);
	return ok;
}
int main(){
	srand(time(0));
	scanf("%d%d",&n,&m),mn=m;
	for(int i=1;i<=m;i++)scanf("%d%d",&p[i].first,&p[i].second),res[i]=true;
	for(int t=0;t<1000000;t++){
		if(!(t%1000)){
			tot=m;
			for(int i=1;i<=m;i++)g[p[i].first][p[i].second]=g[p[i].second][p[i].first]=true,on[i]=true;
		}
		if(rand()%4||tot==m){
			int x=rand()%m+1;
			while(!on[x])x=rand()%m+1;
			on[x]=false,g[p[x].first][p[x].second]=g[p[x].second][p[x].first]=false,tot--;
			if(!che())on[x]=true,g[p[x].first][p[x].second]=g[p[x].second][p[x].first]=true,tot++;
		}else{
			int x=rand()%m+1;
			while(on[x])x=rand()%m+1;
			on[x]=true,g[p[x].first][p[x].second]=g[p[x].second][p[x].first]=true,tot++;
		}
		if(tot<mn){mn=tot;for(int i=1;i<=m;i++)res[i]=on[i];}
	}
	printf("%d\n",mn);
	for(int i=1;i<=m;i++)if(res[i])printf("%d %d\n",p[i].first,p[i].second);
	return 0;
}