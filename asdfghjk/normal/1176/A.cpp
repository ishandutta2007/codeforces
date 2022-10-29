#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int q,i,j,k,ans;
long long a;
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%I64d",&a);
		i=j=k=0;
		while(a%2==0)
			a/=2,++i;
		while(a%3==0)
			a/=3,++j;
		while(a%5==0)
			a/=5,++k;
		if(a>1)
		{
			puts("-1");
			continue;
		}
		ans=j+k;
		i+=j+k*2;
		ans+=i;
		printf("%d\n",ans);
	}
	return 0;
}