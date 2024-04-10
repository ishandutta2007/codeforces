//zhouakngyang txdy!
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
	int sum=0,nega=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')nega=-1;ch=getchar();}
	while(ch<='9'&&ch>='0')sum=sum*10+ch-'0',ch=getchar();
	return sum*nega;
}
long long n,m,mod,res[409],k;
int C[409][409],dp[409][409],pown[409];
signed main()
{
	n=read(),mod=read();
	for(int i=1;i<=n;i++)C[i][0]=C[i][i]=1;
	pown[0]=1;
	for(int i=1;i<=n;i++)pown[i]=pown[i-1]*2%mod;
	for(int i=2;i<=n;i++)
		for(int j=1;j<i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	long long ans=0;
	dp[1][1]=1,dp[2][1]=2;
	for(int i=3;i<=n;i++) 
	{
		dp[i][1]=pown[i-1];
		for(int j=2;j<=(i+1)/2;j++) 
			for(int k=1;k<=i-2;k++) 
			{
				dp[i][j]=(dp[i][j]+dp[k][j-1]*C[i-j+1][i-k-1]%mod*pown[i-k-2]%mod)%mod;
			}
	}
	for(int i=1;i<=(n+1)/2;i++)ans=(ans+dp[n][i])%mod;
	cout<<ans<<endl;
	return 0;
}