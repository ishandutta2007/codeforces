#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

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
			bit[idx] ^= val;
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
			ans ^= bit[idx];
			idx -= idx & -idx;
		}
		return ans;
	}

	int rsum(int l, int r)
	{
		return pref(r) ^ pref(l - 1);
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

int n, m;
int a[N], pref[N];
int l[N], r[N], ans[N];
vector<int> q[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pref[i] = pref[i - 1] ^ a[i];
	}
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> l[i] >> r[i];
		q[r[i]].push_back(i);
		ans[i] = pref[r[i]] ^ pref[l[i] - 1];
	}
	map<int, int> prv;
	BIT bit;
	bit.init(1e6 + 5);
	for(int i = 1; i <= n; i++)
	{
		if(prv.find(a[i]) != prv.end())
		{
			int idx = prv[a[i]];
			bit.update(idx, a[i]);
		}	
		bit.update(i, a[i]);
		prv[a[i]] = i;
		for(auto &it:q[i])
		{
			int idx = it;
			ans[idx] ^= bit.rsum(l[idx], i);
		}
	}
	for(int i = 1; i <= m; i++)
		cout << ans[i] << endl;
	return 0;
}