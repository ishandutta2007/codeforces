#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;

int n, k;
string s, ans = "";

int32_t main()
{
	IOS;
	cin >> n >> k;
	cin >> s;
	int open = k / 2, close = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '(' && open)
		{
			open--, close++;
			ans += s[i];
		}
		else if(s[i] == ')' && close)
			ans += s[i], close--;
	}
	cout << ans;
	return 0;
}