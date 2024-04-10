#include<bits/stdc++.h>
using namespace std;
int n,rt,head[1001000],sum[1001000],all,val[1001000],cnt,has1[1001000];
struct node{
	int to,next;
}edge[1001000];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
}
void dfs(int x){
	sum[x]=val[x];
	for(int i=head[x];i!=-1;i=edge[i].next){
		dfs(edge[i].to),sum[x]+=sum[edge[i].to];
		if(has1[edge[i].to]){
			if(!has1[x])has1[x]=has1[edge[i].to];
			else{printf("%d %d\n",has1[x],has1[edge[i].to]);exit(0);}
		}
	}
	if(sum[x]==all*2&&has1[x]&&x!=rt){printf("%d %d\n",x,has1[x]);exit(0);}
	if(sum[x]==all)has1[x]=x;
}
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head));
	for(int i=1,x;i<=n;i++){
		scanf("%d%d",&x,&val[i]),all+=val[i];
		if(!x)rt=i;
		else ae(x,i);
	}
	if(all%3!=0){puts("-1");return 0;}
	all/=3;
	dfs(rt);
	puts("-1");
	return 0;
}