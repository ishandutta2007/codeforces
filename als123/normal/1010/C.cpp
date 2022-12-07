#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int n,k;
int gcd (int x,int y)
{
	return x==0?y:gcd(y%x,x);
}
int main()
{
	scanf("%d%d",&n,&k);
	int ans=k;
	for (int u=1;u<=n;u++)
	{
		int x;
		scanf("%d",&x);
		ans=gcd(ans,x);
	}
	printf("%d\n",k/ans);
	for (int u=0;u<k;u+=ans)
		printf("%d ",u);
	return 0;
}