#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=1005;

int n,k,a[N];

int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	{
		int x;scanf("%d",&x);
		a[x]++;
	}
	int ans=0;
	for (int i=1;i<=k;i++) ans+=a[i]/2*2;
	ans+=(n-ans+1)/2;
	printf("%d\n",ans);
	return 0;
}