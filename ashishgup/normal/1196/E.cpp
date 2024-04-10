#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int b, w;
		cin >> b >> w;
		int take = min(b, w);
		int extra = max(b, w) - take;
		int canHave = 2 * take + 1;
		if(extra > canHave)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			int x = 2, y = 2;
			for(int i = 1; i <= 2 * take; i++)
			{
				cout << x << " " << y << endl;
				y++;
				if(i % 2 == 0)
				{
					b--;
					w--;
				}
			}
			y--;
			for(int i = 2; i <= y && b > 0; i += 2)
			{
				cout << 1 << " " << i << endl;
				b--;
			}
			for(int i = 2; i <= y && b > 0; i += 2)
			{
				cout << 3 << " " << i << endl;
				b--;
			}
			for(int i = 3; i <= y && w > 0; i += 2)
			{
				cout << 1 << " " << i << endl;
				w--;
			}
			for(int i = 3; i <= y && w > 0; i += 2)
			{
				cout << 3 << " " << i << endl;
				w--;
			}
			if(b > 0)
				cout << "2 1" << endl;
			if(w > 0)
				cout << "2 " << y + 1 << endl;
		}
	}
	return 0;
}