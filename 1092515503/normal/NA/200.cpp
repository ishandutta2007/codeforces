#include<bits/stdc++.h>
using namespace std;
int n,m,col[20100],c,res,mx,leaf,sz;
namespace ECC{
	vector<int>v[20100];
	int dfn[20100],low[20100],tot;
	stack<int>s;
	void Tarjan(int x,int fa){
		dfn[x]=low[x]=++tot,s.push(x);
		for(auto y:v[x]){
			if(y==fa)continue;
			if(!dfn[y])Tarjan(y,x),low[x]=min(low[x],low[y]);
			else low[x]=min(low[x],dfn[y]);
		}
		if(dfn[x]!=low[x])return;
		c++;
		while(s.top()!=x)col[s.top()]=c,s.pop();
		col[s.top()]=c,s.pop();
	}
}
namespace Tree{
	vector<int>v[20100];
	int dis[20100];
	bool vis[20100];
	void dfs(int x){
		sz++,leaf+=(v[x].size()==1),vis[x]=true,dis[x]=1;
		for(auto y:v[x])if(!vis[y])dfs(y),mx=max(mx,dis[x]+dis[y]),dis[x]=max(dis[x],dis[y]+1);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),ECC::v[x].push_back(y),ECC::v[y].push_back(x);
	for(int i=1;i<=n;i++)if(!ECC::dfn[i])ECC::Tarjan(i,0);
	res=n-c-1;
//	for(int i=1;i<=n;i++)printf("%d ",col[i]);puts("");
	for(int i=1;i<=n;i++)for(auto j:ECC::v[i])if(col[i]!=col[j])Tree::v[col[i]].push_back(col[j]);
	for(int i=1;i<=c;i++){
		if(Tree::vis[i])continue;
		mx=leaf=sz=0;
		Tree::dfs(i);
		res++;
		if(sz!=1)res+=sz-leaf-(mx-2);
	}
	printf("%d\n",res);
	return 0;
}