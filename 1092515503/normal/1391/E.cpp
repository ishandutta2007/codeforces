#include<bits/stdc++.h>
using namespace std;
int T,n,m,dep[500100];
vector<int>v[500100],u[500100];
vector<pair<int,int> >r;
bool vis[500100];
bool dfs(int x){
	vis[x]=true;
	if(dep[x]==(n-1)/2){printf("PATH\n%d\n%d",(n+1)/2,x);return true;}
	for(auto y:v[x])if(!vis[y]){
		dep[y]=dep[x]+1;
		if(dfs(y)){printf(" %d",x);return true;}
	}
	return false;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)vis[i]=false,dep[i]=0,v[i].clear();
		for(int i=0;i<=n;i++)u[i].clear();
		for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
		if(dfs(1)){puts("");continue;}
		puts("PAIRING");
		r.clear();
		for(int i=1;i<=n;i++){
			u[dep[i]].push_back(i);
			if(u[dep[i]].size()>=2)r.emplace_back(u[dep[i]][0],u[dep[i]][1]),u[dep[i]].clear();
		}
		printf("%d\n",r.size());
		for(auto i:r)printf("%d %d\n",i.first,i.second);
	}
	return 0;
}
/*
1
12 14
1 2
2 3
3 4
4 1
1 5
1 12
2 6
2 7
3 8
3 9
4 10
4 11
2 4
1 3
*/