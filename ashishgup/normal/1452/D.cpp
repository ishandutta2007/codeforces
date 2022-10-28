#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 2e5 + 5;
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
	return pow(k, MOD-2, MOD);
}

int n;
int fib[N];

int32_t main()
{
	IOS;
	cin >> n;
	fib[1] = 1, fib[2] = 1;
	for(int i = 3; i <= n; i++)
		fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
	int ans = fib[n];
	ans *= pow(modinv(2), n, MOD);
	ans %= MOD;
	cout << ans;
	return 0;
}