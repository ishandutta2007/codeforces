#include<bits/stdc++.h>
using namespace std;
int n,m,k,head[200100],cnt,d1[200100],d2[200100],res;
struct node{
	int to,next;
}edge[400100];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,head[v]=cnt++;
}
queue<int>q;
void bfs(int S,int *dis){
	for(int i=1;i<=n;i++)dis[i]=-1;
	dis[S]=0;
	q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
//		printf("%d\n",x);
		for(int i=head[x];i!=-1;i=edge[i].next)if(dis[edge[i].to]==-1)dis[edge[i].to]=dis[x]+1,q.push(edge[i].to);
	}
}
vector<int>v;
bool cmp(int x,int y){
	return d1[x]-d2[x]<d1[y]-d2[y];
}
int main(){
	scanf("%d%d%d",&n,&m,&k),memset(head,-1,sizeof(head));
	for(int i=1,x;i<=k;i++)scanf("%d",&x),v.push_back(x);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),ae(x,y);
	bfs(1,d1),bfs(n,d2);
//	for(int i=1;i<=n;i++)printf("%d ",d1[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%d ",d2[i]);puts("");
	sort(v.begin(),v.end(),cmp);
	for(int i=0,mx=0;i<v.size();i++){
//		printf("%d %d %d\n",v[i],d1[v[i]],d2[v[i]]);
		if(i)res=max(res,mx+d2[v[i]]);
		mx=max(mx,d1[v[i]]); 
	}
	printf("%d\n",min(res+1,d1[n]));
	return 0;
}