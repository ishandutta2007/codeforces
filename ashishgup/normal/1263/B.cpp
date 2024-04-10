#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 25;

int n;
bool vis[N];
string s[N], ans[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		memset(vis, 0, sizeof(vis));
		cin >> n;
		set<string> taken;
		for(int i = 1; i <= n; i++)
		{
			cin >> s[i];
			if(taken.find(s[i]) == taken.end())
			{
				ans[i] = s[i];
				vis[i] = 1;
				taken.insert(s[i]);
			}
		}
		int answer = 0;
		for(int i = 1; i <= n; i++)
		{
			if(vis[i])
				continue;
			answer++;
			for(int j = 0; j < 4 && !vis[i]; j++)
			{
				for(char ch = '0'; ch <= '9'; ch++)
				{
					string str = s[i];
					str[j] = ch;
					if(taken.find(str) == taken.end())
					{		
						vis[i] = 1;
						taken.insert(str);
						ans[i] = str;
						break;
					}
				}
			}
		}
		cout << answer << endl;
		for(int i = 1; i <= n; i++)
			cout << ans[i] << endl;
	}	
	return 0;
}