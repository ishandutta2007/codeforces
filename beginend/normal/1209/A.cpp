#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=105;

int n,a[N];
bool vis[N];

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	std::sort(a+1,a+n+1);
	int ans=0;
	for (int i=1;i<=n;i++)
		if (!vis[i])
		{
			ans++;
			for (int j=i;j<=n;j++)
				if (!vis[j]&&a[j]%a[i]==0) vis[j]=1;
		}
	printf("%d\n",ans);
	return 0;
}