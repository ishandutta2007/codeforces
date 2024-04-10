#include<bits/stdc++.h>
using namespace std;
int a[2020202];
int main()
{
	int n,r;
	scanf("%d%d",&n,&r);
	long long sum=0;
	for(int i=0;i<(1<<n);i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	printf("%.8f\n",1.0*sum/(1<<n));
	while(r--)
	{
		int z,g;
		scanf("%d%d",&z,&g);
		sum-=a[z];
		sum+=g;
		a[z]=g;
		printf("%.8f\n",1.0*sum/(1<<n));
	}
	return 0;
}