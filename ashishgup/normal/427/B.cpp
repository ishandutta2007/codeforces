#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, t, c, ans = 0;
int a[N];

int32_t main()
{
	IOS;
	cin >> n >> t >> c;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		int j = i;
		while(j <= n && a[j] <= t)
			j++;
		int len = j - i;
		ans += max(0LL, len - c + 1);
		i = j;
	}
	cout << ans;
	return 0;
}