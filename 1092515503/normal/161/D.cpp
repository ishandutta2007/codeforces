#include<bits/stdc++.h>
using namespace std;
int n,m,f[50100][510],head[50100],cnt,res;
struct node{
	int to,next;
}edge[200100];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,head[v]=cnt++;
}
void dfs(int x,int fa){
	f[x][0]=1;
	for(int i=head[x],y;i!=-1;i=edge[i].next){
		if((y=edge[i].to)==fa)continue;
		dfs(y,x);
		for(int j=m;j;j--)f[y][j]=f[y][j-1],f[x][j]+=f[y][j];
		f[y][0]=0;
		for(int j=0;j<=m;j++)res+=(f[x][j]-f[y][j])*f[y][m-j];
	}
}
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),ae(x,y);
	dfs(1,0);
	printf("%d\n",res);
	return 0;
}