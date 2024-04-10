#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const long long M = 1000000007;
const int N = 200005;

long long ast(long long x, long long n)
{
	if (n == 0)
		return 1;
	if (n % 2 == 0)
	{
		long long y = ast(x, n / 2);
		return (y * y) % M;
	}
	else
	{
		long long y = ast(x, n - 1);
		return (x * y) % M;
	}
}

int n;
long long q[N];
long long p[N], s[N];

__int32 main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		q[x]++;
	}

	long long a = 1;
	p[0] = 1;
	for (int x = 1; x < N; ++x)
	{
		p[x] = (p[x - 1] * (q[x] + 1)) % (M - 1);
	}
	s[N - 1] = 1;
	for (int x = N - 2; x >= 0; --x)
	{
		s[x] = (s[x + 1] * (q[x] + 1)) % (M - 1);
	}

	long long ans = 1;
	for (int x = 2; x < N - 1; ++x)
	{
		long long aa = (p[x - 1] * s[x + 1]) % (M - 1);
		ans = (ans * ast(ast(x, q[x] * (q[x] + 1) / 2), aa)) % M;
	}
	cout << ans << endl;
	return 0;
}