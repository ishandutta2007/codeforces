#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007, i2 = 5;
typedef long long ll;
#define int ll
inline int fastpow(int a, int n)
{
	int ans = 1;
	while(n)
	{
		if(n & 1)
			ans = ans * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ans;
}
inline int inv(int x)
{
	return fastpow(x, mod - 2);
}
const int inv2 = inv(2), inv5 = inv(5);
struct Complex
{
	int r, i;
	Complex(int r = 0, int i = 0): r(r), i(i) {}
}phi1 = {inv2, mod - inv2}, phi2 = {inv2, inv2};
Complex operator + (const Complex& a, const Complex& b)
{
	return {(a.r + b.r) % mod, (a.i + b.i) % mod};
}
Complex operator - (const Complex& a, const Complex& b)
{
	return {(a.r - b.r + mod) % mod, (a.i - b.i + mod) % mod};
}
Complex operator * (const Complex& a, const Complex& b)
{
	return {(a.r * b.r + a.i * b.i * i2) % mod, (a.r * b.i + a.i * b.r) % mod};
}
Complex operator / (const Complex& a, const Complex& b)
{
	int iv = inv(((i2 * b.i * b.i - b.r * b.r) % mod + mod) % mod);
	return {((i2 * a.i * b.i - a.r * b.r) % mod + mod) * iv % mod, ((a.r * b.i - a.i * b.r) % mod + mod) * iv % mod};
}
Complex operator - (const Complex& a, const int& b)
{
	return {(a.r - b + mod) % mod, a.i};
}
Complex operator * (const Complex& a, const int& b)
{
	return {a.r * b % mod, a.i * b % mod};
}
Complex fastpow(Complex a, int n)
{
	Complex ans = {1, 0};
	while(n)
	{
		if(n & 1)
			ans = ans * a;
		a = a * a;
		n >>= 1;
	}
	return ans;
}
int p[210], pl[210], pr[210];
int C[210][210], stl[210][210];
inline void Init(int n)
{
	C[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		C[i][0] = 1;
		for(int j = 1; j <= n; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	stl[1][1] = 1;
	for(int i = 2; i <= n; i++)
		for(int j = 1; j < i; j++)
		{
			stl[i][j] = (stl[i][j] + stl[i - 1][j] * (mod + 1 - i)) % mod;
			stl[i][j + 1] = (stl[i][j + 1] + stl[i - 1][j]) % mod;
		}
}
inline int p1(int x)
{
	return (x & 1) ? mod - 1 : 1;
}
inline Complex GetSum(Complex& a, int n)
{
	if(a.r == 1 && a.i == 0)
		return {(n + 1) % mod, 0};
	return (fastpow(a, n + 1) - 1) / (a - 1);
}
inline Complex GetOne(int n, int k, int j)
{
	int co = C[k][j] * p1(j) % mod;
	Complex bs = fastpow(phi1, j) * fastpow(phi2, k - j);
	return GetSum(bs, n) * co;
}
inline void GetPows(int n, int *p, int k)
{
	Complex res;
	for(int j = 0; j <= k; j++)
		res = res + GetOne(n, k, j);
	Complex div = {0, inv(5)};
	res = res * fastpow(div, k);
	p[k] = res.r;
}
signed main()
{
	int k, l, r;
	scanf("%lld %lld %lld", &k, &l, &r);
	l += 2, r += 2;
	Init(k);
	for(int i = 1; i <= k; i++)
	{
		GetPows(r, pr, i);
		GetPows(l - 1, pl, i);
		p[i] = (pr[i] - pl[i] + mod) % mod;
	}
	int ans = 0;
	for(int i = 1; i <= k; i++)
		ans = (ans + p[i] * stl[k][i]) % mod;
	int fac = 1;
	for(int i = 1; i <= k; i++)
		fac = fac * i % mod;
	printf("%lld\n", ans * inv(fac) % mod);
	return 0;
}