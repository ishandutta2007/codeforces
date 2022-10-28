#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k;
int a[N], pref[N], suf[N];

int get(int l, int r, int val)
{
	int cost = 0;
	if(l > 0)
	{
		auto idx = lower_bound(a + 1, a + n + 1, val) - a;
		cost += val * (idx - 1) - pref[idx - 1];
		cost -= (idx - 1 - l);
	}
	if(r > 0)
	{
		auto idx = upper_bound(a + 1, a + n + 1, val) - a;
		cost += suf[idx] - val * (n - idx + 1);
		cost -= (n - idx + 1 - r);
	}
	return cost;
}

int32_t main()
{
	IOS;
	cin >> n >> k;
	map<int, int> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		m[a[i]]++;
	}
	vector<pair<int, int> > v;
	for(auto &it:m)
	{
		if(it.second >= k)
		{
			cout << 0;
			return 0;
		}
		v.push_back(it);
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
		pref[i] = pref[i - 1] + a[i];
	for(int i = n; i >= 1; i--)
		suf[i] = suf[i + 1] + a[i];
	int toLeft = 0, toRight = n;
	int ans = 1e18;
	for(auto &it:v)
	{
		toRight -= it.second;
		int left = k - it.second;
		int val = it.first;
		int takeLeft = min(left, toLeft);
		int takeRight = max(0LL, left - takeLeft);
		ans = min(ans, get(takeLeft, takeRight, val));
		int takeRight2 = min(left, toRight);
		int takeLeft2 = max(0LL, left - takeRight2);
		ans = min(ans, get(takeLeft2, takeRight2, val));
		toLeft += it.second;
	}
	cout << ans;
	return 0;
}