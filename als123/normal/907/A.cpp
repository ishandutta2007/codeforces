#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int a,b,c,d;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for (int u=a;u<=2*a;u++)//
		for (int i=b;i<=2*b;i++)
			for (int j=c;j<=2*c;j++)
			{
				if (u<=i) continue;
				if (i<=j) continue;
				if (d<=u&&2*d<u&&d<=i&&2*d<i&&d<=j&&2*d>=j)
				{
					printf("%d\n%d\n%d\n",u,i,j);
					return 0;
				}
			}
	printf("-1");
	return 0;
}