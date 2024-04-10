#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

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
		string str = s;
		sort(str.begin(), str.end());
		int ans = 0;
		for(int i = 0; i < n; i++)
			ans += (s[i] != str[i]);
		cout << ans << endl;
	}
	return 0;
}