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
		int n, k;
		cin >> n >> k;
		int sum1 = k;
		if((n - k) % 2 == 0 && n >= k)
		{
			cout << "YES" << endl;
			for(int i = 1; i <= k - 1; i++)
				cout << 1 << " ";
			cout << n - k + 1 << endl;
		}
		else if((n - 2 * k) % 2 == 0 && n >= 2 * k)
		{
			cout << "YES" << endl;
			for(int i = 1; i <= k - 1; i++)
				cout << 2 << " ";
			cout << n - 2*k + 2 << endl;
		}
		else
			cout << "NO" << endl;
	}
	return 0;
}