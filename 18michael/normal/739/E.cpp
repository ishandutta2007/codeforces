#include<bits/stdc++.h>
#define eps 1e-8
#define eps1 1e-12
using namespace std;
int n,A,B;
double l,r,mid;
double a[2002],b[2002];
double dp[2][2002];
int num[2][2002];
inline bool check()
{
	for(int i=0;i<=n;++i)dp[0][i]=dp[1][i]=num[0][i]=num[1][i]=0;
	for(int i=1,i0=0,i1=1;i<=n;++i,i0^=1,i1^=1)
		for(int j=min(i,A);~j;--j)
		{
			dp[i1][j]=dp[i0][j],num[i1][j]=num[i0][j];
			if(j && (dp[i1][j]<dp[i0][j-1]+a[i] || (dp[i1][j]<eps1+dp[i0][j-1]+a[i] && num[i0][j-1]<num[i1][j])))
				dp[i1][j]=dp[i0][j-1]+a[i],num[i1][j]=num[i0][j-1];
			if(dp[i1][j]<dp[i0][j]+b[i]-mid || (dp[i1][j]<eps1+dp[i0][j]+b[i]-mid && num[i0][j]+1<num[i1][j]))
				dp[i1][j]=dp[i0][j]+b[i]-mid,num[i1][j]=num[i0][j]+1;
			if(j && (dp[i1][j]<dp[i0][j-1]+a[i]+b[i]-a[i]*b[i]-mid || (dp[i1][j]<eps1+dp[i0][j-1]+a[i]+b[i]-a[i]*b[i]-mid && num[i0][j-1]+1<num[i1][j])))
				dp[i1][j]=dp[i0][j-1]+a[i]+b[i]-a[i]*b[i]-mid,num[i1][j]=num[i0][j-1]+1;
		}
	return num[n&1][A]<=B;
}
int main()
{
	scanf("%d%d%d",&n,&A,&B);
	for(int i=1;i<=n;++i)scanf("%lf",&a[i]);
	for(int i=1;i<=n;++i)scanf("%lf",&b[i]);
	for(l=0,r=1;l+eps<=r;)
	{
		mid=(l+r)/2;
		if(check())r=mid;
		else l=mid;
	}
	return 0&printf("%.8lf",dp[n&1][A]+B*mid);
}