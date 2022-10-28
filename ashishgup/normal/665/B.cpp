#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 105;

int n, m, k;
int a[N];

int32_t main()
{
	IOS;
	cin >> n >> m >> k;
	for(int i = 1; i <= k; i++)
		cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			int x;
			cin >> x;
			int idx = 0;
			vector<int> v;
			for(int p = 1; p <= k; p++)
			{
				if(a[p] == x)
					ans += p;
				else
					v.push_back(a[p]);
			}
			reverse(v.begin(), v.end());
			v.push_back(x);
			reverse(v.begin(), v.end());
			for(int p = 1; p <= k; p++)
				a[p] = v[p - 1];
		}
	}
	cout << ans;
	return 0;
}