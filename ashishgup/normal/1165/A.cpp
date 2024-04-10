#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	int ans = 0;
	reverse(s.begin(), s.end());
	for(int i = 0; i < x; i++)
	{
		if(i == y)
			ans += (s[i] != '1');
		else
			ans += (s[i] != '0');	
	}
	cout << ans;
	return 0;
}