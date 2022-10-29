#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,i,j,k,g[10][10],col[10],w[10][10],ans;
void dfs(int x)
{
	if(x>n)
	{
		int i,j,k;
		for(i=1;i<=6;++i)
			for(j=i;j<=6;++j)
				w[i][j]=0;
		for(i=1;i<=n;++i)
			for(j=i;j<=n;++j)
				if(g[i][j])
					w[min(col[i],col[j])][max(col[i],col[j])]++;
		k=0;
		for(i=1;i<=6;++i)
			for(j=i;j<=6;++j)
				if(w[i][j])
					++k;
		ans=max(ans,k);
		return;
	}
	for(int y=1;y<=6;++y)
	{
		col[x]=y;
		dfs(x+1);
	}
}
int main()
{
	//freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&j,&k);
		g[j][k]++,g[k][j]++;
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}