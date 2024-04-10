#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=5e3+5;
const int MOD=1e9+7;

int n;
char a[N];
int cache[N][N];

int dp(int i, int ind)
{
	if(ind<0)
		return 0;
	if(i>=n+1)
		return ind+1;
	if(cache[i][ind]!=-1)
		return cache[i][ind];
	int &ans=cache[i][ind];
	ans=0;
	if(a[i-1]=='f')
		ans=dp(i+1, ind+1)-dp(i+1, ind)+MOD;
	else
		ans=dp(i+1, ind);
	ans%=MOD;
	ans+=dp(i, ind-1);
	ans%=MOD;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	int ind=n+1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]=='f')
			ind=min(ind, i);
	}
	int ans=dp(ind+2, 1)-dp(ind+2, 0)+MOD;
	ans%=MOD;
	cout<<ans;
	return 0;
}