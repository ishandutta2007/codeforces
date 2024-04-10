#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const int N=400005;

int n,k,a[N],b[N],c[N];

bool check(int l)
{
	int tot=0;
	for (int i=1;i<=n;i++) b[++tot]=a[i]-l,b[++tot]=a[i]+l+1;
	std::sort(b+1,b+tot+1);
	tot=std::unique(b+1,b+tot+1)-b-1;
	for (int i=1;i<=tot;i++) c[i]=0;
	for (int i=1;i<=n;i++)
	{
		int x=std::lower_bound(b+1,b+tot+1,a[i]-l)-b;
		int y=std::lower_bound(b+1,b+tot+1,a[i]+l+1)-b;
		c[x]++;c[y]--;
	}
	for (int i=1;i<=tot;i++)
	{
		c[i]+=c[i-1];
		if (c[i]>=k+1) return 1;
	}
	return 0;
}

void pri(int l)
{
	int tot=0;
	for (int i=1;i<=n;i++) b[++tot]=a[i]-l,b[++tot]=a[i]+l+1;
	std::sort(b+1,b+tot+1);
	tot=std::unique(b+1,b+tot+1)-b-1;
	for (int i=1;i<=tot;i++) c[i]=0;
	for (int i=1;i<=n;i++)
	{
		int x=std::lower_bound(b+1,b+tot+1,a[i]-l)-b;
		int y=std::lower_bound(b+1,b+tot+1,a[i]+l+1)-b;
		c[x]++;c[y]--;
	}
	for (int i=1;i<=tot;i++)
	{
		c[i]+=c[i-1];
		if (c[i]>=k+1) {printf("%d\n",b[i]);return;}
	}
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d",&n,&k);
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		int l=0,r=1e9;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (check(mid)) r=mid-1;
			else l=mid+1;
		}
		pri(r+1); 
	}
	return 0;
}