#include<bits/stdc++.h>
using namespace std;
int n,*f[1001000],F[1001000],dep[1001000],son[1001000],g[1001000],*ff=F;
vector<int>v[1001000];
void dfs1(int x,int fa){
	for(auto y:v[x])if(y!=fa){
		dfs1(y,x);
		if(dep[y]>dep[son[x]])son[x]=y;
	}
	dep[x]=dep[son[x]]+1;
}
void dfs2(int x,int fa){
	if(!f[x])f[x]=ff,ff+=dep[x];
	if(son[x])f[son[x]]=f[x]+1,dfs2(son[x],x),g[x]=g[son[x]]+1;
	f[x][0]=1;if(f[x][g[x]]<=1)g[x]=0;
	for(auto y:v[x])if(y!=fa&&y!=son[x]){
		dfs2(y,x);
		for(int i=0;i<dep[y];i++){
			f[x][i+1]+=f[y][i];
			if(f[x][i+1]>f[x][g[x]]||f[x][i+1]==f[x][g[x]]&&g[x]>i+1)g[x]=i+1;
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	dfs1(1,0),dfs2(1,0);
//	for(int i=1;i<=n;i++)printf("(%d %d)\n",dep[i],son[i]);
	for(int i=1;i<=n;i++)printf("%d\n",g[i]);
	return 0;
}