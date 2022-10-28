#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int32_t main()
{
	IOS;
	int a, b;
	cin >> a >> b;
	if(b > a)
	{
		cout << 0;
		return 0;
	}
	if(b == a)
	{
		cout << "infinity";
		return 0;
	}
	int n = a - b;
	int ans = 0;
	for(int i = 1; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			int x = i;
			int y = n / i;
			if(a % x == b)
				ans++;
			if(y != x && a % y == b)
				ans++;
		}
	}
	cout << ans;
	return 0;
}