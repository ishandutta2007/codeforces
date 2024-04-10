#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k;
int a[N];


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


int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		BIT bit;
		cin >> n >> k;
		bit.init(2 * k + 5);
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n / 2; i++)
		{
			int mn = min(a[i], a[n - i + 1]);
			int mx = max(a[i], a[n - i + 1]);
			bit.update(1, 2);
			bit.update(mn + 1, -2);
			int val = a[i] + a[n - i + 1];
			if(mn + 1 <= val - 1)
			{
				bit.update(mn + 1, 1);
				bit.update(val, -1);
			}
			if(mx + k >= val + 1)
			{
				bit.update(val + 1, 1);
				bit.update(mx + k + 1, -1);
			}
			bit.update(mx + k + 1, 2);
		}
		int ans = n;
		for(int i = 2; i <= 2 * k; i++)
			ans = min(ans, bit.pref(i));
		cout << ans << endl;
	}	
	return 0;
}