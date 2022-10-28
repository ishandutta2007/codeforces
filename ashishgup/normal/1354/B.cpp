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
		map<char, int> m;
		int l = 0, ans = 1e9;
		for(int r = 0; r < s.size(); r++)
		{
			m[s[r]]++;
			while(m[s[l]] > 1)
			{
				m[s[l]]--;
				l++;
			}
			if(m.size() == 3)
				ans = min(ans, r - l + 1);
		}
		if(ans > 1e7)
			ans = 0;
		cout << ans << endl;
	}
	return 0;
}