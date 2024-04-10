#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, m;
int a[N], b[N];
map<int, int> c, d;

int32_t main()
{
	IOS;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		c[a[i] % 2]++;
	}
	for(int i = 1; i <= m; i++)
	{
		cin >> b[i];
		d[b[i] % 2]++;
	}
	int ans = min(c[0], d[1]) + min(c[1], d[0]);
	cout << ans;
	return 0;
}