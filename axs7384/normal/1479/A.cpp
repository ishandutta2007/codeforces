#include<bits/stdc++.h>
using namespace std;
inline void read(int &x)
{
	char c=getchar();
	x=0;
	int y=1;
	while (c>'9'||c<'0')
	{
		if (c=='-')
			y=-1;
		c=getchar();
	}
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	x*=y;
}
int n,a[100005];
inline void work(int x)
{
	if (!a[x])
	{
		printf("? %d\n",x);
		fflush(stdout);
		read(a[x]);
	}
}
int main()
{
	read(n);
	int l=1,r=n;
	a[0]=a[n+1]=n+1;
	while (l<=r)
	{
		int mid=(l+r)/2;
		work(mid-1);
		work(mid+1);
		work(mid);
		if (a[mid]<a[mid+1]&&a[mid]<a[mid-1])
		{
			printf("! %d\n",mid);
			fflush(stdout);
			return 0;
		}
		else
		{
			if (a[mid]>a[mid-1])
				r=mid;
			else
				l=mid+1;
		}
	}
	return 0;
}