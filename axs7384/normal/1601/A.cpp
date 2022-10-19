#include<bits/stdc++.h>
using namespace std;
int t,n,x;
int sum[100];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&x);
			for (int j=0;j<30;++j)
				if (x&(1<<j))
					++sum[j];
		}
		int ans=0;
		for (int i=0;i<30;++i)
		{
			ans=__gcd(ans,sum[i]);
			sum[i]=0;
		}
		// cout<<"!"<<ans<<endl;
		for (int i=1;i<=n;++i)
			if (ans%i==0)
				printf("%d ",i);
		puts("");
	}
	return 0;
}