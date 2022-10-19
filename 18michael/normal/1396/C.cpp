#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,r1,r2,r3,d;
LL a[1000002];
LL dp[1000002][2];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
int main()
{
	read(n),read(r1),read(r2),read(r3),read(d);
	for(int i=1;i<=n;++i)read(a[i]);
	dp[1][0]=a[1]*r1+r3,dp[1][1]=min((a[1]+1)*r1,r2);
	for(int i=2;i<=n;++i)
	{
		dp[i][0]=min(dp[i-1][0]+d+a[i]*r1+r3,min((a[i]+1)*r1,r2)+d+min(dp[i-1][0],dp[i-1][1]+r1)+d+d+r1);
		dp[i][1]=min(min((a[i]+1)*r1,r2)+d+min(dp[i-1][0],dp[i-1][1]+d+r1+d),dp[i-1][0]+d+min((a[i]+1)*r1,r2));
	}
	return 0&printf("%lld",min(dp[n][0],a[n]*r1+r3+d+min(dp[n-1][0],dp[n-1][1]+r1)+d));
}