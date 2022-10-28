#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=505;

int n;
int a[N];
int cache[N][N];

int dp(int i, int j)
{
	if(i>j)
		return 0;
	if(i==j)
		return 1;
	if(j-i==1)
		return (a[j]==a[i])?1:2;
	if(cache[i][j]!=-1)
		return cache[i][j];
	int &ans=cache[i][j];
	ans=1+dp(i, j-1);
	for(int k=i;k<=j-1;k++)
	{
		if(a[k]==a[j])
			ans=min(ans, dp(i, k-1) + dp(k+1, j-1) + ((j-k)==1));
	}
	if(a[i]==a[j])
		ans=min(ans, dp(i+1, j-1));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<dp(1, n);
}