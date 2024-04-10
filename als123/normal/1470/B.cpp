#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int N=1000005;
int T;
int n,q;
int a[N];
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int u=1;u<=n;u++) 
		{
			scanf("%d",&a[u]);
			while (a[u]%4==0) a[u]/=4;
			for (int i=3;i*i<=a[u];i+=2)
			{
				int j=i*i;
				while (a[u]%j==0) a[u]/=j;
			}
		}
		sort(a+1,a+1+n);
	//	for (int u=1;u<=n;u++) printf("%d ",a[u]);printf("\n");
		int r;
		int mx=0,sum=0;
		for (int l=1;l<=n;l=r+1)
		{
			r=l;
			while (r+1<=n&&a[r+1]==a[l]) r++;
			if (a[l]==1||(r-l+1)%2==0) sum=sum+(r-l+1);
			mx=max(mx,r-l+1);
		}
		scanf("%d",&q);
		while (q--)
		{
			int x;
			scanf("%d",&x);
			if (x==0) printf("%d\n",mx);
			else printf("%d\n",max(sum,mx));
		}
	}
	return 0;
}