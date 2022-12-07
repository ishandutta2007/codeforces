#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=405;
char ss[N][N];
int n,m;
int a[N][N];
int b[N][N];
int c[N];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&m);
		for (int u=1;u<=n;u++) scanf("%s",ss[u]+1);
		for (int u=1;u<=m;u++)
		{
			for (int i=1;i<=n;i++)
			{
				a[u][i]=a[u][i-1];
				b[u][i]=b[u][i-1];
				if (ss[i][u]=='0') a[u][i]++;
				else b[u][i]++;
			}
		}
		int ans=n*m;
		for (int u=1;u<=n;u++)
		for (int i=u+4;i<=n;i++)
		{
			int mx=-1e9+7;
			int sum=0;
			for (int j=1;j<=m;j++)
			{
				if (j-3>=1) mx=max(mx,c[j-3]);
				int t1=a[j][i-1]-a[j][u];
				int t2=b[j][i-1]-b[j][u];
				t2=t2+(ss[u][j]=='0')+(ss[i][j]=='0');
			//	printf("%d %d %d %d %d %d\n",u,i,j,t1,t2,sum);
				ans=min(ans,t1+sum-mx);
				sum=sum+t2;c[j]=sum-t1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}