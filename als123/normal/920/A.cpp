#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=205;
int T;
int n,k;
int a[N];
bool check (int x)
{
	int r=1;
	for (int u=1;u<=k;u++)
	{
		if (a[u]-x+1>r) return false;
		r=a[u]+x;
	}
	return r>n;
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k);
		for (int u=1;u<=k;u++)
			scanf("%d",&a[u]);
		int l=1,r=n;
		int ans=-1;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (check(mid)) {ans=mid;r=mid-1;}
			else l=mid+1;
		}
		printf("%d\n",ans);
	}
	return 0;
}