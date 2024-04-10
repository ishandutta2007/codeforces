#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int a, b, c;

int32_t main()
{
	IOS;
	cin >> a >> b >> c;
	int ans = 0;
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			int cur = i, cnt = 0;
			int cura = a, curb = b, curc = c;
			while(true)
			{
				if(cur == 0 || cur == 3 || cur == 6)
					cura--;
				else if(cur == 1 || cur == 5)
					curb--;
				else
					curc--;
				cnt++;
				if(cur == j)
					break;
				cur++;
				cur %= 7;
			}
			if(cura < 0 || curb < 0 || curc < 0)
				continue;
			int curans = cnt + 7 * min({cura / 3, curb / 2, curc / 2});
			ans = max(ans, curans);
		}
	}
	cout << ans;
	return 0;
}