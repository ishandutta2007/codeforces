#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
const int N=105;
int a[N];
int main()
{
	int n,d;
	scanf("%d%d",&n,&d);
	for (int u=1;u<=n;u++) scanf("%d",&a[u]);
	int ans=n;
	for (int u=1;u<=n;u++)// 
	{
		int mx=a[u]+d;
		int cnt=0;
		for (int i=1;i<=n;i++)
		{
			if (a[i]<a[u]||a[i]>mx)	cnt++;
		}
		ans=min(ans,cnt);
	}
	printf("%d\n",ans);
	return 0;
}