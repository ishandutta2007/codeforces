#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int h,w,r[1005],c[1005],a[1005][1005],i,j,ans;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d%d",&h,&w);
	for(i=1;i<=h;++i)
	{
		scanf("%d",r+i);
		for(j=1;j<=r[i];++j)
			a[i][j]=1;
		a[i][r[i]+1]=-1;
	}
	for(i=1;i<=w;++i)
	{
		scanf("%d",c+i);
		for(j=1;j<=c[i];++j)
		{
			if(a[j][i]==-1)
			{
				printf("0");
				return 0;
			}
			a[j][i]=1;
		}
		if(c[i]+1<=h&&a[c[i]+1][i]==1)
		{
			printf("0");
			return 0;
		}
		a[c[i]+1][i]=-1;
	}
	ans=1;
	for(i=1;i<=h;++i)
		for(j=1;j<=w;++j)
			if(a[i][j]==0)
				ans=ans*2%1000000007;
	printf("%d",ans);
	return 0;
}