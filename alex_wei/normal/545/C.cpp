#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,dp[100005][3];
struct tree{
	int x,h;
}p[100005];
bool cmp(tree a,tree b){return a.x<b.x;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].h;
	sort(p+1,p+n+1,cmp);
	p[0].x=-1e9,p[n+1].x=2e9+5;
	for(int i=1;i<=n;i++){
		dp[i][0]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
		if(p[i].x-p[i-1].x>p[i].h)dp[i][1]=max(dp[i-1][1],dp[i-1][0])+1;
		if(p[i].x-p[i-1].x>p[i].h+p[i-1].h)dp[i][1]=max(dp[i][1],dp[i-1][2]+1);
		if(p[i+1].x-p[i].x>p[i].h)dp[i][2]=max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2])+1;
	}
	cout<<max(max(dp[n][0],dp[n][1]),dp[n][2]);
	return 0;
}