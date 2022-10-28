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
		int a, b;
		cin >> a >> b;
		if(a == b)
			cout << 0 << endl;
		else if(a > b)
		{
			if((a - b) % 2)
				cout << 2 << endl;
			else
				cout << 1 << endl;
		}
		else
		{
			if((b - a) % 2)
				cout << 1 << endl;
			else
				cout << 2 << endl;
		}
	}
	return 0;
}