#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5005;

int n, k, x;
int a[N], dp[N];
int RMQ[20][N], floorlog[N];

void precompute()
{
	for(int i=0;(1<<i)<N;i++)
	{
		for(int j=(1<<i);j<N && j<(1<<(i+1)); j++)
			floorlog[j]=i;
	}

	for(int i=n;i>=1;i--)
	{
		RMQ[0][i]=a[i] + dp[i+1]; 
		int mxj=floorlog[n-i+1]; //2^j <= n-i+1
		int pw=1;
		for(int j=1;j<=mxj;j++)
		{
			RMQ[j][i]=max(RMQ[j-1][i], RMQ[j-1][i+pw]);
			pw<<=1;
		}
	}	
}

int getMax(int L, int R)
{
	int k=floorlog[R-L+1]; //2^k <= R-L+1
	return max(RMQ[k][L], RMQ[k][R - (1<<k) +1]);
}

void go(int taken)
{
	if(taken==-1)
		return;

	precompute();

	for(int i=1;i<=n;i++)
		dp[i]=getMax(i, min(i+k-1, n));

	go(taken-1);
}

int32_t main()
{
	IOS;
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<N;i++)
		dp[i]=((i+k-1>n)?0:-1e15);
	go(x-1);
	int ans=dp[1];
	if(ans<0)
		ans=-1;
	cout<<ans;
	return 0;
}