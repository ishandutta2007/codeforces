#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n, m, sum = 0;
int a[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	sort(a + 1, a + n + 1);
	cin >> m;
	while(m--)
	{
		int x, y;
		cin >> x >> y;
		auto it = lower_bound(a + 1, a + n + 1, x) - a;
		if(it == n + 1)
		{
			int attack = x - a[n];
			int defense = max(0LL, y - (sum - a[n]));
			int ans = attack + defense;
			cout << ans << endl;
		}
		else
		{
			int defense = max(0LL, y - (sum - a[it]));
			int ans = defense;
			it--;
			if(it >= 1)
			{
				int attack = x - a[it];
				int defense = max(0LL, y - (sum - a[it]));
				ans = min(ans, attack + defense);
			}
			cout << ans << endl;
		}
	}
	return 0;
}