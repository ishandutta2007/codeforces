#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e6 + 5;

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
		int ans = 0;
		int mn = 1e9;
		for(int i = n; i >= 1; i--)
		{
			if(a[i] > mn)
				ans++;
			mn = min(mn, a[i]);
		}
		cout << ans << endl;
	}
	return 0;
}