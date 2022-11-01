#include<bits/stdc++.h>

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		int a[3];scanf("%d%d%d",&a[0],&a[1],&a[2]);
		std::sort(a,a+3);
		if (a[2]<=a[0]+a[1]) printf("%d\n",(a[0]+a[1]+a[2])/2);
		else printf("%d\n",a[0]+a[1]);
	}
	return 0;
}