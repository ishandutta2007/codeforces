#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100005;
int a[N],f[100],t,n;
ll k;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		scanf("%lld",&k);
		--k;
		// cout<<"!"<<n<<' '<<k<<' '<<(1LL<<(n-1))<<endl;
		if (n<=60&&(1LL<<(n-1))<=k)
		{
			puts("-1");
			continue;
		}
		for (int i=0;i<=60;++i)
			if ((1LL<<i)&k)
				f[i]=1;
			else
				f[i]=0;
		for (int i=1;i<=n;++i)
			a[i]=i;
		for (int i=0;i<=60;++i)
			if (f[i]==1&&(i==0||f[i-1]==0))
			{
				int l,r=n-i;
				for (int j=i;j<=60;++j)
					if (f[j+1]==0)
					{
						l=n-j-1;
						break;
					}
				// cout<<l<<' '<<r<<endl;
				while (l<r)
				{
					swap(a[l],a[r]);
					++l;
					--r;
				}
			}
		for (int i=1;i<=n;++i)
			printf("%d ",a[i]);
		puts("");
	}
	return 0;
}