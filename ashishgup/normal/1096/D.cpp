#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
char s[N];
int cost[N];
int cache[N][5];
string reqd = "hard";

int dp(int idx, int cur)
{
	if(cur == reqd.size())
		return 1e18;
	if(idx == n + 1)
		return 0;
	int &ans = cache[idx][cur];
	if(ans != -1)
		return ans;
	int pos1 = dp(idx + 1, cur + (s[idx] == reqd[cur]));
	int pos2 = cost[idx] + dp(idx + 1, cur);
	ans = min(pos1, pos2);
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	for(int i = 1; i <= n; i++)
		cin >> cost[i];
	int ans = dp(1, 0);
	cout<<ans;
	return 0;
}