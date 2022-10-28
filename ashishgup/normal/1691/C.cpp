#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n, k;
string s;

int get(string &str)
{
	int ans = 0;
	for(int i = 0; i + 1 < str.size(); i++)
		ans += (str[i] - '0') * 10 + (str[i + 1] - '0');
	return ans;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		cin >> s;
		int ans = get(s);
		int ct1 = 0, f = -1, l = -1;
		for(int i = 0; i < n; i++)
		{
			ct1 += (s[i] == '1');
			if(s[i] == '1')
			{
				if(f == -1)
					f = i;
				l = i;
			}
		}
		l = n - 1 - l;
		if(ct1 == 0)
			cout << ans << endl;
		else if(ct1 == 1)
		{
			if(l >= 1 && k >= l)
				ans -= 10 - (f == 0);
			else if(l >= 1 && f >= 1 && k >= f)
				ans -= 1;
			cout << ans << endl;
		}
		else
		{
			if(l >= 1 && k >= l)
				ans -= 10, k -= l;
			if(f >= 1 && k >= f)
				ans -= 1;
			cout << ans << endl;
		}
	}
	return 0;
}