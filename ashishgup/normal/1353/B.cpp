#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n, k;
int a[N], b[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		for(int i = 1; i <= n; i++)
			cin >> b[i];
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1);
		int ans = 0;
		for(int i = 1; i <= k; i++)
		{
			if(a[i] < b[n + 1 - i])
				swap(a[i], b[n + 1 - i]);
		}
		for(int i = 1; i <= n; i++)
			ans += a[i];
		cout << ans << endl;
	}	
	return 0;
}