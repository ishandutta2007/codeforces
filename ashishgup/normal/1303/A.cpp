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
		int cnt = 0, one = 0, ans = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '0')
				cnt++;
			else
			{
				if(one)
					ans += cnt;
				cnt = 0;
				one = 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}