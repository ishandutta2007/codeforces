#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int vist[1005][1005],a[1005][1005],sz[1000005];
int n,m,mb[4][2]={{0,-1},{1,0},{0,1},{-1,0}},S=0;
void dfs(int x,int y)
{
	vist[x][y]=1,S++;
	for(int i=0;i<4;i++)if(!(a[x][y]&(1<<i)))
	{
		int dx=x+mb[i][0],dy=y+mb[i][1];
		if(dx<=0||dy<=0||dx>n||dy>m)continue;
		if(!vist[dx][dy])dfs(dx,dy);
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
		scanf("%d",&a[i][j]);
	int k=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(!vist[i][j])
	{
		int aa=S;
		dfs(i,j);
		sz[++k]=S-aa;
	}
	sort(sz+1,sz+k+1,greater<int>());
	for(int i=1;i<=k;i++)printf("%d ",sz[i]);
	return 0;
}