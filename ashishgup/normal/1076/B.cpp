#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int n;

int32_t main()
{
	IOS;
	cin >> n;
	if(n % 2 == 0)
		cout << n / 2 << endl;
	else
	{
		int d = -1;
		int val = n;
		for(int i = 3; i * i <= n; i++)
		{
			while(n % i == 0)
			{
				n /= i;
				d = i;
			}
			if(d > 0)
				break;
		}
		if(d == -1)
			d = n;
		val -= d;
		cout << 1 + val / 2 << endl;
	}
	return 0;
}