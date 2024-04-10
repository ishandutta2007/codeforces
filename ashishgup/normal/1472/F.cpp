//Trying to screencast

#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int n, m;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		map<int, int> mask;
		for(int i = 1; i <= m; i++)
		{
			int x, y;
			cin >> x >> y;
			mask[y] |= (1 << (x - 1));
		}
		int cur = 0;
		int prevY = 0;
		//00 = valid
		//10 => 01
		//01 => 10
		bool flag = 1;
		for(auto &it:mask)
		{
			if(cur == 0)
			{
				cur |= it.second;
				if(it.second > 0 && it.second < 3)
					prevY = it.first; 
			}
			else
			{
				if(it.second == 3)
				{
					flag = 0;
					break;
				}
				if(cur == it.second)
				{
					if((it.first - prevY) % 2 == 0)
					{
						flag = 0;
						break;
					}
					cur = 0;
				}
				else
				{
					if((it.first - prevY) % 2 == 1)
					{
						flag = 0;
						break;
					}
					cur = 0;
				}
			}
			if(cur == 3)
				cur = 0;
		}
		if(cur)
			flag = 0;
		if(flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}