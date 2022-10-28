#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int c1, c2, c3;
		int a1, a2, a3, a4, a5;
		cin >> c1 >> c2 >> c3;
		cin >> a1 >> a2 >> a3 >> a4 >> a5;
		c1 -= a1;
		c2 -= a2;
		c3 -= a3;
		if(c1 < 0 || c2 < 0 || c3 < 0)
		{
			cout << "No" << endl;
			continue;
		}
		int take = min(c1, a4);
		a4 -= take;
		int take2 = min(c2, a5);
		a5 -= take2;
		if(c3 >= a4 + a5)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}