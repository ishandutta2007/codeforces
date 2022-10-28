#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int32_t main()
{
	IOS;
	int n;
	cin >> n;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			cout << i << n / i;
			return 0;
		}
	}
	return 0;
}