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
		int c00, c01, c11;
		cin >> c00 >> c01 >> c11;
		if(c01 > 0)
		{
			string ans = "1";
			for(int i = 1; i <= c11; i++)
				ans += '1';
			ans += '0';
			c01--;
			for(int i = 1; i <= c00; i++)
				ans += '0';
			for(int i = 1; i <= c01; i++)
				ans += (char)(i % 2 + '0');
			cout << ans << endl;
		}
		else 
		{
			if(c00 > 0)
				for(int i = 1; i <= c00 + 1; i++)
					cout << 0;
			else
				for(int i = 1; i <= c11 + 1; i++)
					cout << 1;
			cout << endl;
		}
	}
	return 0;
}