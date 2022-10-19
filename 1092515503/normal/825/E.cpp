#include<bits/stdc++.h>
using namespace std;
int n,m,head[100100],cnt,in[100100],ord[100100],tot;
priority_queue<int,vector<int>,less<int>>q;
struct node{
	int to,next;
}edge[100100];
void ae(int v,int u){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++,in[v]++;
}
int main(){
	scanf("%d%d",&n,&m),memset(head,-1,sizeof(head));
	for(int i=0,x,y;i<m;i++)scanf("%d%d",&x,&y),ae(x,y);
	for(int i=1;i<=n;i++)if(!in[i])q.push(i);
	while(!q.empty()){
		int x=q.top();q.pop();ord[x]=n-(++tot)+1;
		for(int i=head[x];i!=-1;i=edge[i].next){
			in[edge[i].to]--;
			if(!in[edge[i].to])q.push(edge[i].to);
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",ord[i]);
	return 0;
}