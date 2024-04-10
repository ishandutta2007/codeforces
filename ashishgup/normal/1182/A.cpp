#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int32_t main()
{
	IOS;
	int n;
	cin >> n;
	int ans = 1;
	if(n % 2)
		ans = 0;
	else
	{
		for(int i = 1; i <= n / 2; i++)
			ans *= 2;
	}
	cout << ans;
	return 0;
}