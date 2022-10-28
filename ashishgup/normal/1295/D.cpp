#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;

int totient(int x)
{
	int ans = x;
	for(int i = 2; i * i <= x; i++)
	{
		if(x % i)
			continue;
		while(x % i == 0)
			x /= i;
		ans -= ans / i;
	}
	if(x > 1)
		ans -= ans / x;
	return ans;
}

int32_t main()
{
	IOS;
	int t;
	cin >> t;
	while(t--)
	{
		int a, m;
		cin >> a >> m;
		int g = __gcd(a, m);
		m /= g;
		int ans = 0;
		ans += totient(m);
		cout << ans << endl;
	}
	return 0;
}