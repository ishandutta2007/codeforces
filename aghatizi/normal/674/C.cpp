#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ld double

const int maxn = 2e5 + 20;

ld sum[maxn] , val[maxn] , dp[maxn] , pd[maxn];
ll st[maxn];

int t[maxn] , n;

void solve(int l , int r , int s , int e)
{
	if(e < s)
		return;

	int m = (s + e) / 2;
	pair<ld , int> upd;
	for(int i = l; i <= r && i < m; i++)
	{
		ld tmp = pd[i] + val[m] - val[i] - (st[m] - st[i]) * (sum[n] - sum[m]);
		if(i == l)
			upd = make_pair(tmp , i);
		else
			upd = min(upd , make_pair(tmp , i));
	}

	dp[m] = upd.first;
	solve(l , upd.second , s , m - 1);
	solve(upd.second , r , m + 1 , e);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k;
	cin >> n >> k;

	for(int i = 0; i < n; i++)
	{
		cin >> t[i];
		st[i + 1] = st[i] + t[i];
		sum[i + 1] = sum[i] + 1 / (ld)t[i];
	}

	for(int i = 0; i < n; i++)
		val[i + 1] = val[i] + t[i] * (sum[n] - sum[i]);

	fill(pd , pd + maxn , 1e18);
	pd[0] = 0;
	for(int i = 1; i <= k; i++)
	{
		solve(0 , n , 0 , n);
		dp[0] = 0;
		for(int i = 0; i <= n; i++)
			pd[i] = dp[i];
	}

	cout << fixed << setprecision(20) << pd[n] << endl;
}