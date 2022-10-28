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
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = 0, cur = 0;
		for(auto &it:s)
		{
			if(it == '(')
				cur++;
			else
				cur--;
			if(cur < 0)
			{
				ans++;
				cur = 0;
			}
		}
		cout << ans << endl;
	}
	return 0;
}