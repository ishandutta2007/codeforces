#include<bits/stdc++.h>
using namespace std;
int n,a[100];
__int128 f[100];
int t;
inline void write(__int128 x)
{
	if (x>=10)
		write(x/10);
	putchar('0'+x%10);
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		__int128 ans=0;
		// cout<<"!"<<n<<endl;
		for (int i=1;i<=n;++i)
		{
			// cout<<">>"<<i<<endl;
			scanf("%d",&a[i]);
		}
		for (int i=1;i<=n;++i)
		{
			// cout<<i<<endl;
			for (int j=1;j<=n;++j)
				f[j]=a[j];
			for (int j=1;j<=n;++j)
				if (j!=i)
				{
					while (f[j]%2==0)
					{
						// cout<<i<<' '<<j<<' '<<(int)f[i]<<' '<<(int)f[j]<<endl;
						f[j]/=2;
						f[i]*=2;
					}
				}
			__int128 sum=0;
			for (int j=1;j<=n;++j)
				sum+=f[j];
			ans=max(ans,sum);
		}
		// cout<<"??"<<(long long)ans<<endl;
		write(ans);
		putchar('\n');
	}
	return 0;
}