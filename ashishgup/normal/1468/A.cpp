#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 5e5 + 5;

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

int n;
int a[N], l[N], mx[N];
vector<int> store[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
		{
			l[i] = -1;
			mx[i] = 0;
			store[i].clear();
			cin >> a[i];
		}
		stack<int> s;
		for(int i = 1; i <= n; i++)
		{ 
			while(s.size() && a[s.top()] <= a[i])
				s.pop();
			if(s.size())
			{
				l[i] = s.top();
				store[l[i]].push_back(i);
			}
			s.push(i);
		}
		BIT bit;
		bit.init(n + 5);
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			int prv = bit.prefMax(a[i]);
			mx[i] = max(mx[i], prv + 1);
			bit.updateMax(a[i], mx[i]);
			for(auto &it:store[i])
			{
				int val = a[it];
				int lis = bit.prefMax(val);
				mx[it] = max(mx[it], lis + 2);
			}
		}
		cout << bit.prefMax(n) << endl;
 	}
	return 0;
}