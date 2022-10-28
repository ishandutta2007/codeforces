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
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		bool printed = 0;
		for(int i = 0; i <= k; i++)
		{
			int x = i, y = k - i;
			int lec = x * c;
			int other = y * d;
			if(lec >= a && other >= b)
			{
				printed = 1;
				cout << i << " " << k - i << endl;
				break;
			}
		}
		if(!printed)
			cout << -1 << endl;
	}
	return 0;
}