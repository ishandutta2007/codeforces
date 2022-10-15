#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

template <typename T> T sqr(T x) { return x * x; }
template <typename T> T abs(T x) { return x < 0? -x : x; }
template <typename T> T gcd(T a, T b) { return b == 0? a : gcd(b, a % b); }

long long a, b;
int k, m;

int run(int a, int b)
{
	if (b < a)
		b += m;
	
	int d[b + 1];
	memset(d, 0, sizeof(d));
	queue <int> q;
	d[b] = 1;
	q.push(b);
	while (q.size())
	{
		int x = q.front();
		int l = d[x];
		q.pop();
		if (a < x && d[x - 1] == 0)
		{
			q.push(x - 1);
			d[x - 1] = l + 1;
		}
		for (int j = 2; j <= k; j++)
		{
			int v = x % j;
			x -= v;
			if (a <= x && d[x] == 0)
			{
				d[x] = l + 1;
				q.push(x);
			}
			x += v;
		}
	}
	return d[a] - 1;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	cin >> a >> b >> k;
	
	m = 1;
	for (int i = 1; i <= k; i++)
		m = m * i / gcd(m, i);
	if (a - b < m)
	{
		cout << run(b % m, a % m) << endl;
		return 0;
	}
	
	long long x = a / m - b / m - 1;
	cout << run(0, m) * x + run(b % m, m) + run(0, a % m) << endl;
	return 0;
}