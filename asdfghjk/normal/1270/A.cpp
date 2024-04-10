#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int t,n,k1,k2,i,j,x,y;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&k1,&k2);
		x=y=0;
		for(i=1;i<=k1;++i)
		{
			scanf("%d",&j);
			x=max(x,j);
		}
		for(i=1;i<=k2;++i)
		{
			scanf("%d",&j);
			y=max(y,j);
		}
		if(x>y)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}