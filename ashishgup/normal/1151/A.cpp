#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

string reqd = "ACTG";

int32_t main()
{
	IOS;
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 1e9;
	for(int i = 0; i + 3 < n; i++)
	{
		int cur = 0;
		for(int j = i; j <= i + 3; j++)
		{
			int diff = min(abs(s[j] - reqd[j - i]), abs(26 - abs(s[j] - reqd[j - i])));
			cur += diff;
		}
		ans = min(ans, cur);
	}
	cout << ans;
	return 0;
}