#include<bits/stdc++.h>
using namespace std;
int n,m,dfn[100100],low[100100],col[100100],c,tot,in[100100];
vector<int>u[100100],v[100100],w[100100],res;
stack<int>s;
void Tarjan(int x){
	dfn[x]=low[x]=++tot,s.push(x);
	for(auto y:u[x]){
		if(!dfn[y])Tarjan(y),low[x]=min(low[x],low[y]);
		else if(!col[y])low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]>low[x])return;
	c++;
	while(s.top()!=x)col[s.top()]=c,v[c].push_back(s.top()),s.pop();col[s.top()]=c,v[c].push_back(s.top()),s.pop();
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),u[x].push_back(y);
	for(int i=1;i<=n;i++)if(!dfn[i])Tarjan(i);
	for(int i=1;i<=n;i++)for(auto j:u[i])if(col[i]!=col[j])w[col[i]].push_back(col[j]),in[col[j]]++;
	for(int i=1;i<=c;i++)if(!in[i])res.push_back(i);
	while(res.size()>1){
		int x=res.back();res.pop_back();
		int y=res.back();res.pop_back();
		printf("? %d %d\n",v[x].back(),v[y].back()),fflush(stdout);
		int dir;scanf("%d",&dir);
		if(!dir)swap(x,y);
		v[y].pop_back();
		res.push_back(x);
		if(!v[y].empty())res.push_back(y);
		else for(auto z:w[y])if(!--in[z])res.push_back(z);
	}
	printf("! %d\n",v[res.back()].back());
	return 0;
}