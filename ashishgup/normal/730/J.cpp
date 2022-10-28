#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 101;
const int off = N * N;

int n;
int a[N], b[N];
bool vis[N][N * N * 2];
pair<int, int> cache[N][N * N * 2];

pair<int, int> dp(int idx, int have)
{
	if(idx > n)
	{
		if(have >= 0)
			return {0, 0};
		return {1e9, 1e9};
	}
	pair<int, int> &ans = cache[idx][have + off];
	if(vis[idx][have + off])
		return ans;
	vis[idx][have + off] = 1;
	pair<int, int> cur1 = dp(idx + 1, have - a[idx]);
	cur1.second += a[idx];
	pair<int, int> cur2 = dp(idx + 1, have + (b[idx] - a[idx]));
	cur2.first += 1;
	ans = min(cur1, cur2);
	return ans;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		cin >> b[i];
	pair<int, int> ans = dp(1, 0);
	cout << ans.first << " " << ans.second;		
	return 0;
}