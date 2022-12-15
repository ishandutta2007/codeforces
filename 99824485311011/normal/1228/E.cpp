#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000000007;
inline int add(int a,int b)
{
	if((a+=b)>=mod)a-=mod;
	return a;
}
inline int mult(int a,int b)
{
	long long t=1ll*a*b;
	if(t>=mod)t%=mod;
	return t;
}
inline int dec(int a,int b)
{
	if((a-=b)<0)a+=mod;
	return a;
}
inline int power(int a,ll b)
{
	int out=1;
	while(b)
	{
		if(b&1)out=mult(out,a);
		a=mult(a,a);
		b>>=1;
	}
	return out;
}
int n,K,dp[255][255],c[255][255],sum[255][255],pw1[255],pw2[255];
int main()
{
	scanf("%d%d",&n,&K);
	if(K==1)
	{
		puts("1");
		return 0;
	}
	c[0][0]=1;
	for(int i=1;i<=250;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)c[i][j]=add(c[i-1][j-1],c[i-1][j]);
	}
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=n;i++)pw1[i]=mult(pw1[i-1],K),pw2[i]=mult(pw2[i-1],K-1);
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=add(dp[i][j],mult(dp[i-1][j],dec(mult(pw2[n-j],pw1[j]),pw2[n])));
			for(int k=j+1;k<=n;k++)
			{
				dp[i][k]=add(dp[i][k],mult(dp[i-1][j],mult(pw1[j],mult(c[n-j][k-j],pw2[n-k]))));
			}
		}
	}
	printf("%d\n",dp[n][n]);
	return 0;
}