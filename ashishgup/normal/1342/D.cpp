#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k;
int a[N], c[N], f[N];
vector<int> answer[N];

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		f[a[i]]++;
	}
	for(int i = 1; i <= k; i++)
		cin >> c[i];
	int cur = 0, ans = 0;
	for(int i = k; i >= 1; i--)
	{
		cur += f[i];
		ans = max(ans, (cur + c[i] - 1) / c[i]);
	}
	cout << ans << endl;
	int idx = 0;
	for(int i = k; i >= 1; i--)
	{
		for(int j = 1; j <= f[i]; j++)
		{
			answer[idx].push_back(i);
			idx++;
			idx %= ans;
		}
	}
	for(int i = 0; i < ans; i++)
	{
		cout << answer[i].size() << " ";
		for(auto &it:answer[i])
			cout << it << " ";
		cout << endl;
	}
	return 0;
}