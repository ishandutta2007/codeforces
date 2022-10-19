#include <iostream>
#include <algorithm>
using namespace std;
const int N=100,INF=999999999;

int t;
int a[N][N][N];
int dp(int n,int m,int k)
{
	if(k==0)
		return 0;
	if(n*m==k)
		return 0;
	if(a[n][m][k])
		return a[n][m][k];
	a[n][m][k]=INF;
	for(int i=1;i<n;++i)
	{
		for(int j=0;j<=k;++j)
		{
			a[n][m][k]=min(a[n][m][k],m*m+dp(i,m,j)+dp(n-i,m,k-j));
		}
	}
	for(int i=1;i<m;++i)
	{
		for(int j=0;j<=k;++j)
		{
			a[n][m][k]=min(a[n][m][k],n*n+dp(n,i,j)+dp(n,m-i,k-j));
		}
	}
	return a[n][m][k];
}
int main()
{
	int n,m,k;
	cin>>t;
	for(int i=0;i<t;++i)
	{
		cin>>n>>m>>k;
		cout<<dp(n,m,k)<<endl;
	}
	return 0;
}