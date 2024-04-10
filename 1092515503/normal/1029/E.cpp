#include<bits/stdc++.h>
using namespace std;
int n,head[1001000],cnt,f[1001000][3],res;//0:have a son;1:itself;2:have a father 
struct node{
	int to,next;
}edge[2001000];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
}
void dfs(int x,int fa){
	int mn=0x3f3f3f3f;
	f[x][1]=1;
	for(int i=head[x],y;i!=-1;i=edge[i].next){
		if((y=edge[i].to)==fa)continue;
		dfs(y,x);
		f[x][0]+=min(f[y][0],f[y][1]),mn=min(mn,f[y][1]-f[y][0]);
		f[x][1]+=min(f[y][0],min(f[y][1],f[y][2]));
		f[x][2]+=min(f[y][0],f[y][1]);
		if(x==1)res+=f[y][1]-1;
	}
	f[x][0]+=max(mn,0);
}
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),ae(x,y),ae(y,x);
	dfs(1,0);
	printf("%d\n",res);
	return 0;
}