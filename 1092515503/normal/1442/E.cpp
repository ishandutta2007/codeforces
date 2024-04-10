#include<bits/stdc++.h>
using namespace std;
int T,n,col[200100],f[200100][3],g[200100][3];
vector<int>v[200100];
void dfs(int x,int fa){
	for(auto y:v[x])if(y!=fa)dfs(y,x);
	for(int i=1;i<=2;i++)
	if(col[x]&&col[x]!=i)f[x][i]=g[x][i]=0x3f3f3f3f;
	else{
		f[x][i]=g[x][i]=1;
		for(auto y:v[x])if(y!=fa){
//			printf("%d+[%d,%d]=",f[x][i],f[y][1],f[y][2]);
			g[x][i]=max(g[x][i],min(max(f[y][1]+f[x][i]-(i==1),g[y][1]),max(f[y][2]+f[x][i]-(i==2),g[y][2])));
			f[x][i]=max(f[x][i],min(f[y][1]+(i!=1),f[y][2]+(i!=2)));
//			printf("%d\n",f[x][i]);
		}
	}
//	printf("%d[%d,%d][%d,%d]\n",x,f[x][1],g[x][1],f[x][2],g[x][2]);
	v[x].clear();
}
void mina(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&col[i]);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
	dfs(1,0);
	printf("%d\n",(min(g[1][1],g[1][2])>>1)+1);
}
int main(){
	scanf("%d",&T);
	while(T--)mina();
	return 0;
}
/*
1
4
1 2 1 2
1 2
2 3
3 4
*/