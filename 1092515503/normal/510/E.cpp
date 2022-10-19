#include<bits/stdc++.h>
using namespace std;
int n,num[210],odd,head[210],cnt,s,t,dep[210],res,cur[210];
inline bool prime(int ip){
	if(ip<2)return false;
	for(register int i=2;i*i<=ip;i++)if(!(ip%i))return false;
	return true;
}
struct node{
	int to,next,val;
}edge[100010];
inline void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
}
queue<int>q;
inline bool bfs(){
	memset(dep,0,sizeof(dep)),dep[s]=1,q.push(s);
	while(!q.empty()){
		register int x=q.front();q.pop();
		for(register int i=cur[x]=head[x];i!=-1;i=edge[i].next)if(edge[i].val&&!dep[edge[i].to])dep[edge[i].to]=dep[x]+1,q.push(edge[i].to);
	}
	return dep[t]>0;
}
bool reach;
inline int dfs(int x,int flow){
	if(x==t){
		reach=true;
		res+=flow;
		return flow;
	}
	register int used=0;
	for(register int &i=cur[x];i!=-1;i=edge[i].next){
		if(!edge[i].val||dep[edge[i].to]!=dep[x]+1)continue;
		register int ff=dfs(edge[i].to,min(flow,edge[i].val));
		if(ff){
			used+=ff;
			edge[i].val-=ff;
			edge[i^1].val+=ff;
			if(used==flow)break;
		}
	}
	return used;
}
vector<int>g[210],v[210];
bool vis[210];
inline void dfs_ans(int x){
	if(vis[x])return;vis[x]=true,v[res].push_back(x);
	for(register int i=0;i<g[x].size();i++)dfs_ans(g[x][i]);
}
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head)),s=n+1,t=n+2;
	for(register int i=1;i<=n;i++)scanf("%d",&num[i]),odd+=(num[i]&1);
	if(odd*2!=n){puts("Impossible");return 0;}
	for(register int i=1;i<=n;i++){
		if(num[i]&1)ae(s,i,2),ae(i,s,0);
		else ae(i,t,2),ae(t,i,0);
	}
	for(register int i=1;i<=n;i++)for(register int j=1;j<=n;j++)if((num[i]&1)&&!(num[j]&1)&&prime(num[i]+num[j]))ae(i,j,1),ae(j,i,0);
	while(bfs()){
		reach=true;
		while(reach)reach=false,dfs(s,0x3f3f3f3f);
	}
	if(res!=n){puts("Impossible");return 0;}
	for(register int i=1;i<=n;i++){
		if(!(num[i]&1))continue;
		for(register int j=head[i];j!=-1;j=edge[j].next)if(edge[j].to<=n&&!(num[edge[j].to]&1)&&!edge[j].val)g[i].push_back(edge[j].to),g[edge[j].to].push_back(i);
	}
	res=0;
	for(register int i=1;i<=n;i++)if(!vis[i])res++,dfs_ans(i);
	printf("%d\n",res);
	for(register int i=1;i<=res;i++){
		printf("%d ",v[i].size());
		for(register int j=0;j<v[i].size();j++)printf("%d ",v[i][j]);
		puts("");
	}
	return 0;
}