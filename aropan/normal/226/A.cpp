#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

long long n, m;

long long powmod(long long a, long long b, long long m)
{
	if (b == 0)
		return 1;
	long long res = powmod(a, b >> 1, m);
	(res *= res) %= m;
	return b & 1? res * a % m : res;
}

long long rec(long long n)
{
	if (n == 1)
		return 1;
	long long res = rec(n >> 1);
	res = (res + res * powmod(3, n >> 1, m)) % m;
	return n & 1? (res * 3 + 1) % m :  res;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	cin >> n >> m;
	cout << rec(n) * 2 % m << endl;
	
	return 0;
}