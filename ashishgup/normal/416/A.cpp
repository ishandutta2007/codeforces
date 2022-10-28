#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int32_t main()
{
	IOS;
	int n;
	cin >> n;
	string s;
	int mn = -2e9, mx = 2e9;
	for(int i = 1; i <= n; i++)
	{
		string x;
		int y;
		char ch;
		stringstream ss(s);
		cin >> x >> y >> ch;
		if(x.size() == 2)
		{
			if(x[0] == '>')
			{
				if(ch == 'Y')
					mn = max(mn, y);
				else
					mx = min(mx, y - 1);
			}
			else
			{	
				if(ch == 'Y')
					mx = min(mx, y);
				else
					mn = max(mn, y + 1);
			}
		}
		else
		{
			if(x[0] == '>')
			{
				if(ch == 'Y')
					mn = max(mn, y + 1);
				else
					mx = min(mx, y);
			}
			else
			{
				if(ch == 'Y')
					mx = min(mx, y - 1);
				else
					mn = max(mn, y);
			}
		}
	}
	if(mn <= mx)
		cout << mn;
	else
		cout << "Impossible";
	return 0;
}