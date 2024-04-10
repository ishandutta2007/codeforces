#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 15;

int n, m, cur = 1;
string s[N];

bool check(string str)
{
	for(int i = 0; i < n; i++)
	{
		int cnt = 0;
		for(int j = 0; j < m; j++)
		{
			cnt += (str[j] != s[i][j]);
			if(cnt > 1)
				return 0;
		}
	}
	return 1;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 0; i < n; i++)
			cin >> s[i];
		if(check(s[0]))
			cout << s[0] << endl;
		else
		{
			bool printed = 0;
			for(int i = 0; i < m; i++)
			{
				string str = s[0];
				for(char ch = 'a'; ch <= 'z'; ch++)
				{
					str[i] = ch;
					if(check(str))
					{
						cout << str << endl;
						printed = 1;
						break;
					}
				}
				if(printed)
					break;
			}
			if(!printed)
				cout << -1 << endl;
		}
	}
	return 0;
}