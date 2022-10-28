#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	string s;
	cin >> s;
	int n = s.size();
	string ans = "";
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] == '0')
		{
			ans += s.substr(i + 1);
			break;
		}
		else
			ans += s[i];
	}
	if(ans.size() == n)
		ans.pop_back();
	cout << ans;
	return 0;
}