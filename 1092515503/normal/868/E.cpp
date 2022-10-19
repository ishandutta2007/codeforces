#include<bits/stdc++.h>
using namespace std;
int n,m,S,f[120][60][60],head[60],deg[60],cnt,sz[60],res=0x3f3f3f3f;//policeman on edge i;j terrorists are remaining;k terrorists on his opposite direction
struct node{int to,next,val;}edge[120];
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,edge[cnt].val=w,head[v]=cnt++;
}
void DP(int id,int u);
int F(int x,int y,int z){if(!y)return 0;if(f[x][y][z]==-1)DP(x,y);return f[x][y][z];}
struct dat{
	int x,y,z;
	dat(int X,int Y,int Z){x=X,y=Y,z=Z;}
	int val()const{return z<y?F(x,y,z+1):0;}
	friend bool operator<(const dat&u,const dat&v){return u.val()<v.val();}
};
void DP(int id,int u){
	f[id][u][0]=0x3f3f3f3f;
	if(deg[edge[id].to]==1){for(int i=1;i<=u;i++)f[id][u][i]=F(id^1,u-i,u-i)+edge[id].val;return;}
	priority_queue<dat>q;
	for(int i=head[edge[id].to];i!=-1;i=edge[i].next)if((i^id)!=1)q.emplace(i,u,0);
	for(int i=1;i<=u;i++){
		dat x=q.top();q.pop();
		f[id][u][i]=min(f[id][u][i-1],x.val()+edge[id].val);
		x.z++,q.push(x);
	}
}
void dfs(int x,int fa){for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa)dfs(edge[i].to,x),sz[x]+=sz[edge[i].to];}
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head)),memset(f,-1,sizeof(f));
	for(int i=1,x,y,z;i<n;i++)scanf("%d%d%d",&x,&y,&z),ae(x,y,z),deg[x]++,deg[y]++;
	scanf("%d%d",&S,&m);
	for(int i=1,x;i<=m;i++)scanf("%d",&x),sz[x]++;
	dfs(S,0);
	for(int i=head[S];i!=-1;i=edge[i].next)res=min(res,F(i,m,sz[edge[i].to]));
	printf("%d\n",res);
	return 0;
}