#include<bits/stdc++.h>

typedef long long LL;

const int N=200005;

int n,d[N],id[N];
LL p[N],k;

bool cmp(int x,int y)
{
	return d[x]>d[y];
}

bool check(int t)
{
	for (int i=1;i<=t;i++) id[i]=i;
	std::sort(id+1,id+t+1,cmp);
	LL sum=0;
	for (int i=1;i<=t;i++)
	{
		sum+=(LL)p[n-i+1]/100*d[id[i]];
	}
	return sum>=k;
}

int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%lld",&p[i]),d[i]=0;
		int x,a,y,b;
		scanf("%d%d%d%d",&x,&a,&y,&b);
		for (int i=a;i<=n;i+=a) d[i]+=x;
		for (int i=b;i<=n;i+=b) d[i]+=y;
		std::sort(p+1,p+n+1);
		scanf("%lld",&k);
		int l=1,r=n;
		while (l<=r)
		{
			int mid=(l+r)/2;
			if (check(mid)) r=mid-1;
			else l=mid+1;
		}
		if (check(r+1)) printf("%d\n",r+1);
		else puts("-1");
	}
	return 0;
}