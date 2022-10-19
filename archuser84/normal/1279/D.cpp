#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <algorithm>
#include <vector>
#define Loop(x, a, b) for(int x = a; x < b; ++x)
#define LoopR(x, a, b) for(int x = b - 1; x >= a; --x)
#define ll long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;

ll modDivide(ll x, ll y, ll mod)
{
	if (x % y == 0)
		return x / y;
	return ((modDivide(y - x % y, mod % y, y) * mod + x) / y) % mod;
}

class frac
{
private:
	ll N, D;
	ll mod;
public:
	frac() {}
	frac(ll m)
	{
		mod = m;
		N = 0;
		D = 1;
	}
	frac(ll n, ll d, ll m)
	{
		mod = m;
		N = n % mod;
		D = d % mod;
	}
	frac operator*(frac x)
	{
		if (this->mod == x.mod)
			return frac(N * x.N, D * x.D, mod);
		else
			return frac(0, 1, mod);
	}
	frac operator+(frac x)
	{
		if (this->mod == x.mod)
			return frac(N * x.D + x.N * D, D * x.D, mod);
		else
			return frac(0, 1, mod);
	}
	frac operator*(ll x)
	{
		return frac(N * x, D, mod);
	}
	frac operator/(ll x)
	{
		return frac(N, D * x, mod);
	}
	ll getValue()
	{
		return modDivide(N, D, mod);
	}
};

int main()
{
	ll n;
	frac f[1000001];
	int count[1000001] = { 0 };
	Loop(i, 0, 1000001)
		f[i] = frac(Mod2);
	
	cin >> n;
	Loop(i, 0, n)
	{
		int x;
		cin >> x;
		Loop(j, 0, x)
		{
			int k;
			cin >> k;
			count[k]++;
			f[k] = f[k] + frac(1, x, Mod2);
		}
	}

	frac ans(Mod2);
	Loop(i, 0, 1000001)
	{
		ans = ans + f[i] * count[i];
	}
	ans = ans / n;
	ans = ans / n;
	
	cout << ans.getValue();
}