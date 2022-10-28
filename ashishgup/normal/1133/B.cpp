#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k, ans = 0;
int a[N], cnt[105];

int32_t main()
{
	IOS;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		cnt[a[i] % k]++;
	}
	for(int i = 0; i <= k - 1; i++)
	{
		if(i != (k - i) % k)
			ans += min(cnt[i], cnt[k - i]);
		else
			ans += cnt[i] / 2 * 2;
	}
	cout << ans;
	return 0;
}