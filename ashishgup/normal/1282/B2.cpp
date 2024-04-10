#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, p, k;
int a[N], pref[N], pref2[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> p >> k;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		sort(a + 1, a + n + 1);
		for(int i = 0; i < k; i++)
			pref[i] = 0;
		for(int i = 1; i <= n; i++)
			pref2[i] = pref2[i - 1] + a[i];
		int ans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(i >= k)
				pref[i % k] += a[i];
			int left = i % k;
			int reqd = pref[i % k] + pref2[left];
			if(reqd <= p)
				ans = max(ans, i);
		}
		cout << ans << endl;
	}
	return 0;
}