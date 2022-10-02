#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int a[100005];
int sl[5000005];
int dp[5000005];
signed main()
{
	int n;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),sl[a[i]]++;
	for(int i=1;i<=5000000;i++)
	{
		for(int j=2*i;j<=5000000;j+=i)sl[i]+=sl[j];
	}
	//printf("orz\n");
	for(int i=1;i<=5000000;i++)dp[i]=sl[i]*i;
	for(int j=5000000;j>=1;j--)
	{
		if(sl[j]==0)continue;
		for(int k=2*j;k<=5000000;k+=j)dp[j]=max(dp[j],dp[k]+(sl[j]-sl[k])*j);
	}
	printf("%lld\n",dp[1]);
	return 0;
}