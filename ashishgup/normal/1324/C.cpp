#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int n = s.size();
		int prv = 0, ans = 1;
		for(int i = 1; i <= n; i++)
		{
			if(s[i - 1] == 'R')
			{
				ans = max(ans, i - prv);
				prv = i;
			}
		}
		ans = max(ans, n + 1 - prv);
		cout << ans << endl;
	}
	return 0;
}