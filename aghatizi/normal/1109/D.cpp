#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e6 + 20;
const int mod = 1e9 + 7;

int fac[maxn] , caf[maxn];

int bpw(int a , int b)
{
	if(!b)
		return 1;

	int x = bpw(a , b / 2);
	x = 1LL * x * x % mod;
	if(b&1)
		x = 1LL * x * a % mod;

	return x;
}

int c(int r , int s)
{
	if(r > s || r < 0)
		return 0;

	return (1LL * fac[s] * caf[r] % mod) * caf[s - r] % mod;
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

	int n , m;
	cin >> n >> m;

	int res = 0;
	for(int i = 1; i < n; i++)
	{
		int ef = c(i - 1 , m - 1);
		int tmp = 1LL * ef * c(i - 1 , n - 2) % mod;
		tmp = 1LL * tmp * fac[i - 1] % mod;
		if(i + 1 < n)
		{
			tmp = 1LL * tmp * bpw(n , n - i - 2) % mod;
			tmp = 1LL * tmp * (i + 1) % mod;
		}

		tmp = 1LL * tmp * bpw(m , n - i - 1) % mod;
		res = (res + tmp) % mod;
	}

	cout << res << endl;
}