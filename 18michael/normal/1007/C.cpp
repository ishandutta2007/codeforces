#include<bits/stdc++.h>
#define LL long long
using namespace std;
int c;
LL a=1,b=1,ta=1,tb=1,n;
int main()
{
	for(scanf("%lld",&n);;)
	{
		printf("%lld %lld\n",a,b),fflush(stdout),scanf("%d",&c);
		if(!c)break;
		if(c==1)
		{
			while(a+ta>n)ta>>=1;
			a+=ta,ta<<=1;
		}
		else if(c==2)
		{
			while(b+tb>n)tb>>=1;
			b+=tb,tb<<=1;
		}
		else
		{
			if(ta>1)a-=(ta>>2),ta>>=1;
			if(tb>1)b-=(tb>>2),tb>>=1;
		}
	}
	return 0;
}