#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,dep[N],sz[N],dfn[N],fa[N][20],v[N],dnum;
vector <int> e[N];
int dfs(int id,int f,int d){
	fa[id][0]=f,dep[id]=d,sz[id]=1,dfn[id]=++dnum;
	for(auto it:e[id])if(it!=fa[id][0])sz[id]+=dfs(it,id,d+1);
	return sz[id];
}
bool cmp(int a,int b){
	return dep[a]>dep[b];
}
int LCA(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=18;~i;i--)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=18;~i;i--)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
bool check(int x,int y){
	int d=LCA(x,y);
	if(d!=y&&fa[y][0]!=d)return false;
	return true;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0,1);
	for(int i=1;i<19;i++)for(int j=1;j<=n;j++)fa[j][i]=fa[fa[j][i-1]][i-1];
	for(int i=1;i<=m;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)scanf("%d",&v[j]);
		sort(v+1,v+k+1,cmp);
		bool pd=1;
		for(int j=1;j<k;j++)if(!check(v[j],v[j+1]))pd=0;
		puts(pd?"YES":"NO");
	}
	return 0;
}
/*
10 6
1 2
1 3
1 4
2 5
2 6
3 7
7 8
7 9
9 10
4 3 8 9 10
3 2 4 6
3 2 1 5
3 4 8 2
2 6 10
3 5 4 7
*/