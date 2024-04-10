#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005],g[25][200005];
long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
int main()
{
	int T=1;
	cin>>T;
	while(T--)
	{
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]),b[i-1]=a[i]-a[i-1];
		for(int i=1;i<n;i++)g[0][i]=b[i];
		for(int i=1;i<=20;i++)for(int j=1;j<n;j++)
			g[i][j]=gcd(g[i-1][j],g[i-1][j+(1<<i-1)]);
		for(int i=1;i<n;i++)
		{
			int len=n-i;
			long long he=0;
			for(int j=20;j>=0;j--)if(len>=(1<<j))
			{
				long long dd=gcd(he,g[j][n-len]);
				if(abs(dd)==1)continue;
				len-=1<<j,he=dd;
			}
			ans=max(ans,n-len-i);
		}
		cout<<ans+1<<endl;
	}
	return 0;
}