#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 200 * 200 + 5;

int store[N], pref[2 * N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		memset(store, 0, sizeof(store));
		int a, b, q;
		cin >> a >> b >> q;
		int period = a * b;
		int tot = 0;
		for(int i = 0; i < period; i++)
		{
			store[i] = ((i % a) % b) != ((i % b) % a);
			tot += store[i];
			pref[i] = store[i];
			if(i > 0)
				pref[i] += pref[i - 1];
		}
		for(int i = period; i < 2 * period; i++)
			pref[i] = pref[i - 1] + store[i - period];
		while(q--)
		{
			int l, r;
			cin >> l >> r;
			int ans = 0;
			int extra = ((r - l + 1) % period);
			int cur = l % period;
			if(extra > 0)
			{
				ans += pref[cur + extra - 1];
				if(cur > 0)
					ans -= pref[cur - 1];
			}
			ans += tot * ((r - l + 1) / period);
			cout << ans << " ";
		}
		cout << endl;
	}
	return 0;
}