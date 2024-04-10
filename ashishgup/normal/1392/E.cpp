#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define endl "\n"
#define int long long

const int N = 50;

int n, q;
int a[N][N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int diag = i + j - 2;
			int val = (1LL << (diag + (i % 2)));
			a[i][j] = val;
			cout << val << " ";
		}
		cout << endl;
	}
	cin >> q;
	while(q--)
	{
		vector<pair<int, int> > path;
		int x = 1, y = 1;
		int val;
		cin >> val;
		while(true)
		{
			val -= a[x][y];
			path.push_back({x, y});
			if(x == n && y == n)
				break;
			if(x < n && y < n)
			{
				if(a[x + 1][y] < a[x][y + 1])
				{
					if(a[x + 1][y] & val)
						x++;
					else
						y++;
				}
				else
				{
					if(a[x][y + 1] & val)
						y++;
					else
						x++;
				}
			}
			else if(x == n)
				y++;
			else
				x++;
		}
		for(auto &it:path)
			cout << it.first << " " << it.second << endl;
	}
	return 0;
}