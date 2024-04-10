#include<cstdio>
using namespace std;
int lm=1e8,rm=1e8,ls=-1e8,rs=-1e8,n,a,b;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		if(a<lm||(a==lm&&b<rm))lm=a,rm=b;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a,&b);
		if(a>ls||(a==ls&&b>rs))ls=a,rs=b;
	}
	printf("%d %d\n",lm+ls,rm+rs);
}