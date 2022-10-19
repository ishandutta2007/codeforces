#include<bits/stdc++.h>
#define Mx 2000
using namespace std;
int r,n,ans=0;
int x[2002],y[2002],t[2002],dp[2002];
template<class T>void read(T &x)
{
	x=0;int f=0;char ch=getchar();
	while(ch<'0' || ch>'9')f|=(ch=='-'),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	x=f? -x:x;return ;
}
inline int dis(int a,int b)
{
	return abs(x[a%Mx]-x[b%Mx])+abs(y[a%Mx]-y[b%Mx]);
}
int main()
{
	read(r),read(n),x[0]=y[0]=1,t[0]=dp[0]=0;
	for(int i=1,k;i<=n;++i)
	{
		read(t[i%Mx]),read(x[i%Mx]),read(y[i%Mx]),dp[i%Mx]=-n,k=max(0,i-Mx+1);
		for(int j=i-1;j>=k;--j)if(dis(i,j)<=t[i%Mx]-t[j%Mx])dp[i%Mx]=max(dp[i%Mx],dp[j%Mx]+1);
		ans=max(ans,dp[i%Mx]);
	}
	return 0&printf("%d",ans);
}