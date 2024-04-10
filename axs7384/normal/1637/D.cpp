#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=10005;
int a[N],b[N];
int t,n;
int f[105][N];
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		int sum=0;
		ll ans=0;
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			ans+=a[i]*a[i];
			sum+=a[i];
		}
		for (int i=1;i<=n;++i)
		{
			scanf("%d",&b[i]);
			ans+=b[i]*b[i];
			sum+=b[i];
		}
		ans*=(n-2);
		for (int i=0;i<=n;++i)
			for (int j=0;j<=sum;++j)
				f[i][j]=0;
		f[0][0]=1;
		for (int i=1;i<=n;++i)
			for (int j=1;j<=sum;++j)
				if ((j>=a[i]&&f[i-1][j-a[i]])||(j>=b[i]&&f[i-1][j-b[i]]))
					f[i][j]=1;
		ll mn=(ll)sum*sum;
		for (int j=1;j<sum;++j)
			if (f[n][j])
				mn=min(mn,(ll)j*j+(ll)(sum-j)*(sum-j));
		cout<<ans+mn<<endl;
	}
	return 0;
}