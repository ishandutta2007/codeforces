#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e3+5;
const int MOD=1e9+7;

int n;
int a[N];
int cache[N][N];

int dp(int i, int j)
{
	if(i==1&&j==1)
		return 1;
	int &ans=cache[i][j];
	if(ans!=-1)
		return ans;
	ans=0;
	if(j>i)
	{
		ans=dp(i, j-1) + 1;
		if(i!=j-1)
		{
			ans+=dp(a[j-1], j-1);
			if(a[j-1]!=j-1)
				ans++;
		}
	}
	else
	{
		if(a[i]==i)
			ans=1;
		else
			ans=1+dp(a[i], i);
	}
	ans%=MOD;
	return ans;
}

int32_t main()
{
    IOS;
    memset(cache, -1, sizeof(cache));
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
  	int ans=dp(1, n+1);
  	cout<<ans;
    return 0;
}