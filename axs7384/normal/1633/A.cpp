#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		if (n%7<=n%10)
			printf("%d\n",n-n%7);
		else
			printf("%d\n",n-n%7+7);
	}
	return 0;
}