#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int x[maxn] , a[maxn];

ll dp[maxn] , pd[maxn];

void solve(int l , int r , int s , int e)
{
	if(s >= e)
		return;
	int m = (e + s) / 2;

	pair<ll , int> tmp = {pd[maxn - 10] , -1};
	for(int i = l; i <= r; i++)
		if(i < m)
		{
			ll upd = pd[i] + 1LL * a[i + 1] * (m - i);
			tmp = min(tmp , make_pair(upd , -i));
		}
	dp[m] = tmp.first;
	tmp.second *= -1;

	solve(l , tmp.second , s , m);
	solve(tmp.second , r , m + 1 , e);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n , m , p;
	cin >> n >> m >> p;

	for(int i = 1; i < n; i++)
	{
		cin >> x[i];
		x[i] += x[i - 1];
	}

	ll sum = 0;
	for(int i = 1; i <= m; i++)
	{
		int h , t;
		cin >> h >> t;
		a[i] = t - x[h - 1];
		sum += a[i];
	}
	p = min(p , m);

	sort(a + 1 , a + m + 1);
	reverse(a + 1 , a + m + 1);

	memset(dp , 63 , sizeof dp);
	dp[0] = 0;
	memset(pd , 63 , sizeof pd);
	pd[0] = 0;

	for(int i = 1; i <= p; i++)
	{
		solve(0 , m + 1 , 1 , m + 1);
		memcpy(pd , dp , sizeof dp);
	}

	cout << pd[m] - sum << endl;
}