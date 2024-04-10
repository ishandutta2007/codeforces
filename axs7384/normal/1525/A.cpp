#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		printf("%d\n",100/__gcd(100,n));
	}
	return 0;
}