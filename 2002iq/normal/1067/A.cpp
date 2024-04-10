#include <iostream>
#include <string.h>
using namespace std;
#define mod 998244353
int n,arr[100005],dp[100005][205][2],sum[100005][205][2];
int solve(int i,int l,bool f);
long long solve2(int i,int l,bool f)
{
	if (!l)
	return 0;
	if (i==n)
	return (int)f*l;
	if (sum[i][l][f]!=-1)
	return sum[i][l][f];
	return sum[i][l][f]=(solve(i,l,f)+solve2(i,l-1,f))%mod;
}
int solve(int i,int l,bool f)
{
	if (i==n)
	return f;
	if (dp[i][l][f]!=-1)
	return dp[i][l][f];
	if (arr[i]!=-1)
	{
	    if (!f && l>arr[i])
	    return 0;
	    return solve(i+1,arr[i],(arr[i]<=l));
	}
	int ans=0,st=l;
	if (f)
	st=1;
	return dp[i][l][f]=(solve2(i+1,l,1)-solve2(i+1,st-1,1)+solve2(i+1,200,0)-solve2(i+1,l,0)+2LL*mod)%mod;
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
    scanf("%d",&arr[i]);
	memset(dp,-1,sizeof(dp));
	memset(sum,-1,sizeof(sum));
	printf("%d",solve(0,0,1));
}