#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e5 + 5;
const int MOD = 998244353;

int pow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

int modinv(int k)
{
	return pow(k, MOD - 2, MOD);
}

int n, m, l, r;

int32_t main()
{
	IOS;
	cin >> n >> m >> l >> r;
	int tot = n * m;
	int k = r - l + 1;
	if(tot % 2)
		cout << pow(k, tot, MOD);
	else
	{
		int ans = pow(k, tot, MOD) + (k % 2);
		ans *= modinv(2);
		ans %= MOD;
		cout << ans;
	}
	return 0;
}