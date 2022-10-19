#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,val[300100],f[300100],mx=0x8080808080808080,res,head[300100],cnt;
bool vis[300100];
struct node{
	int to,next;
}edge[600100];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
	edge[cnt].next=head[v],edge[cnt].to=u,head[v]=cnt++;
}
void dfs1(int x,int fa){
	f[x]=val[x];
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa)dfs1(edge[i].to,x),f[x]+=max(0ll,f[edge[i].to]);
}
void dfs2(int x,int fa){
	f[x]=val[x];
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa)dfs2(edge[i].to,x),f[x]+=max(0ll,f[edge[i].to]);
	if(f[x]==mx)res++,f[x]=0x8080808080808080;
}
signed main(){
	scanf("%lld",&n),memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)scanf("%lld",&val[i]);
	for(int i=1,x,y;i<n;i++)scanf("%lld%lld",&x,&y),ae(x,y);
	dfs1(1,0);
	for(int i=1;i<=n;i++)mx=max(mx,f[i]);
	dfs2(1,0);
	printf("%lld %lld\n",1ll*res*mx,res);
	return 0;
}