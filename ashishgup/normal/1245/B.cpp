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
		int n, r, p, s;
		cin >> n >> r >> p >> s;
		string str;
		cin >> str;
		vector<char> ans(n, '?');
		int answer = 0;
		for(int i = 0; i < n; i++)		
		{
			if(str[i] == 'R')
			{
				if(p > 0)
				{
					answer++;
					p--;
					ans[i] = 'P';
				}
			}
			if(str[i] == 'P')
			{
				if(s > 0)
				{
					answer++;
					s--;
					ans[i] = 'S';
				}
			}
			if(str[i] == 'S')
			{
				if(r > 0)
				{
					answer++;
					r--;
					ans[i] = 'R';
				}
			}
		}
		if(answer < (n + 1) / 2)
		{
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for(int i = 0; i < n; i++)
		{
			if(ans[i] == '?')
			{
				if(r > 0)
				{
					r--;
					ans[i] = 'R';
				}
				else if(p > 0)
				{
					p--;
					ans[i] = 'P';
				}
				else
				{
					s--;
					ans[i] = 'S';
				}
			}
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}