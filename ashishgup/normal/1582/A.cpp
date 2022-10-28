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
		int a, b, c;
		cin >> a >> b >> c;
		if(a >= 2)
			cout << (a + b * 2 + c * 3) % 2 << endl;
		else if(a == 1)
		{
			if(b == 0)
				cout << abs((c % 2) * 3 - 1) << endl;
			else if(c == 0)
				cout << 1 << endl;
			else
				cout << (a + b * 2 + c * 3) % 2 << endl;
		}
		else
		{
			if(b == 0)
				cout << (c % 2) * 3 << endl;
			else if(c == 0)
				cout << (b % 2) * 2 << endl;
			else
				cout << (a + b * 2 + c * 3) % 2 << endl;
		}

	}
	return 0;
}