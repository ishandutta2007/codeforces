#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, ans = 0;
pair<int, int> a[N];
map<int, int> comp;

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

void solve()
{
	vector<int> x, v;
	comp.clear();
	for(int i = 1; i <= n; i++)
	{
		x.push_back(a[i].first);
		v.push_back(a[i].second);
		comp[a[i].second];
	}
	int num = 0;
	for(auto &it:comp)
		it.second = ++num;
	for(auto &it:v)
		it = comp[it];
	int sz = x.size();
	BIT bit1, bit2;
	bit1.init(num);
	bit2.init(num);
	for(int i = 0; i < sz; i++)
	{
		int cnt = bit1.pref(v[i]);
		int sum = bit2.pref(v[i]);
		ans += cnt * x[i] - sum;
		bit1.update(v[i], 1);
		bit2.update(v[i], x[i]);
	}
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].first;
	for(int i = 1; i <= n; i++)
		cin >> a[i].second;
	sort(a + 1, a + n + 1);
	solve();
	cout << ans << endl;
	return 0;
}