#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;
const int MOD = 998244353;

int n, m, ans = 1;
int a[N], b[N];
int pref[N];

int32_t main()
{
	IOS;
	cin >> n >> m;
	if(m > n)
	{
		cout << 0;
		return 0;
	}
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> b[i];
	for(int i = 1; i <= n; i++)
	{
		if(a[i] < b[1])
		{
			cout << 0;
			return 0;
		}
	}
	reverse(a + 1, a + n + 1);
	reverse(b + 1, b + m + 1);
	pref[1] = a[1];
	for(int i = 2; i <= n; i++)
		pref[i] = min(pref[i - 1], a[i]);
	reverse(pref + 1, pref + n + 1);
	reverse(b + 1, b + m + 1);
	reverse(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++)
	{
		if(a[i] > b[1])
			pref[i] = -1e9;
		else
			break;
	}
	int idx = 1;
	while(idx <= m)
	{
		auto it = lower_bound(pref + 1, pref + n + 1, b[idx]);
		auto it2 = upper_bound(pref + 1, pref + n + 1, b[idx]);
		int cnt = it2 - it;
		if(idx == 1)
			cnt = min(cnt, 1LL);
		ans *= cnt;
		ans %= MOD;
		idx++;
	}
	cout << ans;
	return 0;
}