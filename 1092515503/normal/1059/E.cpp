#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,L,S,val[100100],len[100100],anc[100100][20],sum[100100],dep[100100],f[100100],g[100100];
vector<int>v[100100];
void dfs1(int x){
	for(int i=1;(1<<i)<=dep[x];i++)anc[x][i]=anc[anc[x][i-1]][i-1];
	for(int i=19,y=x;i>=0;i--){
		if(!anc[y][i])continue;
		if(sum[x]-sum[anc[y][i]]+val[anc[y][i]]>S)continue;
		if(dep[x]-dep[anc[y][i]]>=L)continue;
		len[x]+=(1<<i),y=anc[y][i];
	}
	for(auto y:v[x])anc[y][0]=x,dep[y]=dep[x]+1,sum[y]=sum[x]+val[y],dfs1(y);
}
void dfs2(int x){
	for(auto y:v[x])dfs2(y),f[x]=max(f[x],f[y]),g[x]+=g[y];
	f[x]--;
	if(f[x]==-1)f[x]=len[x],g[x]++;
}
signed main(){
	scanf("%lld%lld%lld",&n,&L,&S);
	for(int i=1;i<=n;i++){
		scanf("%lld",&val[i]);
		if(val[i]>S){puts("-1");return 0;}
	}
	for(int i=2,x;i<=n;i++)scanf("%lld",&x),v[x].push_back(i);
	dep[1]=1,sum[1]=val[1],dfs1(1),dfs2(1);
//	for(int i=1;i<=n;i++)printf("%lld ",len[i]);puts("");
	printf("%lld\n",g[1]);
	return 0;
} 
/*
6 3 5
2 1 4 3 5 2
1 2 3 2 3

8 4 9
1 3 2 4 2 4 3 5
1 1 2 1 3 4 6
*/