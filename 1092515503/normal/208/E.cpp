#include<bits/stdc++.h>
using namespace std;
int n,m,anc[100100][20],tot,dep[100100],l[100100],r[100100];
vector<int>v[100100],u[100100];
void dfs(int x){
	l[x]=++tot;
	u[dep[x]].push_back(tot);
	for(auto y:v[x])dep[y]=dep[x]+1,dfs(y);
	r[x]=tot;
}
int query(int x,int p){
	int d=dep[x];
	if(p>=d)return 0;
	for(int i=19;i>=0;i--)if(p>=(1<<i))p-=(1<<i),x=anc[x][i];
	return upper_bound(u[d].begin(),u[d].end(),r[x])-lower_bound(u[d].begin(),u[d].end(),l[x])-1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&anc[i][0]),v[anc[i][0]].push_back(i);
	for(int j=1;j<20;j++)for(int i=1;i<=n;i++)anc[i][j]=anc[anc[i][j-1]][j-1];
	dfs(0);
//	for(int i=0;i<=2;i++){for(auto j:u[i])printf("%d ",j);puts("");}
	scanf("%d",&m);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),printf("%d\n",query(x,y));
	return 0;
}