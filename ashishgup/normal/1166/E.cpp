#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e4 + 5;

bitset<N> bit[51];

int32_t main()
{
	IOS;
	int m, n;
	cin >> m >> n;
	for(int i = 1; i <= m; i++)
	{
		int k;
		cin >> k;
		for(int j = 1; j <= k; j++)
		{
			int x;
			cin >> x;
			bit[i][x] = 1;
		}
	}
	for(int i = 1; i <= m; i++)
	{
		for(int j = i + 1; j <= m; j++)
		{
			if(!((bit[i] & bit[j]).any()))
			{
				cout << "impossible";
				exit(0);
			}
		}
	}
	cout << "possible";
	return 0;
}