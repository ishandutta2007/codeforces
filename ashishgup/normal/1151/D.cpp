#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
pair<int, int> a[N];

bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
	return p1.first - p1.second > p2.first - p2.second;
}

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1, comp);	
	int ans = 1e18;
	int cur = 0;
	for(int i = 1; i <= n; i++)
		cur += a[i].first * (i - 1) + a[i].second * (n - i);
	ans = min(ans, cur);
	cout << ans;
	return 0;
}