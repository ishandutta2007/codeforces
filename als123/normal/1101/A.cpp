#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int l,r,d;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&l,&r,&d);
		if (d<l) printf("%d\n",d);
		else
		{
			int t=r%d;
			r=r-t+d;
			printf("%d\n",r);
		}
	}
	return 0;
}