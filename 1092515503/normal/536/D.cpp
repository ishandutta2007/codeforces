#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e15;
int n,m,SUM,head[2010],cnt,dis1[2010],dis2[2010],S,T,val[2010],f1[2010][2010],f2[2010][2010],cnt1[2010][2010],cnt2[2010][2010],sum[2010][2010],lim1,lim2,n1[2010],n2[2010],m1[2010],m2[2010];
priority_queue<pair<int,int> >q;
struct node{
	int to,next,val;
}edge[201000];
void ae(int u,int v,int w){
	edge[cnt].next=head[u],edge[cnt].to=v,edge[cnt].val=w,head[u]=cnt++;
}
bool vis[2010];
void dijkstra(int &root,int *dis){
	for(int i=1;i<=n;i++)dis[i]=1e18,vis[i]=false;
	dis[root]=0,q.push(make_pair(0,root));
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;vis[x]=true;
		for(int i=head[x];i!=-1;i=edge[i].next)if(dis[edge[i].to]>dis[x]+edge[i].val)dis[edge[i].to]=dis[x]+edge[i].val,q.push(make_pair(-dis[edge[i].to],edge[i].to));
	}
}
vector<int>v1,v2,occ1[2010],occ2[2010];
signed main(){
	scanf("%lld%lld",&n,&m),memset(head,-1,sizeof(head));
	scanf("%lld%lld",&S,&T);
	for(int i=1;i<=n;i++)scanf("%lld",&val[i]),SUM+=val[i];
	for(int i=1,x,y,z;i<=m;i++)scanf("%lld%lld%lld",&x,&y,&z),ae(x,y,z),ae(y,x,z);
	dijkstra(S,dis1),dijkstra(T,dis2);
	
	v1.push_back(-1);
	for(int i=1;i<=n;i++)v1.push_back(dis1[i]);
	sort(v1.begin(),v1.end()),v1.resize(unique(v1.begin(),v1.end())-v1.begin()),lim1=v1.size();
	for(int i=1;i<=n;i++)dis1[i]=lower_bound(v1.begin(),v1.end(),dis1[i])-v1.begin();
	
	v2.push_back(-1);
	for(int i=1;i<=n;i++)v2.push_back(dis2[i]);
	sort(v2.begin(),v2.end()),v2.resize(unique(v2.begin(),v2.end())-v2.begin()),lim2=v2.size();
	for(int i=1;i<=n;i++)dis2[i]=lower_bound(v2.begin(),v2.end(),dis2[i])-v2.begin();
	
	for(int i=1;i<=n;i++)occ1[dis1[i]].push_back(i),occ2[dis2[i]].push_back(i);
	
	for(int i=1;i<lim1;i++)for(int j=0;j<lim2;j++){
		cnt1[i][j]=cnt1[i-1][j],sum[i][j]=sum[i-1][j];
		for(int k=0;k<occ1[i].size();k++){
			bool ok=dis2[occ1[i][k]]>j;
			cnt1[i][j]+=ok,sum[i][j]+=ok*val[occ1[i][k]];
		}
	}
	for(int i=1;i<lim2;i++)for(int j=0;j<lim1;j++){
		cnt2[i][j]=cnt2[i-1][j];
		for(int k=0;k<occ2[i].size();k++)cnt2[i][j]+=(dis1[occ2[i][k]]>j);
	}
	
	for(int i=0;i<=n;i++)n1[i]=lim1,n2[i]=lim2,m1[i]=-inf,m2[i]=inf;
	
	for(int i=lim1-1;i>=0;i--)for(int j=lim2-1;j>=0;j--){
		while(n1[j]&&cnt1[n1[j]-1][j]>cnt1[i][j])n1[j]--,m1[j]=max(m1[j],f2[n1[j]][j]+sum[n1[j]][j]);
		f1[i][j]=(m1[j]!=-inf?m1[j]-sum[i][j]:0);
		while(n2[i]&&cnt2[n2[i]-1][i]>cnt2[j][i])n2[i]--,m2[i]=min(m2[i],f1[i][n2[i]]);
		f2[i][j]=(m2[i]!=inf?m2[i]:0);
	}
	int res=f1[0][0];
	if(res<SUM-res)puts("Cry");
	if(res==SUM-res)puts("Flowers");
	if(res>SUM-res)puts("Break a heart");
	return 0;
}