#include<bits/stdc++.h>
using namespace std;
int n,m,val[211],head[211],cnt,f[211][211],res;//f[i][j]:the maximum weight,in the subtree of node i,and the shallowest picked node is j nodes deeper than node i.
struct node{
	int to,next;
}edge[411];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
}
void dfs(int x,int fa){
	f[x][0]=val[x];
	for(int i=head[x],y;i!=-1;i=edge[i].next){
		if(edge[i].to==fa)continue;
		y=edge[i].to,dfs(y,x);
		f[y][m]=max(f[y][m],f[y][m-1]);
		for(int j=m-1;j;j--)f[y][j]=f[y][j-1];
		f[y][0]=0;
		for(int j=0;j<=m;j++){
			int val=f[x][j];f[x][j]=0;//when k<=j,many terrible things would happen if you don't clear f[x][j];
			for(int k=m-j;k<=m;k++)f[x][min(j,k)]=max(f[x][min(j,k)],f[y][k]+val);//only two nodes with distance>=m can be chosen together.
		}
	}
}
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head)),m++;//m++!!!!!! otherwise the loops in DFS will be more confusing.
	for(int i=1;i<=n;i++)scanf("%d",&val[i]);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),ae(x,y),ae(y,x);
	dfs(1,0);
	for(int i=0;i<=m;i++)res=max(res,f[1][i]);
	printf("%d\n",res);
	return 0;
}
/*
5 1
1 2 3 4 5
1 2
2 3
3 4
3 5
*/