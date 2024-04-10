#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e3 + 5;

int n;
char s[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int ans = n;
		int cnt = n;
		for(int i = 1; i <= n; i++)
		{
			cin >> s[i];
			if(s[i] == '1')
			{
				int cur = 2 * i;
				ans = max(ans, cur);
				ans = max(ans, 2 * n - cur + 2);
				cnt++;
			}
		}
		ans = max(ans, cnt);
		cout << ans << endl;
	}
	return 0;
}