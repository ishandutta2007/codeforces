#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		if (n%2==0)
		{
			printf("%d %d 1\n",n/2,n/2-1,1);
		}
		else
		{
			if (n%4==1)
				printf("%d %d 1\n",n/2-1,n/2+1,1);
			else
				printf("%d %d 1\n",n/2-2,n/2+2,1);
		}
	}
	return 0;
}