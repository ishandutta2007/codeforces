#include<bits/stdc++.h>
using namespace std;
int n,m;
int X[600100],Y[600100],P[600100],Q[600100],d[600100],deg[300100];
bool era[600100];
void direct(int i,int x,int y){
//	printf("direct:%d(%d,%d)[%d,%d]\n",i,X[i],Y[i],x,y);
	if(X[i]==x){
		assert(X[i]==x),assert(Y[i]==y);
		d[i]=true;
		if(P[i])direct(P[i],x,X[P[i]]^Y[P[i]]^x);
		if(Q[i])direct(Q[i],X[Q[i]]^Y[Q[i]]^y,y);
	}else{
		assert(X[i]==y),assert(Y[i]==x);
		d[i]=false;
		if(P[i])direct(P[i],X[P[i]]^Y[P[i]]^y,y);
		if(Q[i])direct(Q[i],x,X[Q[i]]^Y[Q[i]]^x);
	}
}
vector<int>u[300100];
struct Graph{
vector<int>v[300100];
void merge(int x,int i,int j){
	int y=X[i]^Y[i]^x,z=X[j]^Y[j]^x;
	era[i]=era[j]=true;
	if(y==z){direct(i,x,y),direct(j,z,x);return;}
	++m,P[m]=i,Q[m]=j,X[m]=y,Y[m]=z,v[y].push_back(m),v[z].push_back(m);
}
void func(){
	for(int x=1;x<=n;x++)for(int i=0,ano=-1;i<v[x].size();i++)if(!era[v[x][i]]){
		if(ano==-1)ano=v[x][i];
		else merge(x,v[x][i],ano),ano=-1;
	}
	for(int x=1;x<=n;x++)for(auto i:v[x])if(!era[i])u[x].push_back(i);
}
}g[2];
void dfs(int x){
	for(auto i:u[x])if(!era[i]){
		int y=X[i]^Y[i]^x;
		era[i]=true,direct(i,x,y),dfs(y);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,z;i<=m;i++)
		scanf("%d%d%d",&X[i],&Y[i],&z),g[z-1].v[X[i]].push_back(i),g[z-1].v[Y[i]].push_back(i),
		deg[X[i]]+=z,deg[Y[i]]+=z;
	int sum=0;for(int i=1;i<=n;i++)sum+=deg[i]&1;
	g[0].func(),g[1].func();
	for(int i=1;i<=n;i++)if(u[i].size()==1)dfs(i);
	for(int i=1;i<=n;i++)dfs(i);
	printf("%d\n",sum);
	for(int i=1;i<=m;i++)if(!P[i]&&!Q[i])printf("%d",d[i]+1);
	return 0;
}