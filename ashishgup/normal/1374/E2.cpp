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

int n, m, k;
int idx[N];
vector<int> store[5];
vector<pair<int, int> > store2[5];

void work(int x)
{
	vector<int> ans;
	for(int i = 1; i <= x; i++)
		ans.push_back(store2[3][i].second);
	int taken = x;
	vector<pair<int, int> > v;
	for(int i = 1; i < store2[0].size(); i++)
		v.push_back(store2[0][i]);
	if(x < k)
	{
		int rem = k - x;
		for(int i = 1; i <= rem; i++)
			ans.push_back(store2[2][i].second);
		for(int i = 1; i <= rem; i++)
			ans.push_back(store2[1][i].second);
		taken += rem * 2;
		for(int i = rem + 1; i < store2[2].size(); i++)
			v.push_back(store2[2][i]);
		for(int i = rem + 1; i < store2[1].size(); i++)
			v.push_back(store2[1][i]);
	}
	else
	{
		for(int i = 1; i < store2[1].size(); i++)
			v.push_back(store2[1][i]);
		for(int i = 1; i < store2[2].size(); i++)
			v.push_back(store2[2][i]);
	}
	int remaining = m - taken;
	sort(v.begin(), v.end());
	for(int i = 0; i < remaining; i++)
		ans.push_back(v[i].second);
	for(auto &it:ans)
		cout << it << " ";
	cout << endl;
}

int32_t main()
{
	IOS;
	cin >> n >> m >> k;
	BIT sum, cnt;
	sum.init(10005);
	cnt.init(10005);
	for(int i = 1; i <= n; i++)
	{
		int t, a, b;
		cin >> t >> a >> b;
		store[a * 2 + b].push_back(t);
		store2[a * 2 + b].push_back({t, i});
	}
	for(int i = 0; i <= 3; i++)
	{
		store[i].push_back(0);
		store2[i].push_back({0, 0});
		sort(store[i].begin(), store[i].end());
		sort(store2[i].begin(), store2[i].end());
		for(int j = 1; j < (int)store[i].size(); j++)
			store[i][j] += store[i][j - 1];
	}
	for(int i = 0; i < 3; i++)
		idx[i] = (int)store2[i].size() - 1;
	for(int i = 1; i < store2[0].size(); i++)
	{
		int it = store2[0][i].first;
		cnt.update(it, 1);
		sum.update(it, it);
	}
	int ans = -1, best = -1;
	for(int i = 0; i < (int)store[3].size(); i++)
	{
		int cur = store[3][i];
		int rem = k - i;
		int take = i;
		for(int j = 1; j <= 2; j++)
		{
			while(idx[j] >= 1 && idx[j] > rem)
			{
				cnt.update(store2[j][idx[j]].first, 1);
				sum.update(store2[j][idx[j]].first, store2[j][idx[j]].first);
				idx[j]--;
			}
		}
		if(rem < (int)store[1].size() && rem < (int)store[2].size())
		{
			if(rem >= 0)
			{
				take += 2 * rem;
				cur += store[1][rem] + store[2][rem];
			}
			if(take > m)
				continue;
			if(take < m)
			{
				int reqd = m - take;
				int have = cnt.pref(10000);
				if(have < reqd)
					continue;
				int lo = 0, hi = 10000;
				while(lo < hi)
				{
					int mid = (lo + hi + 1) / 2;
					if(cnt.pref(mid) <= reqd)
						lo = mid;
					else
						hi = mid - 1;
				}
				cur += sum.pref(lo);
				reqd -= cnt.pref(lo);
				cur += reqd * (lo + 1);
			}
			if(ans == -1)
				ans = cur, best = i;
			else if(ans > cur)
				ans = cur, best = i;
		}
	}
	if(ans == -1)
	{
		cout << ans;
		return 0;
	}
	cout << ans << endl;
	work(best);
	return 0;
}