#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;
int a[N];

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 1; i <= n; i++)
			cin >> a[i];
		int mx = -1e9;
		int diff = 0;
		for(int i = 1; i <= n; i++)
		{
			diff = max(diff, mx - a[i]);
			mx = max(mx, a[i]);
		}
		if(diff == 0)
			cout << 0 << endl;
		else
		{
			for(int i = 0;;i++)
			{
				diff -= (1LL << i);
				if(diff <= 0)
				{
					cout << i + 1 << endl;
					break;
				}
			}
		}
	}
	return 0;
}