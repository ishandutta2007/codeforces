#include<bits/stdc++.h>
using namespace std;
int n,m,k,dep[250100],stk[250100],tp,fa[250100];
vector<int>v[250100],u[250100],w[250100];
bool vis[250100];
void dfs(int x){
	vis[x]=true,stk[++tp]=x;
	if(1ll*tp*k>=n){
		puts("PATH");
		printf("%d\n",tp);
		for(int i=1;i<=tp;i++)printf("%d ",stk[i]);puts("");
		exit(0);
	}
	for(auto y:v[x])
		if(!vis[y])dep[y]=dep[x]+1,fa[y]=x,dfs(y),u[x].push_back(y);
		else if(y!=fa[x])w[x].push_back(y);
	tp--;
}
vector<vector<int> >r;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	dfs(1);
	puts("CYCLES");
	for(int i=1;i<=n;i++){
		if(!u[i].empty())continue;
		int x=i;
		vector<int>p;
		for(auto y:w[x]){
			if(dep[y]%3==(dep[x]+1)%3)continue;
			while(x!=y)p.push_back(x),x=fa[x];
			p.push_back(x);break;
		}
		if(p.empty()){
			int y=w[x][0],z=w[x][1];
			if(dep[y]<dep[z])swap(y,z);
			while(y!=z)p.push_back(y),y=fa[y];
			p.push_back(z),p.push_back(x);
		}
		r.push_back(p);
		if(r.size()==k)break;
	}
	for(auto i:r){printf("%d\n",i.size());for(auto j:i)printf("%d ",j);puts("");}
	return 0;
}