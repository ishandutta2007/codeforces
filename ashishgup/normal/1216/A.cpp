#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n;
string s;

int32_t main()
{
	IOS;
	cin >> n >> s;
	int ans = 0;
	for(int i = 1; i < n; i += 2)
	{
		if(s[i] == s[i - 1])
		{
			ans++;
			if(s[i] == 'a')
				s[i] = 'b';
			else
				s[i] = 'a';
		}
	}
	cout << ans << endl;
	cout << s;
	return 0;
}