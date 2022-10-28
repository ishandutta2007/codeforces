#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, ans = 0;
int a[N], b[N];
pair<int, int> v[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		v[a[i]].first = i;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> b[i];
		v[b[i]].second = i;
	}
	sort(v + 1, v + n + 1);
	int mx = -1;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(v[i].second < mx)
			ans++;
		mx = max(mx, v[i].second);
	}
	cout << ans;
	return 0;
}