#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int n,m;

int gcd(int x,int y)
{
	if (!y) return x;
	else return gcd(y,x%y);
}

int main()
{
	scanf("%d%d",&n,&m);
	int ans=m;
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		ans=gcd(ans,x);
	}
	printf("%d\n",m/ans);
	for (int i=1,j=0;i<=m/ans;i++,j+=ans) printf("%d ",j);
	return 0;
}