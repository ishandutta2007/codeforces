#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=150005;
const int M=305;

int n, m, d, ans=0;
int a[M], b[M], t[M], dp[N];
int RMQ[20][N], floorlog[N];
map<int, vector<pair<int, int> > > event;

void precompute()
{
	for(int i=0;(1<<i)<N;i++)
	{
		for(int j=(1<<i);j<N && j<(1<<(i+1)); j++)
			floorlog[j]=i;
	}

	for(int i=n;i>=1;i--)
	{
		RMQ[0][i]=dp[i]; 
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

void go(int time)
{
	if(time==0)
		return;

	precompute();

	for(int x=1;x<=n;x++)
	{
		int diff=t[time+1] - t[time];
		int minx=max(1LL, x - diff*d);
		int maxx=min(n, x + diff*d);
		dp[x]=b[time] - abs(x-a[time]) + getMax(minx, maxx);
	}

	go(time-1);
}	

int32_t main()
{
	IOS;
	cin>>n>>m>>d;
	for(int i=1;i<=m;i++)
		cin>>a[i]>>b[i]>>t[i];
	t[m+1]=t[m];
	go(m);
	int ans=-1e18;
	for(int i=1;i<=n;i++)
		ans=max(ans, dp[i]);
	cout<<ans;
	return 0;
}