#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=100000+5;
ll n,h[N][2],dp[N][2];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i][0],dp[i][0]=h[i][0];
	for(int i=1;i<=n;i++)
		cin>>h[i][1],dp[i][1]=h[i][1];
	for(int i=2;i<=n;i++)
		dp[i][0]=max(dp[i-1][1],dp[i-2][1])+h[i][0],
		dp[i][1]=max(dp[i-1][0],dp[i-2][0])+h[i][1];
	cout<<max(dp[n][0],dp[n][1]);
    return 0;
}