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
		int ans = 0;
		for(int i = 1; i + 1 <= n; i++)
			ans += abs(a[i + 1] - a[i]);
		int sum = ans;
		for(int i = 1; i + 2 <= n; i++)
			ans = min(ans, sum - abs(a[i + 1] - a[i]) - abs(a[i + 2] - a[i + 1]) + abs(a[i + 2] - a[i]));
		ans = min(ans, sum - abs(a[2] - a[1]));
		ans = min(ans, sum - abs(a[n] - a[n - 1]));
		cout << ans << endl;
	}
	return 0;
}