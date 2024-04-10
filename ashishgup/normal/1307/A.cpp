#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, d;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int ans = a[1];
		for(int i = 2; i <= n; i++)
		{
			int reqd = (i - 1);
			int take = min(d / reqd, a[i]);
			ans += take;
			d -= take * reqd;
		}
		cout << ans << endl;
	}	
	return 0;
}