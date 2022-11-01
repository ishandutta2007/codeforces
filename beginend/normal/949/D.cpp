#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;

const int N=100005;

int n;
LL a[N],tmp[N],b,d;

bool check(int mid)
{
	int p1=1,p2=n;LL s1=0,s2=0;
	for (int i=mid+1;i<=n/2;i++)
	{
		if (a[i]>=b) a[i]-=b;
		else
		{
			LL ret=b-a[i];a[i]=0;
			while (p1<=n&&p1-i<=(LL)d*i)
			{
				LL w=min(ret,a[p1]);
				ret-=w;a[p1]-=w;
				if (!ret) break;
				p1++;
			}
			if (ret) return 0;
		}
	}
	for (int i=n-mid;i>(n+1)/2;i--)
	{
		if (a[i]>=b) a[i]-=b;
		else
		{
			LL ret=b-a[i];a[i]=0;
			while (p2>=1&&i-p2<=(LL)d*(n-i+1))
			{
				LL w=min(ret,a[p2]);
				ret-=w;a[p2]-=w;
				if (!ret) break;
				p2--;
			}
			if (ret) return 0;
		}
	}
	return 1;
}

int main()
{
	scanf("%d%I64d%I64d",&n,&d,&b);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]),tmp[i]=a[i];
	int l=0,r=n/2;
	while (l<=r)
	{
		int mid=(l+r)/2;
		for (int i=1;i<=n;i++) a[i]=tmp[i];
		if (check(mid)) r=mid-1;
		else l=mid+1;
	}
	printf("%d",r+1);
	return 0;
}