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
		int n;
		cin >> n;
		if(n % 2)
		{
			cout << 7;
			n -= 3;
		}
		else
		{
			cout << 1;
			n -= 2;
		}
		while(n > 0)
		{
			cout << 1;
			n -= 2;
		}
		cout << endl;
	}
	return 0;
}