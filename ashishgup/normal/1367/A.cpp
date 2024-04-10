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
		string ans = "";
		ans += s[0];
		ans += s[1];
		for(int i = 3; i < s.size(); i += 2)
			ans += s[i];
		cout << ans << endl;
	}
	return 0;
}