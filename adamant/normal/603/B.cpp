#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 1e9 + 7;

int bpow(int x, int n, int m)
{
	if(n == 0)
		return 1;
	int t = bpow(x, n / 2, m);
	if(n % 2 == 1)
		return x * t % m * t % m;
	else
		return t * t % m;
}

signed main()
{
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int p, k;
	cin >> p >> k;
	if(k == 1)
	{
		cout << bpow(p, p, mod) << "\n";
		return 0;
	}
	if(k == 0)
	{
		cout << bpow(p, p - 1, mod) << "\n";
		return 0;
	}
	for(int i = 1; i < p; i++)
	{
		if(bpow(k, i, p) == 1)
		{
			cout << bpow(p, (p - 1) / i, mod) << "\n";
			return 0;
		}
	}
	/*
	 * f(k*x) = k*f(x)
	 * f(x) = n1 * x^1 + n2 * x^2 + ...
	 * f(k*x) = k^t * x^t * n
	 * k * f(x) = k * x^t * n
	 * n * 
	 * */
    return 0;
}