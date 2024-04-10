#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	int l,r,n,c[30],i;
	scanf("%d%d",&l,&r);
	for(n=l;n<=r;++n)
	{
		for(i=0;i<10;++i)
			c[i]=0;
		for(i=n;i;i/=10)
			c[i%10]++;
		for(i=0;i<10;++i)
			if(c[i]>1)
				break;
		if(i>=10)
		{
			printf("%d",n);
			return 0;
		}
	}
	printf("-1");
	return 0;
}