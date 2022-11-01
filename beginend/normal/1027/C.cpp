#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

const double inf=2e9;

const int N=1000005;

int a[N],b[N],t[N],n; 

double get(int x,int y)
{
	return (double)(x+y)*(x+y)*4/(x*y);
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);int tmp=n;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),t[a[i]]++,b[i]=a[i];
		std::sort(a+1,a+n+1);
		n=std::unique(a+1,a+n+1)-a-1;
		bool flag=0;
		for (int i=1;i<=n;i++)
			if (t[a[i]]>=4) {printf("%d %d %d %d\n",a[i],a[i],a[i],a[i]);flag=1;break;}
		if (flag)
		{
			for (int i=1;i<=tmp;i++) t[b[i]]=0;
			continue;
		}
		int m=n;
		for (int i=1;i<=n;i++) if (t[a[i]]<2) m--,a[i]=100000;
		std::sort(a+1,a+n+1);
		n=m;
		double ans=inf;int p,q;
		for (int i=1;i<n;i++)
		{
			int l=i+1,r=n-1;
			while (l<=r)
			{
				int mid=(l+r)/2;
				if (get(a[i],a[mid])<get(a[i],a[mid+1])) r=mid-1;
				else l=mid+1;
			}
			double w=get(a[i],a[r+1]);
			if (w<ans) ans=w,p=a[i],q=a[r+1];
		}
		printf("%d %d %d %d\n",p,p,q,q);
		for (int i=1;i<=tmp;i++) t[b[i]]=0;
	}
	return 0;
}