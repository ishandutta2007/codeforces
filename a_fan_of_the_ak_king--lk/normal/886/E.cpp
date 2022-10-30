#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
int n,i,k;
long long p[1000005],inv[1000005],f[1000005],s[1000005],ans;
int main()
{
	scanf("%d %d",&n,&k);
	p[0]=inv[1]=inv[0]=1;
	for(i=2;i<=n;i++)
		inv[i]=inv[M%i]*(M-M/i)%M;
	for(i=1;i<=n;i++)
	{
		p[i]=p[i-1]*i%M;
		inv[i]=inv[i-1]*inv[i]%M;
	}
	for(i=k+1;i<=n;i++)
	{
		f[i]=(s[i-1]-s[i-k-1]+i-k)*p[i-1]%M;
		s[i]=(s[i-1]+f[i]*inv[i])%M;
	}
	for(i=n;i>=1;i--)
		ans=(ans+f[i-1]*p[n-1]%M*inv[i-1])%M;
	cout<<(ans%M+M)%M;
}