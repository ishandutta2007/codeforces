#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int cache[35][2][2];
int x[50], y[50];

int dp(int idx, int b1, int b2)
{
	if(idx == 32)
		return 1;
	int &ans = cache[idx][b1][b2];
	if(ans != -1)
		return ans;
	ans = 0;
	int l1 = 0, h1 = x[idx];
	int l2 = 0, h2 = y[idx];
	if(b1)
		h1 = 1;
	if(b2)
		h2 = 1;
	for(int i = l1; i <= h1; i++)
	{
		for(int j = l2; j <= h2; j++)
		{
			if(i & j)
				continue;
			ans += dp(idx + 1, b1 | (i < x[idx]), b2 | (j < y[idx]));
		}
	}
	return ans;
}

int f(int l, int r)
{
	if(l < 0 || r < 0)
		return 0;
	memset(cache, -1, sizeof(cache));
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	int idx = 31;
	while(l > 0)
	{
		x[idx] = l % 2;
		l /= 2;
		idx--;
	}
	idx = 31;
	while(r > 0)
	{
		y[idx] = r % 2;
		r /= 2;
		idx--;
	}
	return dp(0, 0, 0);
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int l, r;
		cin >> l >> r;
		int ans = f(r, r) - 2 * f(l - 1, r) + f(l - 1, l - 1);
		cout << ans << endl;
	}
	return 0;
}