#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int n,head[201000],t1,t2,num[200100],cnt,ans;
struct node{
	int next,to;
}edge[201000];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
}
vector<int>low[200100],high[200100];
void dfs(int x,int fa){
	low[x].pb(num[x]),high[x].pb(num[x]);
	for(int i=head[x];i!=-1;i=edge[i].next){
		int y=edge[i].to,k;
		if(y==fa)continue;
		dfs(y,x);
		k=upper_bound(low[y].begin(),low[y].end(),num[x]-1)-low[y].begin();
		if(k==low[y].size())low[y].pb(num[x]);
		else low[y][k]=num[x];
		k=upper_bound(high[y].begin(),high[y].end(),num[x]+1,greater<int>())-high[y].begin();
		if(k==high[y].size())high[y].pb(num[x]);
		else high[y][k]=num[x];
		for(int j=0;j<low[y].size();j++)k=(upper_bound(high[x].begin(),high[x].end(),low[y][j]+1,greater<int>())-high[x].begin())+j+1,ans=max(ans,k);
		for(int j=0;j<high[y].size();j++)k=(upper_bound(low[x].begin(),low[x].end(),high[y][j]-1)-low[x].begin())+j+1,ans=max(ans,k);
		for(int j=0;j<high[x].size()||j<high[y].size();j++){
			if(j<high[x].size()&&j<high[y].size())high[x][j]=max(high[x][j],high[y][j]);
			else if(j<high[y].size())high[x].pb(high[y][j]);
		}
		for(int j=0;j<low[x].size()||j<low[y].size();j++){
			if(j<low[x].size()&&j<low[y].size())low[x][j]=min(low[x][j],low[y][j]);
			else if(j<low[y].size())low[x].pb(low[y][j]);
		}
	}
}
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)scanf("%d",&num[i]);
	for(int i=1;i<n;i++)scanf("%d%d",&t1,&t2),ae(t1,t2),ae(t2,t1);
	dfs(1,-1),printf("%d\n",ans);
	return 0;
}