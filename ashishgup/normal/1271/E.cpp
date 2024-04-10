#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, k, X;
int cache[64][2];

/*int dp(int i, int less)
{
	int &ans = cache[i][less];
	if(ans != -1)
		return ans;
	int lo = 0, hi = 0;

}*/

int get(int x)
{
	int ans = 0, cur = 1;
	int curx = x;
	while(2 * x + 1 <= n)
	{
		cur *= 2;
		ans += cur;
		x = 2 * x + 1;
		curx *= 2;
	}
	if(curx * 2 <= n)
		return (ans + n - curx * 2 + 1);
	return ans;
}

int binsearch(int lo, int hi)
{
	while(lo < hi)
	{
		int mid = (lo + hi + 1) / 2;
		if(get(mid) >= k)
			lo = mid;
		else
			hi = mid - 1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin >> n >> k;
	if(k == n)
	{
		cout << 1;
		return 0;
	}
	int ans = binsearch(1, n / 2);
	int odd = get(ans) - get(ans * 2) - 1;
	if(odd >= k)
		cout << ans * 2 + 1;
	else
		cout << ans * 2;
	return 0;
}