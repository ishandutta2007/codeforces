#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,p,w,i,j,k;
int main()
{
	scanf("%I64d%I64d",&n,&p);
	for(i=1;;++i)
	{
		w=n-i*p;
		if(w<i&&p>=0)
		{
			printf("-1");
			return 0;
		}
		if(w>=i)
		{
			for(j=k=0;(1ll<<j)<=w;++j)
				if(w>>j&1)
					++k;
			if(k<=i)
			{
				printf("%I64d",i);
				return 0;
			}
		}
	}
	printf("-1");
	return 0;
}