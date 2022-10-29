#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,i,j,x,y,l,ans[1005][1005];
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&n);
	for(i=1,j=n;i<j;++i,--j)
	{
		for(x=1,y=n;x<y;++x,--y)
		{
			ans[x][i]=l++;
			ans[x][j]=l++;
			ans[y][i]=l++;
			ans[y][j]=l++;
		}
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
			printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}