#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, m;
pair<int, int> l[N];
int ans[N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	int tot = 0;
	for(int i = 1; i <= m; i++)
	{
		cin	>> l[i].first;
		tot += l[i].first;
		l[i].second = i;
	}
	if(tot < n)
	{
		cout << -1;
		return 0;
	}
	int overlap = tot - n;
	int idx = 1;
	for(int i = 1; i <= m; i++)
	{
		ans[l[i].second] = idx;
		if(idx + l[i].first - 1 > n)
		{
			cout << -1;
			return 0;
		}
		int increment = l[i].first;
		if(overlap > 0)
		{
			int take = min(l[i].first - 1, overlap);
			overlap -= take;
			increment -= take;
		}
		idx += increment;
	}
	for(int i = 1; i <= m; i++)
		cout << ans[i] << " ";
	return 0;
}