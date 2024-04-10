#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

string s;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> s;
		int n = s.size();
		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '0')
				continue;
			int val = 0;
			int zeroes = 0;
			for(int j = i - 1; j >= 0; j--)
			{
				if(s[j] == '0')
					zeroes++;
				else
					break;
			}
			for(int j = i; j < n; j++)
			{
				val = val * 2 + (s[j] - '0');
				if((j - i + 1 + zeroes) >= val)
					ans++;
				if(val > n)
					break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}