#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=505;

int n, storek;
int a[N];
bool dp[N][N][2];

int32_t main()
{
	IOS;
	cin>>n>>storek;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int x=0;x<=500;x++)
	{
		for(int i=1;i<=n+1;i++)
		{
			dp[x][0][i&1]=(x==0);
		}
	}
	for(int i=n;i>=1;i--)
	{
		for(int x=0;x<=500;x++)
		{
			for(int k=1;k<=storek;k++)
			{
				bool &ans=dp[x][k][i&1];
				ans|=dp[x][k][i+1&1];
				if(k>=a[i])
					ans|=dp[x][k-a[i]][i+1&1];
				if(x>=a[i]&&k>=a[i])
					ans|=dp[x-a[i]][k-a[i]][i+1&1];
			}
		}
	}
	vector<int> v;
	v.push_back(0);
	for(int i=1;i<=500;i++)
	{
		if(dp[i][storek][1])
			v.push_back(i);
	}
	cout<<v.size()<<endl;
	for(auto it:v)
		cout<<it<<" ";
	return 0;
}