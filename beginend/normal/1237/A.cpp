#include<bits/stdc++.h>

int main()
{
	int n;
	scanf("%d",&n);
	int now=0;
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		if (x%2==0) printf("%d\n",x/2);
		else if (!now) printf("%d\n",(x+1)/2),now^=1;
		else printf("%d\n",(x-1)/2),now^=1;
	}
	return 0;
}