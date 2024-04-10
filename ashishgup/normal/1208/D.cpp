#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

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
int a[N], ans[N];

int32_t main()
{
	IOS;
	cin >> n;
	BIT bit;
	bit.init(n + 5);
	set<int> s;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		bit.update(i, i);
		s.insert(i);
	}
	for(int i = n; i >= 1; i--)
	{
		int lo = 1, hi = n;
		while(lo < hi)
		{
			int mid = (lo + hi + 1) / 2;
			if(bit.pref(mid - 1) < a[i])
				lo = mid + 1;
			else if(bit.pref(mid - 1) > a[i])
				hi = mid - 1;
			else
				lo = hi = mid;
		}
		auto it = s.lower_bound(lo);
		ans[i] = *it;
		bit.update(*it, -*it);
		s.erase(it);
	}
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";
	return 0;
}