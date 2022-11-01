#include<bits/stdc++.h>

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		int a,b;scanf("%d%d",&a,&b);
		int d=a>b?a-b:b-a;
		int i;
		for (i=0;i*(i+1)/2<d||(i*(i+1)/2+d)%2==1;i++);
		printf("%d\n",i);
	}
	return 0;
}