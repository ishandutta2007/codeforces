#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int k1, k2, k3;
vector<int> v[5];
int store[N];

int get(int i, int x)
{
	auto j = lower_bound(v[i].begin(), v[i].end(), x) - v[i].begin();
	return j;
}

int32_t main()
{
	IOS;
	cin >> k1 >> k2 >> k3;
	int k[5] = {0, k1, k2, k3, 0};
	for(int i = 1; i <= 3; i++)
	{
		for(int j = 1; j <= k[i]; j++)
		{
			int x;
			cin >> x;
			v[i].push_back(x);
		}
		sort(v[i].begin(), v[i].end());
	}
	for(int i = 0; i < k2; i++)
	{
		auto j = lower_bound(v[3].begin(), v[3].end(), v[2][i]) - v[3].begin();
		store[i] = j + k2 - i - 1;
	}
	for(int i = k2 - 2; i >= 0; i--)
		store[i] = min(store[i + 1], store[i]);
	int n = k1 + k2 + k3;
	int ans = n;
	ans = min(ans, k1 + k2);
	ans = min(ans, k2 + k3);
	ans = min(ans, k1 + k3);
	for(int i = 0; i <= n; i++)
	{
		int one = k1 - get(1, i + 1) + i - get(1, i + 1);
		ans = min(ans, one + k2 - get(2, i + 1));
		ans = min(ans, one + k3 - get(3, i + 1));
		auto idx2 = lower_bound(v[2].begin(), v[2].end(), i + 1) - v[2].begin();
		if(idx2 == k2)
			ans = min(ans, one);
		else
		{
			int extra = store[idx2];
			extra -= get(3, i + 1);
			one += extra;
			ans = min(ans, one);
		}
	}	
	cout << ans;
	return 0;
}