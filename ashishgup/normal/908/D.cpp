#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N = 1e3 + 5;
const int MOD = 1e9 + 7;
 
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
 
int k, pa, pb, x, y, denA;
int cache[N][N];
 
int dp(int a, int k)
{
	if(k <= 0)
		return 0;
	int &ans = cache[a][k];
	if(ans != -1)
		return ans;
	if(a >= k)
	{
		int val = a + pa * denA;
		val %= MOD;
		val *= denA;
		val %= MOD;
		val *= pb;
		val %= MOD;
		return ans = val;
	}
	int valA = pa * dp(a + 1, k);
	int valB = pb * (a + dp(a, k - a));
	ans = valA + valB;
	ans %= MOD;
	return ans;
}
 
int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> k >> x >> y;
	pa = x * modinv(x + y);
	pa %= MOD;
	pb = y * modinv(x + y);
	pb %= MOD;
	denA = modinv(1 - pa + MOD);
	int ans = dp(1, k);
	cout << ans;
	return 0;
}