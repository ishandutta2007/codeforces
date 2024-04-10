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
		if(n % 2)
		{
			int flag = 0;
			for(int i = 0; i < n; i += 2)
				if((s[i] - '0') % 2)
					flag = 1;
			if(flag == 0)
				cout << 2 << endl;
			else
				cout << 1 << endl;
		}
		else
		{
			int flag = 1;
			for(int i = 1; i < n; i += 2)
				if((s[i] - '0') % 2 == 0)
					flag = 0;
			if(flag == 0)
				cout << 2 << endl;
			else
				cout << 1 << endl;
		}
	}
	return 0;
}