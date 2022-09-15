#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int arr[1010];
int a[101010];
int dp[304];
int v;
int getLDS()
{
	memset(dp,0,sizeof(dp)); 
	int ans=0;
	for(int i=0;i<v;i++)
	{
		int maxv=0;
		for(int j=0;j<=a[i];j++)
			maxv=max(maxv,dp[j]);
		maxv++;
		ans=max(ans,maxv);
		dp[a[i]]=maxv;
	}
	return ans;
}
const int fff = 112;
int main()
{
	int N, T;
	scanf("%d %d",&N, &T);
	for(int i=0;i<N;i++) scanf("%d",arr+i);
	for(int i=0;i<N;i++)
		for(int j=0;j<fff;j++)
			a[j*N+i] = arr[i];
	if(T<fff)
	{
		v = N*T;
		printf("%d",getLDS());
	}
	else
	{
		v = N * 101;
		int x= getLDS();
		v = N * 102;
		int x2= getLDS();
		int d=x2-x;
		printf("%d",x+(T-101)*d);
	}
	return 0;
}