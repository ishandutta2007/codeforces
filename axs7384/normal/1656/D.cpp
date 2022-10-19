#include<bits/stdc++.h>
using namespace std;
long long n,x;
int t;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%lld",&n);
		n<<=1;
		x=1;
		while (n%2==0)
		{
			x<<=1;
			n>>=1;
		}
		if (n==1)
			puts("-1");
		else
			printf("%lld\n",min(n,x));
	}
	return 0;
}