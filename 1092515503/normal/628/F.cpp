#include<bits/stdc++.h>
using namespace std;
pair<int,int>p[10100];
int n,lim,m,head[20100],cur[20100],dep[20100],cnt,id[5],S,T,res;
struct node{
	int to,next,val;
}edge[200100];
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=0,head[v]=cnt++;
}
int calc(int L,int R,int mod){
	R=R-mod+5,L=L-mod+5;
	return R/5-L/5;
}
bool reach;
queue<int>q;
bool bfs(){
	memset(dep,0,sizeof(dep)),dep[S]=1,q.push(S);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=cur[x]=head[x];i!=-1;i=edge[i].next)if(edge[i].val&&!dep[edge[i].to])dep[edge[i].to]=dep[x]+1,q.push(edge[i].to);
	}
	return dep[T]>0;
}
int dfs(int x,int flow){
	if(x==T){reach=true;res+=flow;return flow;}
	int used=0;
	for(int &i=cur[x];i!=-1;i=edge[i].next){
		if(!edge[i].val||dep[edge[i].to]!=dep[x]+1)continue;
		int ff=dfs(edge[i].to,min(flow-used,edge[i].val));
		if(ff){
			edge[i].val-=ff;
			edge[i^1].val+=ff;
			used+=ff;
			if(used==flow)break;
		}
	}
	return used;
}
int main(){
	scanf("%d%d%d",&n,&lim,&m),memset(head,-1,sizeof(head));
	S=n+6,T=n+7;
	for(int i=0;i<5;i++)id[i]=n+i+1,ae(id[i],T,n/5);
	for(int i=1;i<=m;i++)scanf("%d%d",&p[i].first,&p[i].second);
	sort(p+1,p+m+1),m++,p[m]=make_pair(lim,n);
	for(int i=1;i<=m;i++)if(p[i].first-p[i-1].first<p[i].second-p[i-1].second||p[i].second<p[i-1].second){puts("unfair");return 0;}
	for(int i=1;i<=m;i++)ae(S,i,p[i].second-p[i-1].second);
	for(int i=1;i<=m;i++)for(int j=0;j<5;j++)ae(i,id[j],calc(p[i-1].first,p[i].first,j));
//	puts("IN");
	while(bfs()){
		reach=true;
		while(reach)reach=false,dfs(S,0x3f3f3f3f);
	}
//	printf("%d\n",res);
	puts(res==n?"fair":"unfair");
	return 0;
}