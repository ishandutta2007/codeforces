#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	scanf("%lld",&n);
	if (n<=36LL)
	{
		if (n%2==1)
			putchar('4');
		for (int i=1;i<=n/2;++i)
			putchar('8');
	}
	else
		puts("-1");
	return 0;
}