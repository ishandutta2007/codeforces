#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e3 + 5;

int n, m;
int a[N];
map<char, int> f[N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			char ch;
			cin >> ch;
			f[j][ch]++;
		}
	}
	int ans = 0;
	for(int i = 1; i <= m; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
	{
		int mx = 0;
		for(auto &it:f[i])
			mx = max(mx, it.second);
		ans += mx * a[i];
	}
	cout << ans;
	return 0;
}