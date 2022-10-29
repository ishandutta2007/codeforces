#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, m, k, ans = 0;
int p[N], s[N], c[N], mx[N];

int32_t main()
{
	IOS;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
		cin >> p[i];
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		mx[s[i]] = max(mx[s[i]], p[i]);
	}
	for(int i = 1; i <= k; i++)
	{
		int idx;
		cin >> idx;
		if(mx[s[idx]] != p[idx])
			ans++;
	}
	cout << ans;
	return 0;
}