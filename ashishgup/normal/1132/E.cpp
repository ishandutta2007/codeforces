//Started Late

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 10;
const int M = 2e3 + 5;

int totw, n = 8;
int a[N], cache[N][M];

int dp(int idx, int totw)
{
	if(totw == 0)
		return 0;
	if(idx == n+1)
		return 0;
	int &ans = cache[idx][totw];
	if(ans != -1)
		return ans;
	ans = 0;
	for(int i=0;idx*i<=totw && i<=a[idx];i++)
		ans = max(ans, i * idx + dp(idx+1, totw - idx*i));
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>totw;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans = 0;
	for(int i=n;i>=1;i--)
	{
		int take = max(0LL, totw - 1000)/i;
		take = min(take, a[i] - 5);
		take = max(take, 0LL);
		a[i] -= take;
		totw -= take * i;
		ans += take * i;
	}	
	totw = min(totw, 2000LL);
	ans += dp(1, totw);
	cout<<ans;
	return 0;
}