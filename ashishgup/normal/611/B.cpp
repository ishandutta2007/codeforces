#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e5 + 5;
 
int a, b;
 
int f(int x)
{
	int ans = 0;
	for(int len = 2; len <= 62; len++)
	{
		int mask = (1LL << len) - 1;
		for(int j = 0; j + 1 < len; j++)
		{
			int y = mask ^ (1LL << j);
			if(y <= x)
				ans++;
		}
	}
	return ans;
}
 
int32_t main()
{
	IOS;
	cin >> a >> b;
	int ans = f(b) - f(a - 1);
	cout << ans;
	return 0;
}