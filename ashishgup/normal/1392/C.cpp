#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int ans = 0, mx = a[1];
		for(int i = 2; i <= n; i++)
		{
			a[i] += ans;
			if(a[i] < mx)
				ans += mx - a[i];
			else
				mx = a[i];
		}
		cout << ans << endl;
	}
	return 0;
}