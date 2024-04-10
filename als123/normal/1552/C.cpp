#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=205;
int n,k,T;
int a[N],b[N];
int sum[N];
bool check (int x,int y)
{
	int cnt=0;
	if (a[x]>=a[y]&&a[x]<=b[y])	cnt++;
	if (b[x]>=a[y]&&b[x]<=b[y])	cnt++;
	return cnt==1;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k);n*=2;
		int nn=n-2*k;
		int ans=0;
		for (int u=1;u<=nn/2-1;u++) ans=ans+u; 
		for (int u=1;u<=n;u++) sum[u]=1;
		for (int u=1;u<=k;u++) 
		{
			scanf("%d%d",&a[u],&b[u]);
			if (a[u]>b[u]) swap(a[u],b[u]);
			sum[a[u]]=0;sum[b[u]]=0;
		}
		for (int u=1;u<=n;u++) sum[u]+=sum[u-1];
		for (int u=1;u<=k;u++)
		{
			int x=sum[b[u]]-sum[a[u]-1];
			ans=ans+min(sum[n]-x,x);
		}
		for (int u=1;u<=k;u++)
		for (int i=u+1;i<=k;i++)
		if (check(u,i)) ans++;
		printf("%d\n",ans);
	}
	return 0;
}