#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n;
int a[N], vis[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(vis[i])
			continue;
		vis[i] = 1;
		for(int j = i + 1; j <= n; j++)
		{
			if(a[j] % a[i] == 0)
				vis[j] = 1;
		}
		ans++;
	}
	cout << ans;
	return 0;
}