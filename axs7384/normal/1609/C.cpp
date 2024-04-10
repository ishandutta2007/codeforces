#include<bits/stdc++.h>
using namespace std;
const int N=10000005;
int b[N],pr[N],cnt;
int a[N],f[N];
int t,n,m;
inline void prework()
{
	int n=1000000;

	// int n=100;
	b[1]=1;
	for (int i=2;i<n;++i)
	{
		if (!b[i])
		{
			// cout<<i<<' ';
			pr[++cnt]=i;
		}
		for (int j=1;j<=cnt&&pr[j]*i<=n;++j)
		{
			b[i*pr[j]]=1;
			if (i%pr[j]==0)
				break;
		}
	}
}
int main()
{
	prework();
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&m);
		for (int i=1,x;i<=n;++i)
		{
			scanf("%d",&x);
			if (x==1)
			{
				a[i]=0;
			}
			else
			{
				if (b[x])
					a[i]=2;
				else
					a[i]=1;
			}
		}
		// cout<<endl;
		for (int i=1;i<=n;++i)
		{
			if (i<=m)
				f[i]=a[i];
			else
				f[i]=a[i]+f[i-m];
			// cout<<f[i]<<' ';
		}
		// cout<<endl;
		long long ans=0;
		for (int i=1;i<=n;++i)
		{
			if (a[i]==2)
				continue;
			int l=0,r=(n-i)/m;
			while (l<=r)
			{
				int mid=(l+r)/2;
				int sum=f[mid*m+i]-f[i]+a[i];
				if (sum<=1)
					l=mid+1;
				else
					r=mid-1;
			}
			int R=r;
			l=0,r=(n-i)/m;
			while (l<=r)
			{
				int mid=(l+r)/2;
				int sum=f[mid*m+i]-f[i]+a[i];
				if (sum>=1)
					r=mid-1;
				else
					l=mid+1;
			}
			int L=l;
			if (L==0)
				++L;
			// cout<<"!"<<i<<' '<<L<<' '<<R<<endl;
			ans+=max(0,R-L+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}