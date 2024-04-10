#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n;
string s;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cin >> s;
		int mn = n / 2;
		int flag = 0;
		for(int i = mn; i < n; i++)
		{
			if(s[i] == '0')
			{
				cout << 1 << " " << i + 1 << " ";
				cout << 1 << " " << i << endl;
				flag = 1;
				break;
			}
		}
		if(flag)
			continue;
		for(int i = mn - 1; i >= 0; i--)
		{
			if(s[i] == '0')
			{
				cout << i + 1 << " " << n << " ";
				cout << i + 2 << " " << n << endl;
				flag = 1;
				break;
			}
		}
		if(flag)
			continue;
		cout << 1 << " " << mn << " ";
		cout << 2 << " " << mn + 1 << endl;
	}
	return 0;
}