#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 4e5 + 5;

int n;
int a[N];
int pref[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pref[i] = a[i];
		a[i + n] = a[i];
		if(i - 2 >= 0)
			pref[i] += pref[i - 2];
	}
	if(n == 1)
	{
		cout << a[1];
		return 0;
	}
	for(int i = n + 1; i <= 2 * n; i++)
		pref[i] += pref[i - 2] + a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int cur = (a[i] + a[i + 1]);
		cur += pref[i + n - 2] - pref[i + 1];
		ans = max(ans, cur);
	}
	cout << ans;
	return 0;
}