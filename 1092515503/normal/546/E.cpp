#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],b[110],head[210],cnt,dep[210],res,sa,sb,ans[110][110];
struct node{
	int to,next,val,sz;
}edge[100100];
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].sz=edge[cnt].val=w,head[u]=cnt++;
}
queue<int>q;
bool bfs(){
	memset(dep,0,sizeof(dep)),dep[2*n+1]=1,q.push(2*n+1);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].val&&!dep[edge[i].to])dep[edge[i].to]=dep[x]+1,q.push(edge[i].to);
	}
	return dep[2*n+2]>0;
}
int dfs(int x,int flow){
	if(x==2*n+2||!flow)return flow;
	for(int i=head[x];i!=-1;i=edge[i].next){
		if(!edge[i].val||dep[edge[i].to]!=dep[x]+1)continue;
		int ff=dfs(edge[i].to,min(flow,edge[i].val));
		if(ff){
			edge[i].val-=ff;
			edge[i^1].val+=ff;
			return ff;
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),ae(2*n+1,i,a[i]),ae(i,2*n+1,0),sa+=a[i];
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),ae(i+n,2*n+2,b[i]),ae(2*n+2,i+n,0),sb+=b[i];
	if(sa!=sb){puts("NO");return 0;}
	for(int i=1;i<=n;i++)ae(i,i+n,0x3f3f3f3f),ae(i+n,i,0);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),ae(x,y+n,0x3f3f3f3f),ae(y+n,x,0),ae(y,x+n,0x3f3f3f3f),ae(x+n,y,0);
	while(bfs())res+=dfs(2*n+1,0x3f3f3f3f);
	if(res!=sa){puts("NO");return 0;}
	for(int i=1;i<=n;i++)for(int j=head[i];j!=-1;j=edge[j].next)if(edge[j].to>n&&edge[j].to<=2*n)ans[i][edge[j].to-n]=edge[j].sz-edge[j].val;
	puts("YES");
	for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)printf("%d ",ans[i][j]);puts("");}
	return 0;
}