#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 105;

int n;
string s;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> s;
		int idx = 0;
		for(int i = 1; i < n; i++)
		{
			if(s[i] == '?')
			{
				if(s[i - 1] == 'R')
					s[i] = 'B';
				else if(s[i - 1] == 'B')
					s[i] = 'R';
			}
		}
		for(int i = n - 2; i >= 0; i--)
		{
			if(s[i] == '?')
			{
				if(s[i + 1] == 'R')
					s[i] = 'B';
				else if(s[i + 1] == 'B')
					s[i] = 'R';
			}
		}
		if(s[0] == '?')
		{
			for(int i = 0; i < n; i++)
			{
				if(i % 2)
					s[i] = 'B';
				else
					s[i] = 'R';
			}
		}
		cout << s << endl;
	}
	return 0;
}