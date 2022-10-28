#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 1e6 + 5;

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

int n, q;

int32_t main()
{
	IOS;
	cin >> n >> q;
	BIT bit;
	bit.init(n + 1);
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		bit.update(x, 1);
	}
	while(q--)
	{
		int k;
		cin >> k;
		if(k > 0)
			bit.update(k, 1);
		else
		{
			int lo = 1, hi = n;
			k = -k;
			while(lo < hi)
			{
				int mid = (lo + hi) / 2;
				if(bit.pref(mid) >= k)
					hi = mid;
				else
					lo = mid + 1;
			}
			bit.update(lo, -1);
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(bit.pref(i) > 0)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}