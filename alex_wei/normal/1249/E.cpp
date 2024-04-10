#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,c,a[200005],b[200005],dp[200005][2];
int main()
{
	cin>>n>>c;
	for(int i=1;i<n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		cin>>b[i];
	cout<<"0 ";
	dp[0][1]=c;
	for(int i=1;i<n;i++){
		dp[i][0]=min(dp[i-1][1],dp[i-1][0])+a[i];
		dp[i][1]=min(dp[i-1][1],dp[i-1][0]+c)+b[i];
//		cout<<dp[i-1][0]+c<<" "<<dp[i-1][1]<<endl;
		cout<<min(dp[i][0],dp[i][1])<<" ";
	}
    return 0;
}