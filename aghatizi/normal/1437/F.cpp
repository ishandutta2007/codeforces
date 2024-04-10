#include<bits/stdc++.h>
using namespace::std;

#define ll long long
#define pb push_back

const int maxn = 5e3 + 20;
const int mod = 998244353;

int t[maxn] , a[maxn] , dp[maxn];

int fac[maxn] , caf[maxn];

void mkay(int &a)
{
	if(a >= mod)
		a -= mod;
	else if(a < 0)
		a += mod;
}

int bpw(int a , int b)
{
	if(!b)
		return 1;
	int x = bpw(a , b / 2);

	x = 1LL * x * x % mod;
	if(b & 1)
		x = 1LL * x * a % mod;

	return x;
}

int c(int s , int r)
{
	if(r > s || r < 0)
		return 0;

	return 1LL * fac[s] * caf[r] % mod * caf[s - r] % mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	fac[0] = 1;
	for(int i = 1; i < maxn; i++)
		fac[i] = 1LL * fac[i - 1] * i % mod;

	caf[maxn - 1] = bpw(fac[maxn - 1] , mod - 2);
	for(int i = maxn - 1; i > 0; i--)
		caf[i - 1] = 1LL * caf[i] * i % mod;

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a , a + n + 1);

	if(a[n] < a[n - 1] * 2)
		return cout << 0 << endl , 0;

	for(int i = 0; i <= n; i++)
		for(int j = 0; j < i; j++)
			t[i] += a[j] * 2 <= a[i];

	dp[n] = 1;
	for(int i = n; i >= 0; i--)
		for(int j = i - 1; j >= 0; j--)
			if(a[j] * 2 <= a[i])
				mkay(dp[j] += 1LL * dp[i] * c(t[n] - t[j] - 1 , t[i] - t[j] - 1) % mod * fac[t[i] - t[j] - 1] % mod);

	cout << dp[0] << endl;
}