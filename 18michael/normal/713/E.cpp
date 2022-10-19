#include<cstdio>
#include<algorithm>
#define inf 0x3f3f3f3f
using namespace std;
int m,n,mx,num=1,l,r,mid;
int b[100002],dp[100002];
inline void calc(int t)
{
	for(int i=3;i<=n;++i)
	{
		if(dp[i-1]>=b[i]-1)dp[i]=b[i]+t;
		else if(dp[i-1]+t<b[i]-1)return (void)(dp[n]=-inf);
		else if(dp[i-2]+t<b[i]-1)dp[i]=b[i];
		else dp[i]=max(b[i],b[i-1]+t);
	}
}
inline bool check(int t)
{
	dp[1]=1;
	if(b[2]==b[1]+1)
	{
		dp[2]=b[2]+t,calc(t);
		if(dp[n]>=m-t)return 1;
	}
	else if(b[1]+t>=b[2]-1)
	{
		dp[2]=b[2],calc(t);
		if(dp[n]>=m-t)return 1;
	}
	dp[1]=b[1]+t;
	if(b[1]+t<b[2]-1)
	{
		dp[2]=b[2],calc(t);
		return (dp[n]>=m);
	}
	dp[2]=dp[1],calc(t);
	return (dp[n]>=(m-max(t-b[2]+1,0)));
}
int main()
{
	scanf("%d%d",&m,&n);if(n==1)return 0&printf("%d",m-1);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);mx=b[1]+m-b[n]-1;
	for(int i=2;i<=n;++i)if(b[i]-b[i-1]-1>mx)mx=b[i]-b[i-1]-1,num=i;num=b[num];
	for(int i=1;i<=n;++i)if((b[i]-=num-1)<=0)b[i]+=m;sort(b+1,b+n+1);
	for(l=((r=b[1]+m-b[n]-1)+1)/2;l<=r;)if(check(mid=((l+r)>>1)))r=mid-1;else l=mid+1;
	return 0&printf("%d",l);
}