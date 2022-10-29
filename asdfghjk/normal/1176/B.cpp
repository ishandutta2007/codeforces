#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int q,n,i,a[105],x,y,z,ans;
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&n);
		x=y=z=0;
		for(i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			if(a[i]%3==0)
				++x;
			else if(a[i]%3==1)
				++y;
			else
				++z;
		}
		ans=x;
		if(y>=z)
		{
			ans+=z;
			y-=z;
			ans+=y/3;
		}
		else
		{
			ans+=y;
			z-=y;
			ans+=z/3;
		}
		printf("%d\n",ans);
	}
	return 0;
}