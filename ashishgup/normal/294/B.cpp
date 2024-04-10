#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=105;
const int M=20005;
const int offset=10000;

int n;
int t[N], w[N];
int cache[N][M];

int dp(int i, int extra)
{
	if(i==n+1)
	{
		if(extra<0)
			return 1e9;
		return 0;
	}
	int &ans=cache[i][extra+offset];
	if(ans!=-1)
		return ans;
	ans=min(t[i] + dp(i+1, extra+t[i]), dp(i+1, extra-w[i]));
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n;
	memset(cache, -1, sizeof(cache));
	for(int i=1;i<=n;i++)
		cin>>t[i]>>w[i];
	int ans=dp(1, 0);
	cout<<ans;
}