#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n;
int a[N], pref[N], suf[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= 2 * n; i++)
			cin >> a[i];
		int cnt = 0;
		for(int i = n + 1; i <= 2 * n; i++)
		{
			if(a[i] == 1)
				cnt--;
			else
				cnt++;
		}
		map<int, int> mx;
		mx[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			pref[i] = pref[i - 1];
			pref[i] += (a[i] == 1);
			pref[i] -= (a[i] == 2);
			mx[pref[i]] = i;
		}
		int ans = 2e9;
		if(mx.find(cnt) != mx.end())
			ans = n - mx[cnt];
		for(int i = n + 1; i <= 2 * n; i++)
		{
			if(a[i] == 1)
				cnt++;
			else
				cnt--;
			if(mx.count(cnt))
				ans = min(ans, i - n + n - mx[cnt]);
		}
		cout << ans << endl;
	}
	return 0;
}