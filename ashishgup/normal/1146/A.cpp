#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	string s;
	cin >> s;
	map<char, int> m;
	for(auto &it:s)
		m[it]++;
	int ans = s.size();
	ans = min(ans, m['a'] * 2 - 1);
	cout << ans;
	return 0;
}