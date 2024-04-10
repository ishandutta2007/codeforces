#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int a[105],b[105],vis[105],n,i,ans,sum,x;
void dfs(int x)
{
	vis[x]=1;
	++sum;
	if (vis[a[x]]==0)
		dfs(a[x]);
}
int gcd(int x,int y)
{
	return x%y==0?y:gcd(y,x%y);
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		++b[a[i]];
		if (b[a[i]]>1)
		{
			putchar('-');
			putchar('1');
			return 0;
		}
	}
	dfs(1);
	if (sum%2==0) 
		sum/=2;
	ans=sum;
	for (i=2;i<=n;++i)
		if (vis[i]==0)
		{
			sum=0;
			dfs(i);
			if (sum%2==0)
				sum/=2;
			x=gcd(ans,sum);
			ans=ans/x*sum;
		}
	printf("%d",ans);
	return 0;
}