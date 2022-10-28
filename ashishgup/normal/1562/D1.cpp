#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 3e5 + 5;

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

	//returns first index such that pref[idx] >= val

	int search(int val)
	{
		int curSum = 0, pos = 0;
		for(int i = log2(N) + 1; i >= 0; i--)
		{
			if(pos + (1 << i) < N && curSum + bit[pos + (1 << i)] < val)
			{
				curSum += bit[pos + (1 << i)];
				pos += (1 << i);
			}
		}
		return pos + 1;
	}

	void updateMax(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] = max(bit[idx], val);
			idx += idx & -idx;
		}
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
string s;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> q;
		cin >> s;
		BIT bit1, bit2;
		bit1.init(n);
		bit2.init(n);
		for(int i = 1; i <= n; i++)
		{
			if(i % 2)
			{
				if(s[i - 1] == '+')
					bit1.update(i, +1);
				else
					bit1.update(i, -1);
			}
			else
			{
				if(s[i - 1] == '+')
					bit1.update(i, -1);
				else
					bit1.update(i, +1);
			}
		}
		for(int i = 1; i <= n; i++)
		{
			if(i % 2)
			{
				if(s[i - 1] == '+')
					bit2.update(i, -1);
				else
					bit2.update(i, +1);
			}
			else
			{
				if(s[i - 1] == '+')
					bit2.update(i, +1);
				else
					bit2.update(i, -1);
			}
		}
		while(q--)
		{
			int l, r;
			cin >> l >> r;
			int rsum = 0;
			if(l % 2)
				rsum = bit1.rsum(l, r);
			else
				rsum = bit2.rsum(l, r);
			rsum = abs(rsum);
			int ans = 0;
			if(rsum % 2)
				ans = 1;
			else if(rsum > 0)
				ans = 2;
			cout << ans << endl;
		}
	}
	return 0;
}