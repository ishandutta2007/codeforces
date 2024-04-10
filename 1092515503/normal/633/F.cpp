#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,f[100100],g[100100],h[100100],d[100100],head[100100],cnt,res,val[100100];
struct node{
	int to,next;
}edge[200100];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
}
void dfs1(int x,int fa){
	g[x]=val[x];
	for(int i=head[x],y;i!=-1;i=edge[i].next){
		if((y=edge[i].to)==fa)continue;
		dfs1(y,x);
		g[x]=max(g[x],f[x]+f[y]+val[x]);
		g[x]=max(g[x],g[y]);
		f[x]=max(f[x],f[y]);
	}
	f[x]+=val[x];
}
bool cmp1(const int &x,const int &y){
	return f[x]>f[y];
}
bool cmp2(const int &x,const int &y){
	return g[x]>g[y];
}
void dfs2(int x,int fa){
	vector<int>v,u;
	for(int i=head[x],y;i!=-1;i=edge[i].next){
		if((y=edge[i].to)==fa)continue;
		v.push_back(edge[i].to),u.push_back(edge[i].to);
	}
	sort(v.begin(),v.end(),cmp1),v.push_back(0),v.push_back(0);
	sort(u.begin(),u.end(),cmp2),u.push_back(0);
	for(int i=head[x],y;i!=-1;i=edge[i].next){
		if((y=edge[i].to)==fa)continue;
		d[y]=max({d[x],max(h[x],(y==v[0]||y==v[1]?f[v[2]]:f[v[1]]))+(y==v[0]?f[v[1]]:f[v[0]])+val[x],(y==u[0]?g[u[1]]:g[u[0]])});
		res=max(res,g[y]+d[y]);
//		printf("(%d,%d):%d,%d,%d,%d\n",x,y,g[y],max(h[x],(y==v[0]||y==v[1]?f[v[2]]:f[v[1]])),(y==v[0]?f[v[1]]:f[v[0]]),val[x]);
		h[y]=max(h[x],(y==v[0]?f[v[1]]:f[v[0]]))+val[x];
		dfs2(y,x);
	}
}
signed main(){
	scanf("%lld",&n),memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)scanf("%lld",&val[i]);
	for(int i=1,x,y;i<n;i++)scanf("%lld%lld",&x,&y),ae(x,y),ae(y,x);
	dfs1(1,0),dfs2(1,0);
//	for(int i=1;i<=n;i++)printf("%lld ",f[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%lld ",g[i]);puts("");
//	for(int i=1;i<=n;i++)printf("%lld ",h[i]);puts("");
	printf("%lld\n",res);
	return 0;
}