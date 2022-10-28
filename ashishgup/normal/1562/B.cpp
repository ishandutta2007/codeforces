#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;

int n;
string s;

bool check(int x)
{
	for(int i = 2; i * i <= x; i++)
		if(x % i == 0)
			return 1;
	return 0;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cin >> s;
		int ans = 0;
		map<int, int> m;
		for(auto &it:s)
			m[it - '0']++;
		set<int> st = {1, 4, 6, 8, 9};
		if(m[1] || m[4] || m[6] || m[8] || m[9])
		{
			cout << 1 << endl;
			for(auto &it:st)
			{
				if(m[it])
				{
					cout << it << endl;
					break;
				}
			}
			continue;
		}
		else
		{
			bool flag = 0;
			for(int i = 0; i < n && !flag; i++)
			{
				for(int j = i + 1; j < n && !flag; j++)
				{
					int val = (s[i] - '0') * 10 + (s[j] - '0');
					if(check(val))
					{
						cout << 2 << endl;
						cout << val << endl;
						flag = 1;
						break;
					}
				}
			}
			for(int i = 0; i < n && !flag; i++)
			{
				for(int j = i + 1; j < n && !flag; j++)
				{
					for(int k = j + 1; k < n && !flag; k++)
					{
						int val = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
						if(check(val))
						{
							cout << 3 << endl;
							cout << val << endl;
							flag = 1;
							break;
						}
					}
				}
			}
		}
	}
	return 0;
}