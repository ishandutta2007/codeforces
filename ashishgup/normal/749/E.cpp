#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
struct BIT
{
	int N;
	vector<int> bit;
 
	void init(int n)
	{
		N = n;
		bit.assign(n + 1, 0);
	}
 
	void update(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] += val;
			idx += idx & -idx;
		}
	}
 
	void updateMax(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] = max(bit[idx], val);
			idx += idx & -idx;
		}
	}
 
	int pref(int idx)
	{
		int ans = 0;
		while(idx > 0)
		{
			ans += bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}
 
	int rsum(int l, int r)
	{
		return pref(r) - pref(l - 1);
	}
 
	int prefMax(int idx)
	{
		int ans = -2e9;
		while(idx > 0)
		{
			ans = max(ans, bit[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
};
 
int n;
int a[N];
 
int32_t main()
{
	IOS;
	cin >> n;
	BIT bit;
	bit.init(1e5);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	double ans = 0;
	for(int i = n; i >= 1; i--)
	{
		ans += bit.pref(a[i]);
		bit.update(a[i], 1);
	}	
	bit.init(1e5);
	double extra = 0;
	for(int i = 1; i <= n; i++)
	{
		extra += (n - i + 1) * bit.pref(a[i]);
		bit.update(a[i], i);
		a[i] = n - a[i] + 1;
	}
	extra /= n;
	extra /= (n + 1);
	ans += extra;
	bit.init(1e5);
	extra = 0;
	for(int i = 1; i <= n; i++)
	{
		extra += (n - i + 1) * bit.pref(a[i]);
		bit.update(a[i], i);
		a[i] = n - a[i] + 1;
	}
	extra /= n;
	extra /= (n + 1);
	ans -= extra;
	cout << fixed << setprecision(12) << ans;
	return 0;
}