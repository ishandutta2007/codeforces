#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

long long n;
int a[105],b[105];

int main()
{
	scanf("%lld",&n);
	int tot=0;
	while (n) a[++tot]=n%10,n/=10;
	for (int i=2;i<=tot;i++)
	{
		while (a[i-1]+b[i-1]+10<=18)
		{
			a[i]--;
			int x=10;
			int w=std::min(x,9-b[i-1]);
			b[i-1]+=w;x-=w;
			a[i-1]+=x;
		}
	}
	int ans=0;
	for (int i=1;i<=tot;i++) ans+=a[i]+b[i];
	printf("%d\n",ans);
	return 0;
}