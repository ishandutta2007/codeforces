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
		r = min(r, N);
		l = max(1LL, l);
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

int n, k;
string s;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		BIT bit;
		bit.init(n + 1);
		cin >> s;
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(s[i - 1] == '1')
				bit.update(i, 1);
		}
		for(int i = 1; i <= n; i++)
		{
			if(s[i - 1] == '0')
			{
				if(bit.rsum(i - k, i + k) == 0)
				{
					s[i] = '1';
					bit.update(i, 1);
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}