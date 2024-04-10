#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,i,j,a[50][50],w[50][50],ans;
void dfs(int x)
{
	if(x>m)
	{
		int dzx=0;
		for(int i=1;i<m;++i)
			w[i+m][m]=w[i][m]*w[m][m];
		for(int i=1;i<=n;++i)
			dzx+=a[i][m]*w[i][m];
		for(int i=1;i<m;++i)
		{
			w[m][i]=1;
			w[m][i+m]=w[m][i]*w[m][m];
			int X=a[m][i]*w[m][i]+a[m][i+m]*w[m][i+m];
			for(int j=1;j<m;++j)
			{
				w[j][i]=1;
				w[j][i+m]=w[j][i]*w[j][m];
				w[j+m][i]=w[j][i]*w[m][i];
				w[j+m][i+m]=w[j+m][i]*w[j+m][m];
				int x=a[j][i]*w[j][i]+a[j+m][i]*w[j+m][i]+a[j][i+m]*w[j][i+m]+a[j+m][i+m]*w[j+m][i+m];
				w[j][i]=-1;
				w[j][i+m]=w[j][i]*w[j][m];
				w[j+m][i]=w[j][i]*w[m][i];
				w[j+m][i+m]=w[j+m][i]*w[j+m][m];
				int y=a[j][i]*w[j][i]+a[j+m][i]*w[j+m][i]+a[j][i+m]*w[j][i+m]+a[j+m][i+m]*w[j+m][i+m];
				X+=max(x,y);
			}
			w[m][i]=-1;
			w[m][i+m]=w[m][i]*w[m][m];
			int Y=a[m][i]*w[m][i]+a[m][i+m]*w[m][i+m];
			for(int j=1;j<m;++j)
			{
				w[j][i]=1;
				w[j][i+m]=w[j][i]*w[j][m];
				w[j+m][i]=w[j][i]*w[m][i];
				w[j+m][i+m]=w[j+m][i]*w[j+m][m];
				int x=a[j][i]*w[j][i]+a[j+m][i]*w[j+m][i]+a[j][i+m]*w[j][i+m]+a[j+m][i+m]*w[j+m][i+m];
				w[j][i]=-1;
				w[j][i+m]=w[j][i]*w[j][m];
				w[j+m][i]=w[j][i]*w[m][i];
				w[j+m][i+m]=w[j+m][i]*w[j+m][m];
				int y=a[j][i]*w[j][i]+a[j+m][i]*w[j+m][i]+a[j][i+m]*w[j][i+m]+a[j+m][i+m]*w[j+m][i+m];
				Y+=max(x,y);
			}
			dzx+=max(X,Y);
		}
		ans=max(ans,dzx);
		return;
	}
	w[x][m]=1;
	dfs(x+1);
	w[x][m]=-1;
	dfs(x+1);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			scanf("%d",a[i]+j);
	m=(n+1)/2;
	ans=-(1<<30);
	dfs(1);
	printf("%d",ans);
	return 0;
}