#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
int t,n,a[N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		int mn=max(0,n-2);
		for (int i=1;i<=n;++i)
			for (int j=i+1;j<=n;++j)
			{
				int dx=j-i,dy=a[j]-a[i],sum=0;
				for (int k=1;k<=n;++k)
					if (k!=i&&k!=j)
					{
						int nx=k-i,ny=a[k]-a[i];
						if ((ll)dx*ny!=(ll)nx*dy)
							++sum;
					}
				mn=min(mn,sum);
			}
		cout<<mn<<endl;
	}
}