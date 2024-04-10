#include<bits/stdc++.h>
using namespace std;
int a[5005];
long long g[5005][5005],f[5005];
int main()
{
	int n,k,q;
	cin>>n>>k>>q;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),g[i][0]=1;
	for(int i=1;i<=k;i++)
	{
		g[1][i]=g[2][i-1],g[n][i]=g[n-1][i-1];
		for(int j=2;j<=n-1;j++)g[j][i]=(g[j-1][i-1]+g[j+1][i-1])%1000000007;
	}
	for(int i=1;i<=n;i++)for(int j=0;j<=k;j++)
		f[i]=(f[i]+g[i][j]*g[i][k-j])%1000000007;
	long long ans=0;
	for(int i=1;i<=n;i++)ans=(ans+a[i]*f[i])%1000000007;
	for(int i=1;i<=q;i++)
	{
		int p,x;
		scanf("%d%d",&p,&x);
		ans+=f[p]*(x-a[p]);
		ans%=1000000007;
		ans+=1000000007;
		ans%=1000000007;
		a[p]=x;
		printf("%lld\n",ans);
	}
	return 0;
}