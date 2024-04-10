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
		int mx = 1;
		for(int i = 1; i * i <= n; i++)
		{
			if(n % i == 0)
			{
				if(i < n)
					mx = max(mx, i);
				if(n / i < n)
					mx = max(mx, n / i);
			}
		}
		int rem = n / mx;
		int a = mx * (rem - 1);;
		int b = mx * 1;
		cout << a << " " << b << endl;
	}
	return 0;
}