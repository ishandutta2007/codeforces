#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

const int maxn=107;

using namespace std;

int n,m,sum,cnt,ans;
int a[maxn][maxn],c[maxn],d[maxn];

struct rec{
	int x,id;
}b[maxn];

bool cmp(rec a,rec b)
{
	return a.x<b.x;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	ans=m+1;
	for (int i=1;i<n;i++)
	{
		sum=0;
		for (int j=1;j<=m;j++)
		{
			b[j].x=a[j][i]-a[j][n];
			b[j].id=j;
			sum+=b[j].x;
		}
		sort(b+1,b+m+1,cmp);
		if (sum>=0) ans=0;
		else
		{
			cnt=0;
			for (int j=1;j<=m;j++)
			{
				sum-=b[j].x;
				c[++cnt]=b[j].id;
				if (sum>=0) break;
			}
			if (cnt<ans)
			{
				ans=cnt;
				for (int j=1;j<=cnt;j++) d[j]=c[j];
			}
		}
	}
	printf("%d\n",ans);
	for (int i=1;i<=ans;i++) printf("%d ",d[i]);
}